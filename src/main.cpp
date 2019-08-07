#include <Arduino.h>
#include "sensor_readings.h"
#include "settings.h"


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
  refresh_readings(bme);
  delay(2000);
}


