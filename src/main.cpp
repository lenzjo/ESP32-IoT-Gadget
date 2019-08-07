#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

void refresh_readings();

#ifndef LED_BUILTIN
  #define LED_BUILTIN 2
#endif

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME280 bme;


void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  bool status;

  status = bme.begin(0x76);
  if (!status) {
    Serial.println("Could not fin a valid BME280 at that address.");
    while (1);
  }
  
}


void loop() {
  refresh_readings();
  delay(2000);
}


void refresh_readings() {
  float f_temperature;
  float f_humidity;
  float f_pressure;
  float f_altitude;

  digitalWrite(LED_BUILTIN, HIGH);

  f_temperature = bme.readTemperature();
  f_humidity    = bme.readHumidity();
  f_pressure    = bme.readPressure();
  f_altitude    = bme.readAltitude(SEALEVELPRESSURE_HPA);

  Serial.print(f_temperature);
  Serial.println(" 'C");

  Serial.print(f_humidity);
  Serial.println(" %");

  Serial.print(f_pressure);
  Serial.println(" hPa");

  Serial.print(f_altitude);
  Serial.println(" m");

  digitalWrite(LED_BUILTIN, LOW);
  Serial.println("-------------");
}