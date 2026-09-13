# Thermistor Temperature Monitor

Arduino sketch that reads a thermistor on analog pin A0, calculates temperature in Celsius using the Steinhart-Hart equation, and displays the result on a 16 x 2 LCD and the Serial Monitor once per second.

## Code

[View the Arduino sketch](Thermistor_Temp_Monitor/Thermistor_Temp_Monitor.ino)

## Configuration

- Supply voltage: 5 V
- Fixed series resistor: 10 kΩ
- Thermistor input: A0
- LCD pins (RS, Enable, D4, D5, D6, D7): 4, 5, 10, 11, 12, 13
- Serial Monitor baud rate: 9600
- LCD library: LiquidCrystal

The sketch contains thermistor coefficients derived using Mathcad. These coefficients and the voltage-divider calculation must match the connected hardware.

## Open in Arduino IDE

Open `Thermistor_Temp_Monitor/Thermistor_Temp_Monitor.ino`, select the appropriate board and port, and upload. Open Serial Monitor at 9600 baud to see voltage and temperature readings.

The original sketch is included unchanged.
