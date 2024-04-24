#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

#define DHTPIN 14

#define DHTTYPE DHT11

LiquidCrystal_I2C lcd(0x3F, 16, 2);  // I2C address 0x27, 16 column and 2 rows

const int voltageSensorPin = 34;  // Analog pin for the voltage sensor
const int light = 35;  // Analog pin for the voltage sensor
int load= 4;
int charging=12;
int fullcharge=13;

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
   dht.begin();
   lcd.init();
  lcd.backlight();

  pinMode(load, INPUT);
  pinMode(charging, INPUT);
  pinMode(fullcharge, INPUT);
    lcd.setCursor(2,0);
  lcd.print("Solar System");
    lcd.setCursor(5,1);
  lcd.print("Ready");
  delay(1500);
  
  
}

void loop() {
  int loadStatus=digitalRead(load);
  int chargingStatus=digitalRead(charging);
  int fullchargeStatus=digitalRead(fullcharge);
  int hum = dht.readHumidity();
  int temp = dht.readTemperature();
  // Read the raw analog value from the voltage sensor
  int rawValue = analogRead(voltageSensorPin);
  int lightvalue = analogRead(light);

  int lumen=map(lightvalue,0,3200,0,5000);

  // Calculate the battery percentage (assuming a 3.7V battery)
  int batterycharge = map(rawValue, 520, 775, 0, 100);
  batterycharge = constrain(batterycharge, 0, 100);

  // Display the voltage and battery percentage on the LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(temp);
  lcd.print("C");

   lcd.setCursor(8, 0);
  lcd.print("H: ");
  lcd.print(hum);
  lcd.print("%");

  lcd.setCursor(0, 1);
  lcd.print("L:");
  lcd.print(lumen);
  lcd.print(" Lx");

   lcd.setCursor(9, 1);
  lcd.print("Ch:");
  lcd.print(batterycharge);
  lcd.print("%");

  delay(1000);  // Delay for readability, adjust as needed
}
