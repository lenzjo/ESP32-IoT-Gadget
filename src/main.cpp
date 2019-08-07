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


