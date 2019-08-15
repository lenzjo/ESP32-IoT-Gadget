#include <Arduino.h>
#include "sensor_readings.h"
#include <TFT_eSPI.h>
#include "settings.h"


Adafruit_BME280 bme;

TFT_eSPI tft = TFT_eSPI();

uint16_t bg = TFT_BLACK;
uint16_t fg = TFT_WHITE;


void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);

  tft.init();
  tft.setRotation(3);
  tft.setTextColor(fg, bg);
  tft.fillScreen(bg);

  tft.setCursor(0, 0);
  tft.println("Hello");
  tft.println("Starting BM280 sensor...");
  delay(5000);

  bool status;

  status = bme.begin(0x76);
  if (!status) {
    Serial.println("Could not fin a valid BME280 at that address.");
    while (1);
  }

  tft.fillScreen(bg);
}


void loop() {
  refresh_readings(&bme, &tft);
  delay(2000);
}


