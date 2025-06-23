# Fully Automated Egg Incubator

![Project Status](https://img.shields.io/badge/status-Completed-brightgreen.svg)
![Platform](https://img.shields.io/badge/platform-ATmega328P-blue.svg)
![Tool](https://img.shields.io/badge/tool-Arduino%20IDE-lightgrey.svg)
![Sensor](https://img.shields.io/badge/sensor-DHT11%20%7C%20DS18B20-orange.svg)
![Actuator](https://img.shields.io/badge/actuator-Stepper%20Motor%20%7C%20Relay-blueviolet.svg)
![Simulation](https://img.shields.io/badge/tested-In%20Real%20Environment-yellow.svg)

## Abstract

The "Fully Automated Egg Incubator" is a microcontroller-based system designed to regulate temperature, humidity, and periodic egg rotation to ensure optimal hatching conditions. It uses the **ATmega328P** microcontroller, temperature/humidity sensors, and actuators like a stepper motor and relay to fully automate the incubation process.

---

## Objectives

- Automatically control and monitor temperature and humidity
- Periodically rotate the eggs using a stepper motor
- Display real-time environmental conditions on a 16x2 LCD
- Alert users via a buzzer in case of abnormal conditions

---

## Features 

1. **Automatic Egg Rotation**
   - Uses a **stepper motor** to rotate eggs periodically.
   - Simulates natural hen-like rotation to prevent yolk sticking.

2. **Temperature Monitoring and Control**
   - Dual temperature sensors:
     - **DS18B20** for high-precision temperature readings.
     - **DHT11** for basic temperature and humidity data.
   - Controls a **heating element** via a relay to maintain temperature between **36–40°C**.

3. **Humidity Monitoring and Control**
   - Monitors humidity using the **DHT11 sensor**.
   - Activates relay-controlled elements (like water trays or humidifiers) when humidity drops below safe levels (e.g., **<60%**).

4. **Real-time LCD Display**
   - Shows current **temperature and humidity**.
   - Refreshes every few seconds for up-to-date environmental info.

5. **Alert System (Buzzer)**
   - Sounds an alarm if:
     - Temperature goes outside **35–41°C**.
     - Humidity falls outside **45–70%**.
   - Ensures fast response to critical conditions.

6. **Manual Control Option**
   - Includes physical buttons for **calibration** and **hatch mode activation**.
   - Allows manual override and user input.

7. **Hatch Mode**
   - Switches to adjusted settings during the hatching phase.
   - Modifies humidity threshold and **disables egg rotation** automatically.

8. **Calibrated Delay Settings**
   - Adjustable **LCD display refresh** and **rotation interval** via jumper pins.
   - Offers fine-tuning for different egg types.

9. **Simple, Low-Cost Hardware Setup**
   - Built around **Arduino-compatible ATmega328P**.
   - Uses affordable and readily available components.

10. **Real Environment Tested**
    - Successfully incubated and hatched a **pigeon's egg**.
    - Validated under **real-world** conditions (not just simulated).
   
    ---

## Components

- Arduino
- DHT11 Temperature and Humidity Sensor
- Stepper Motor and Driver
- Liquid Crystal Display (LCD 16x2)
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
