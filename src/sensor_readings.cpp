#include <Arduino.h>
#include "settings.h"
#include "sensor_readings.h"


void refresh_readings(Adafruit_BME280* bme, TFT_eSPI* tft) {
  float f_temperature;
  float f_humidity;
  float f_pressure;
  float f_altitude;

  uint16_t bg = TFT_BLACK;

  f_temperature = bme->readTemperature();
  f_humidity    = bme->readHumidity();
  f_pressure    = bme->readPressure();
  f_altitude    = bme->readAltitude(SEALEVELPRESSURE_HPA);

  tft->setTextColor(TFT_YELLOW, bg);

  // Temperature
  tft->fillRect(5, 50, 140, 30, bg);
  tft->setCursor(5, 50);
  tft->print(f_temperature);
  tft->println(" °C");

  // Humidity
  tft->fillRect(5, 90, 130, 30, bg);
  tft->setCursor(5, 90);
  tft->print(f_humidity);
  tft->println(" %");

  // Air Pressure
  tft->fillRect(5, 130, 200, 30, bg);
  tft->setCursor(5, 130);
  tft->print(f_pressure);
  tft->println(" hPa");

  // Altitude
  tft->fillRect(5, 170, 200, 30, bg);
  tft->setCursor(5, 170);
  tft->print(f_altitude);
  tft->println(" m");
}