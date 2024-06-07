#include <Stepper.h>
#include "DHT.h"
#include <LiquidCrystal.h>
#include <OneWire.h>
#include <DallasTemperature.h>

//=================================================================================================================================//

//ALL PINS DEFINITIONS
const int dirPin = 3; //ic pin 5
const int stepPin = 4; //ic pin 6
const int DriverEnable_Pin = 5; //ic pin 11
const int DelayJumper_Pin = 7;  //ic pin 13
const int buzzerPin = A0; //ic pin 23
const int relayPin = A1; //ic pin 24
const int buttonPin = A2; //ic pin 25
const int hatchPin = A3; //ic pin 26
const int rs = 12, en = 11, d4 = 10, d5 = 9, d6 = 8, d7 = 6;
// rs =ic pin 18, en =ic pin 17, d4= 16, d5= ic pin 15, d6= ic pin 14, d7= ic pin 12

#define ONE_WIRE_BUS 2 //ic pin 4
#define DHTPIN 13  //ic pin 19
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//=================================================================================================================================//

//ALL DELAYS SETTINGS
int loopdelay = 180;
int Steps = 50;
int StepDelay = 20;
int Display_Delay;
float h, t, f, tempC;
float temp_accuracy = 0.50;

bool buttonState = LOW;
bool hatchState;
bool DelayJumperState;
bool flag = 0;

//=================================================================================================================================//

void DriveMotor(bool Direction) { //HIGH is clockwise, LOW is anticlockwise
  digitalWrite(DriverEnable_Pin, LOW); //Turns on Driver

  digitalWrite(dirPin, Direction);    //Sets motor direction to Anti-Clockwise
  for (int x = 0; x < Steps; x++) {
    digitalWrite(stepPin, HIGH);
    delay(StepDelay);
    digitalWrite(stepPin, LOW);
    delay(StepDelay);
  }
  digitalWrite(DriverEnable_Pin, HIGH);
  Serial.println(F("Motor has turned 45 deg"));
}

//=================================================================================================================================//

void LCD_Display() {

  sensors.requestTemperatures();  // Request temperature in Celsius readings from DS18B20
  float tempC = sensors.getTempCByIndex(0);
  float h = dht.readHumidity();  //Request Humidity readings from DHT11
  float t = dht.readTemperature();  // Read temperature as Celsius from DHT
  float f = dht.readTemperature(true);  // Read temperature as Fahrenheit from DHT

  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  //---------------------------------------------------------------//

  if (tempC != DEVICE_DISCONNECTED_C) {  // Check if reading is valid
    Serial.println("Temperature: ");
    Serial.print(tempC + temp_accuracy);
    Serial.print(" °C ");
  } else {
    Serial.println("Error: Could not read temperature data");
  }

  //---------------------------------------------------------------//

  lcd.clear();
  lcd.print(F("Humidity: "));
  lcd.print(h);
  lcd.print(F("%"));
  lcd.setCursor(0, 1); // Move cursor to the next line
  lcd.print(F("Temp: "));
  lcd.print(tempC + temp_accuracy);
  lcd.print(F(" C  "));
  lcd.print(flag = !flag);

  //---------------------------------------------------------------//

  if (h > 62) {
    digitalWrite(relayPin, LOW);
    Serial.println("Humidity is greater than 60% ");
  } else {
    digitalWrite(relayPin, HIGH);
    Serial.println("Humidity is less than 60% ");
  }

  //---------------------------------------------------------------//

  if (h >= 70 || h <= 45 || tempC >= 41 || tempC <= 35 ) {
    Serial.println("Alert!!!");
    digitalWrite(buzzerPin, HIGH);
    Serial.println("Alert!! Something is wrong with Sensors ");
  }
  else {
    digitalWrite(buzzerPin, LOW);
    Serial.println("WOW :) Everything is Working Efficiently! ");
  }
}

//=================================================================================================================================//

void HatchFunction() {
  delay(1000);
  sensors.requestTemperatures();  // Request temperature in Celsius readings from DS18B20
  float tempC = sensors.getTempCByIndex(0);
  float h = dht.readHumidity();  //Request Humidity readings from DHT11
  float t = dht.readTemperature();  // Read temperature as Celsius from DHT
  float f = dht.readTemperature(true);  // Read temperature as Fahrenheit from DHT

  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  //---------------------------------------------------------------//

  if (tempC != DEVICE_DISCONNECTED_C) {  // Check if reading is valid
    Serial.println("Temperature: ");
    Serial.print(tempC + temp_accuracy);
    Serial.print(" °C ");
  } else {
    Serial.println("Error: Could not read temperature data");
  }

  //---------------------------------------------------------------//

  lcd.clear();
  lcd.print(F("---We are in ---"));
  lcd.setCursor(0, 1);
  lcd.print(F("---Hatch Mode---"));
  delay(1500);
  lcd.clear();
  lcd.print(F("Humidity: "));
  lcd.print(h);
  lcd.print(F("%"));
  lcd.setCursor(0, 1); // Move cursor to the next line
  lcd.print(F("Temp: "));
  lcd.print(tempC + temp_accuracy);
  lcd.print(F(" C  "));
  lcd.print(flag = !flag);

  //---------------------------------------------------------------//

  if (h >= 72) {
    digitalWrite(relayPin, LOW);
    Serial.println("Humidity is greater than 60% ");
  } else {
    digitalWrite(relayPin, HIGH);
    Serial.println("Humidity is less than 60% ");
  }

  //---------------------------------------------------------------//

  if (h >= 75 || h <= 55 || tempC >= 40 || tempC <= 35 ) {
    Serial.println("Alert!!!");
    digitalWrite(buzzerPin, HIGH);
    Serial.println("Alert!! Something is wrong with Sensors ");
  }
  else {
    digitalWrite(buzzerPin, LOW);
    Serial.println("WOW :) Everything is Working Efficiently! ");
  }
};

//=================================================================================================================================//

void setup() {
  Serial.begin(9600);
  pinMode(DriverEnable_Pin, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(relayPin, OUTPUT);
  pinMode(DelayJumper_Pin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(hatchPin, OUTPUT);
  lcd.begin(16, 2);
  dht.begin();
  sensors.begin();
}

//=================================================================================================================================//

void loop() {

  hatchState = digitalRead(hatchPin);
  if (hatchState == HIGH) {
    digitalWrite(DriverEnable_Pin, HIGH);
    HatchFunction();
    delay(3000);
  } else {
    delay(1000);
    LCD_Display();

    buttonState = digitalRead(buttonPin);
    DelayJumperState = digitalRead(DelayJumper_Pin);
    if (DelayJumperState == LOW) {
      Display_Delay = 300; //300
    } else {
      Display_Delay = 20000; //Egg_Rotation_Sec = [(Display_Delay ) x (No. of loops)] / 1000
    }

    //--------------------------------------------------------------------------------------//

    if (buttonState == LOW) {
      Serial.println("Button is not Pressed");
      lcd.clear();
      lcd.print("--Calibration--");
      lcd.setCursor(0, 1);
      lcd.print("------Mode------");
      delay(1000);
    }
    else {
      Serial.println("Button is Pressed!");

      DriveMotor(HIGH); //Drives motor in Clockwise direction
      for (int i = 0; i < loopdelay; i++) { // Run the loop for a total delay of 1 hour
        LCD_Display();
        delay(Display_Delay);
      }

      //----------------------------------------------------------------------------------//

      DriveMotor(LOW);   //Drives motor in Anti-Clockwise direction
      for (int i = 0; i < loopdelay; i++) { // Run the loop for a total delay of 1 hour
        LCD_Display();
        delay(Display_Delay);
      }

      //----------------------------------------------------------------------------------//

      DriveMotor(LOW);   //Drives motor in Anti-Clockwise direction
      for (int i = 0; i < loopdelay; i++) { // Run the loop for a total delay of 1 hour
        LCD_Display();
        delay(Display_Delay);
      }

      //----------------------------------------------------------------------------------//

      DriveMotor(HIGH);   //Drives motor in Clockwise direction
      for (int i = 0; i < loopdelay; i++) { // Run the loop for a total delay of 1 hour
        LCD_Display();
        delay(Display_Delay);
      }
    }
  }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
