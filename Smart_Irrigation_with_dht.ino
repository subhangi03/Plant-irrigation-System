

#include "dht.h"
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

dht DHT;

#define DHT11_PIN 5

int sensor_pin = A0; // Soil Sensor input at Analog PIN A0
int output_value ;
int relayPin = 6;

void setup(){
  lcd.begin(16, 2);
    lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.setCursor(1,1);
  pinMode(sensor_pin, INPUT);
  pinMode(relayPin, OUTPUT);
}

void loop(){
  int chk = DHT.read11(DHT11_PIN);
  lcd.setCursor(0,0); 
  lcd.print("Temp: ");
  lcd.print(DHT.temperature);
  lcd.print((char)223);
  lcd.print("C");
  
  lcd.setCursor(0,1); 
  lcd.print("Humidity: ");
  lcd.print(DHT.humidity);
  lcd.print("%");
  delay(2000);
  
  lcd.setCursor(23,0);
  lcd.autoscroll();
  output_value= analogRead(sensor_pin);
  output_value = map(output_value,550,10,0,100);
  lcd.print("Mositure: ");
  lcd.print(output_value);
  lcd.print("%");
  
  lcd.setCursor(23,1);
  if(output_value<30){
  digitalWrite(relayPin, HIGH);ty
  lcd.print("Motor ON");
 }
 else
 {
  digitalWrite(relayPin, LOW);
  lcd.print("Motor OFF");       
 }
  
  delay(2500);
  lcd.noAutoscroll();
  lcd.clear();
}
