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

## What Is the Egg Incubation Process?
Egg incubation is the process of maintaining the right environmental conditions—primarily temperature, humidity, and egg turning—to allow an embryo to develop into a chick (or another bird) inside the egg until it hatches.

### Key Elements of the Incubation Process

| Parameter       | Ideal Range (for chickens)                 | Purpose                                                                 |
|----------------|---------------------------------------------|-------------------------------------------------------------------------|
| **Temperature** | 37.5°C ± 0.5°C (99.5°F)                    | Supports proper embryonic development                                  |
| **Humidity**    | 50–55% (first 18 days), 65–70% (last 3 days)| Prevents dehydration or overhydration; aids in successful hatching     |
| **Turning Eggs**| 3–5 times daily (until day 18)              | Prevents the embryo from sticking to the shell and ensures even growth |
| **Ventilation** | Fresh air is crucial                        | Embryo requires oxygen and produces CO₂                                 |
| **Incubation Duration** | ~21 days for chicken eggs              | Varies by species (e.g., 28 days for ducks, 17 days for pigeons)       |

### Stages of the Incubation Process

1. **Day 1–7: Embryo Formation**
   - Heartbeat begins  
   - Circulatory system forms  

2. **Day 8–14: Organ Development**
   - Beak, feathers, and limbs form  

3. **Day 15–18: Final Development**
   - Embryo takes up most of the egg space  
   - Turning is stopped after Day 18  

4. **Day 19–21: Hatching Period**
   - Chick moves into hatching position  
   - Breaks shell using egg tooth
     
![Image](https://github.com/user-attachments/assets/e0e6ea05-133f-46ab-87ef-ac9f9b37459c)

---

## Traditional Incubator
![Image](https://github.com/user-attachments/assets/e8f0fd30-ac76-42cf-8627-12433b4fd207)

---

## Features of this incubator

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

![Image](https://github.com/user-attachments/assets/caefbc83-3e48-471e-90f0-65d48f9bbe03)
    ---

## Components

These connection are just for reference you can change them according to the code.
- ### ATmega328p
  ![Image](https://github.com/user-attachments/assets/2eeb4396-6f14-4eb6-876a-9a3c26726f5f)
  ![Image](https://github.com/user-attachments/assets/95c6d1ef-5f4f-4b47-8f9e-3956bcee5414)
- ### DHT11 Temperature and Humidity Sensor
  ![Image](https://github.com/user-attachments/assets/8716d9d8-ef06-44cb-8f0b-82499b7bb45b)
- ### Stepper Motor and Driver
  ![Image](https://github.com/user-attachments/assets/f41f46b4-6191-4a9a-af0a-e5507ea9950b)
- ### Liquid Crystal Display (LCD 16x2)
  ![Image](https://github.com/user-attachments/assets/f6da93af-b927-4967-ad6e-088fd4beb0a2)
- ### DS18B20 Temperature Sensors
  ![Image](https://github.com/user-attachments/assets/580cba61-69aa-45a2-9212-b368c21ccaca)
- ### Relay Module (for Heat Control)
  ![Image](https://github.com/user-attachments/assets/30649239-22cd-4fac-bbd9-525ff042ec82)
- ### Buzzer
  ![Image](https://github.com/user-attachments/assets/a4f858b3-ada4-4e37-b7f3-46aec326eaa7)
- ### Buttons for user input
  ![Image](https://github.com/user-attachments/assets/5357c363-6555-4236-96d6-2c65563d9abd)

![Image](https://github.com/user-attachments/assets/7ca511a7-9418-452a-8ac1-9681b9dfff95)

---

## Methodology

![Image](https://github.com/user-attachments/assets/9595a17c-1a7f-4716-8061-4bc5b5beaceb)

###  1. System Design

The incubator system is centered around the **ATmega328P microcontroller**, interfacing with various sensors and actuators:

![Image](https://github.com/user-attachments/assets/d90fe84c-6a07-45d5-b3a8-a6d8e5947d65)

- **Sensors**  
  - **DHT11**: Monitors temperature and humidity  
  - **DS18B20**: Provides accurate temperature readings  

- **Actuators**  
  - **Stepper Motor**: Periodically rotates eggs  
  - **Relay Module**: Controls the heating element  
  - **Buzzer**: Alerts when environmental conditions are abnormal  

- **Display**  
  - **16x2 LCD**: Shows real-time temperature and humidity readings  

---

### 2. Control Logic (Firmware)

- Developed using **Arduino IDE (C++)**
- Continuously reads sensor values
- Performs:
  - **Heating control** via relay
  - **Humidity regulation**
  - **Egg rotation**
  - **Error alerting** using a buzzer
  - **LCD updates** for user feedback
    
![Image](https://github.com/user-attachments/assets/9130fd8f-160c-43e8-a60c-e784da22833d)

---

### 3. Modes of Operation

- **Normal Mode**: Active monitoring and control
- **Hatch Mode**: Activated via button; disables rotation and adjusts humidity thresholds
- **Calibration Mode**: Allows for setup adjustments and visual feedback

---

### 4. Hardware Setup

- Components connected via breadboard 
- Reliable power supply to run sensors, display, motor, and controller

| Component           | Arduino Pin     |
|--------------------|-----------------|
| DHT11              | Pin 13          |
| DS18B20            | Pin 2           |
| LCD (rs–d7)        | Pins 12–6       |
| Stepper Motor      | Pins 3–5        |
| Relay              | A1              |
| Buzzer             | A0              |
| Button             | A2              |
| Hatch Trigger      | A3              |
| Delay Jumper       | Pin 7           |


![Image](https://github.com/user-attachments/assets/4b49fe11-582e-43b0-baa5-e2a79918d0a0)

---

### 5. Testing & Validation

- System tested using a **pigeon egg**
- Environmental conditions were successfully maintained
- A chick was successfully hatched, validating system functionality

![Image](https://github.com/user-attachments/assets/44f192c2-ddd6-45dd-8de8-7ec6ac22b21f)
![Image](https://github.com/user-attachments/assets/ea0f2511-4088-4387-bee0-5540fbca7e7f)
![Image](https://github.com/user-attachments/assets/0d8a36d4-95b3-4641-8c35-b7c1a2d172e2)

---

## Results
https://github.com/user-attachments/assets/74fe12b2-0fb4-42b3-a45b-664a12b02d2b
