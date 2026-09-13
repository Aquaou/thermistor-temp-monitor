#include <LiquidCrystal.h>

LiquidCrystal lcd(4,5,10,11,12,13);

// Steinhart Coefficients (derived using Mathcad):
const float A = 0.001283;
const float B = 0.0002079;
const float C = 0.0000002005;

// Circuit Parameters
const float V_IN = 5.0; // 5V supplied from Arduino
const float R_FIXED = 10000; // 10000 ohm resister in series with thermistor
const int THERMISTOR_PIN = A0; // analog pin for the thermistor

// Setup begins serial monitor and small delay for ADC
void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Temperature Monitor");
  delay(1000);
}

// Main loop
void loop() {

  // Reads the raw ADC value from our thermistor pin
  int adc_raw = analogRead(THERMISTOR_PIN);

  /* Gets our V_OUT value by taking the raw ADC value and multiplying by
  the V_IN value divided by the step count.*/ 
  float V_OUT = adc_raw * (V_IN / 1023);

  // Calls our calculate temperature function and passes in: V_IN, V_OUT, and R_FIXED
  float temp_celsius = calculate_temperature(V_IN, V_OUT, R_FIXED);

  Serial.print("Voltage out: ");
  Serial.print(V_OUT);
  Serial.print(" V  |  Temperature: ");
  Serial.print(temp_celsius);
  Serial.println(" C");

  lcd.setCursor(0, 0);
  lcd.print(temp_celsius);
  lcd.print(" C");

  delay(1000); // Read once per second
}

// Function to calculate the temperature based on ohms law
float calculate_temperature(float V_IN, float V_OUT, float R_FIXED) {

  // Calculate the thermistor resistance:
  float R_TH = R_FIXED * ((V_IN/V_OUT) - 1.0);

  // Pre-calculated functions for the steinhart eq
  float log_r = log(R_TH);
  float log_r_cubed = log_r * log_r * log_r;

  // Gets the temperature and kelvin from our resistance
  float t_kelvin = 1/(A+B*(log_r)+C*(log_r_cubed));

  // Converts the kelvin temperature into celsius
  float t_celsius = t_kelvin - 273.15;

  return t_celsius;
}
