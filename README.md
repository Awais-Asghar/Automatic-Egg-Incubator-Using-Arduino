# Egg Incubator Project

## Overview

This project is an egg incubator system built using an Arduino microcontroller. The incubator is designed to maintain optimal conditions for hatching eggs, including temperature and humidity control, and periodic egg turning.

## Features

- **Temperature Control**: Uses a DHT11 sensor for temperature measurement and a relay to control a heating element.
- **Humidity Monitoring**: Uses a DHT11 sensor for humidity measurement.
- **Egg Turning**: Controls a stepper motor to turn the eggs at set intervals.
- **User Interface**: Displays system status on an LCD screen.
- **Alerts**: Buzzer alerts for critical conditions.

## Components

- Arduino
- DHT11 Temperature and Humidity Sensor
- Stepper Motor and Driver
- Liquid Crystal Display (LCD)
- OneWire Temperature Sensors
- Relay Module
- Buzzer
- Buttons for user input

## Pin Configuration

### Stepper Motor Control

- `dirPin` (Pin 3): Sets the direction of the stepper motor (HIGH for clockwise, LOW for counterclockwise).
- `stepPin` (Pin 4): Sends pulses to move the stepper motor.
- `DriverEnable_Pin` (Pin 5): Enables the stepper motor driver (LOW to enable, HIGH to disable).

### Sensors

- `DHTPIN` (Pin 13): Pin connected to the DHT11 sensor for temperature and humidity.
- `ONE_WIRE_BUS` (Pin 2): Pin connected to the OneWire bus for additional temperature sensors.

### LCD Display

- `rs` (Pin 12): Register select pin for the LCD.
- `en` (Pin 11): Enable pin for the LCD.
- `d4` (Pin 10): Data pin 4 for the LCD.
- `d5` (Pin 9): Data pin 5 for the LCD.
- `d6` (Pin 8): Data pin 6 for the LCD.
- `d7` (Pin 6): Data pin 7 for the LCD.

### Other

- `buzzerPin` (Analog Pin A0): Pin connected to the buzzer for alert sounds.
- `relayPin` (Analog Pin A1): Pin connected to the relay module to control the heating element.
- `buttonPin` (Analog Pin A2): Pin connected to a button for user input.
- `hatchPin` (Analog Pin A3): Pin connected to the hatching mechanism.

## Libraries Used

- `Stepper.h`: Library to control the stepper motor.
- `DHT.h`: Library to interface with the DHT11 temperature and humidity sensor.
- `LiquidCrystal.h`: Library to control the LCD display.
- `OneWire.h`: Library for the OneWire protocol.
- `DallasTemperature.h`: Library to get temperature readings from OneWire sensors.

## Code Explanation

### Pin Definitions and Library Inclusions

```cpp
#include <Stepper.h>
#include "DHT.h"
#include <LiquidCrystal.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// Pin definitions
const int dirPin = 3;
const int stepPin = 4;
const int DriverEnable_Pin = 5;
const int DelayJumper_Pin = 7;
const int buzzerPin = A0;
const int relayPin = A1;
const int buttonPin = A2;
const int hatchPin = A3;
const int rs = 12, en = 11, d4 = 10, d5 = 9, d6 = 8, d7 = 6;

#define ONE_WIRE_BUS 2
#define DHTPIN 13
#define DHTTYPE DHT11
```

### Initializing Sensors and LCD

```cpp
DHT dht(DHTPIN, DHTTYPE);
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
```

### Delay and State Variables

```cpp
int loopdelay = 180;       // Delay between main loops
int Steps = 50;            // Steps to turn the motor
int StepDelay = 20;        // Delay between motor steps
int Display_Delay;
float h, t, f, tempC;      // Variables for sensor readings
float temp_accuracy = 0.50; // Temperature control accuracy

bool buttonState = LOW;
bool hatchState;
bool DelayJumperState;
bool flag = 0;
```

### Motor Control Function

```cpp
void DriveMotor(bool Direction) {
  digitalWrite(DriverEnable_Pin, LOW);  // Enable the driver
  digitalWrite(dirPin, Direction);      // Set motor direction
  for (int x = 0; x < Steps; x++) {
    digitalWrite(stepPin, HIGH);
    delay(StepDelay);
    digitalWrite(stepPin, LOW);
    delay(StepDelay);
  }
  digitalWrite(DriverEnable_Pin, HIGH); // Disable the driver
  Serial.println(F("Motor has turned 45 deg"));
}
```

This function drives the stepper motor to turn the eggs. It takes a `Direction` parameter (HIGH for clockwise, LOW for counterclockwise), enables the motor driver, sets the direction, and then sends pulses to move the motor.

### Setup Function

```cpp
void setup() {
  Serial.begin(9600);
  pinMode(dirPin, OUTPUT);
  pinMode(stepPin, OUTPUT);
  pinMode(DriverEnable_Pin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(relayPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(hatchPin, INPUT_PULLUP);
  pinMode(DelayJumper_Pin, INPUT_PULLUP);

  lcd.begin(16, 2);
  lcd.print("Incubator Init");

  dht.begin();
  sensors.begin();

  delay(2000);
  lcd.clear();
}
```

The `setup()` function initializes the serial communication, sets pin modes, initializes the LCD, DHT11 sensor, and OneWire sensors, and displays an initialization message.

### Main Loop

```cpp
void loop() {
  // Reading sensors
  h = dht.readHumidity();
  t = dht.readTemperature();
  sensors.requestTemperatures();
  tempC = sensors.getTempCByIndex(0);

  // Displaying on LCD
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(h);
  lcd.print("%");

  // Temperature control
  if (t < (setTemp - temp_accuracy)) {
    digitalWrite(relayPin, LOW); // Turn on heating element
  } else if (t > (setTemp + temp_accuracy)) {
    digitalWrite(relayPin, HIGH); // Turn off heating element
  }

  // Egg turning
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    DriveMotor(HIGH);
    delay(5000);
    DriveMotor(LOW);
  }

  delay(loopdelay * 1000);
}
```

In the `loop()` function:

1. Sensor readings are taken for temperature and humidity.
2. The readings are displayed on the LCD.
3. The relay is controlled to maintain the desired temperature.
4. The eggs are turned if the button is pressed.
5. The loop runs with a delay specified by `loopdelay`.

## Installation

1. **Hardware Setup**:
    - Connect the components to the Arduino as per the pin configuration.
    - Ensure the power supply to the stepper motor driver and other components is correctly set up.
    
2. **Software Setup**:
    - Install the necessary libraries in the Arduino IDE.
    - Open the `Egg_Incubator.ino` file in the Arduino IDE.
    - Upload the code to the Arduino board.

## Usage

1. Power on the system.
2. The LCD will display the current temperature, humidity, and system status.
3. The stepper motor will periodically turn the eggs.
4. The relay will control the heating element to maintain the desired temperature.
5. The buzzer will sound if any critical conditions are detected.

## Customization

- **Adjusting Delays**: Modify the `loopdelay`, `StepDelay`, and other timing-related variables to adjust the behavior of the incubator.
- **Temperature Accuracy**: Change the `temp_accuracy` variable to set the desired temperature control precision.
- **Motor Steps**: Adjust the `Steps` variable to change how far the motor turns the eggs.

## Troubleshooting

- **LCD Not Displaying Properly**: Check the connections to the LCD and ensure the correct pins are defined in the code.
- **Temperature/Humidity Readings Incorrect**: Verify the sensor connections and ensure the DHT11 sensor is functioning.
- **Motor Not Turning**: Check the connections to the stepper motor driver and ensure the driver is powered and enabled.

## License

This project is licensed under the MIT License. Feel free to modify and distribute as per the license terms.

## Acknowledgments

Special thanks to the contributors of the libraries used in this project.
