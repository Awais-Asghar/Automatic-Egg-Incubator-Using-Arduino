# Automatic_Egg_Incubator_Using_Atmega328p
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

- **Stepper Motor Control**:
  - `dirPin`: 3
  - `stepPin`: 4
  - `DriverEnable_Pin`: 5
- **Sensors**:
  - `DHT11`: Pin 13
  - `OneWire Bus`: Pin 2
- **LCD Display**:
  - `rs`: 12
  - `en`: 11
  - `d4`: 10
  - `d5`: 9
  - `d6`: 8
  - `d7`: 6
- **Other**:
  - `buzzerPin`: A0
  - `relayPin`: A1
  - `buttonPin`: A2
  - `hatchPin`: A3

## Libraries Used

- `Stepper.h`
- `DHT.h`
- `LiquidCrystal.h`
- `OneWire.h`
- `DallasTemperature.h`

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
