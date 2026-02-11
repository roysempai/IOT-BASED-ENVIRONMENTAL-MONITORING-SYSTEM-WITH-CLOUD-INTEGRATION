// =======================
#include "arduino_secrets.h"
#include "thingProperties.h"
#include "DHT.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
// ===========================
LiquidCrystal_I2C lcd(0x27, 16, 2);
#define SDA_PIN 4  
#define SCL_PIN 5  
#define DHTpin 2   
#define DHTtype DHT11

DHT dht(DHTpin, DHTtype);
int sensor = A0;

void setup() {
  dht.begin();
  Serial.begin(9600);
  Wire.begin(SDA_PIN, SCL_PIN);
  lcd.begin(16, 2);
  lcd.backlight();  
  delay(1500); 

  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();

  float hm = dht.readHumidity();
  Serial.print("Humidity: ");
  Serial.println(hm);
  humidity = hm;
    
  float temp = dht.readTemperature();
  Serial.print("Temperature: ");
  Serial.println(temp);
  temperature = temp;
    
  int airqualityvalue = analogRead(sensor);
  Serial.print("Gas Value: ");
  Serial.println(airqualityvalue);
  airquality = airqualityvalue;

  message = "Temperature = " + String(temperature) + 
            "  Humidity = " + String(humidity) + 
            "  Air Quality = " + String(airqualityvalue);

  lcd.setCursor(0, 0);
  lcd.print("T:"); lcd.print(temp); lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("H: "); lcd.print(hm); lcd.print(" %");

  lcd.setCursor(8, 0);
  lcd.print(" Air:"); lcd.print(airqualityvalue);

  delay(1000);
}

void onTemperatureChange() {}
void onHumidityChange() {}
void onAirqualityChange() {}
void onMessageChange() {}
