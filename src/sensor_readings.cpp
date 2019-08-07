#include <Arduino.h>
#include "settings.h"
#include "sensor_readings.h"


void refresh_readings(Adafruit_BME280 bme) {
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