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

  if (!SPIFFS.begin()) {
    // DEBUGPRINTLN("SPIFFS iniz failed");
    while(1) yield();
  }

  tft.init();
  tft.setRotation(3);
  tft.loadFont("SansSerif-36");
  tft.setTextColor(fg, bg);
  tft.fillScreen(bg);

    bool status;

  status = bme.begin(0x76);
  if (!status) {
    tft.println("Could not find a valid BME280 at that address.");
    while (1);
  }
      
  tft.loadFont("NotoSansBold15");
  tft.fillScreen(bg);
}


void loop() {
  refresh_readings(&bme, &tft);
  delay(2000);
}


