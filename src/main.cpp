#include <Arduino.h>
#include "sensor_readings.h"
#include "settings.h"
#include "bmp_functions.h"
#include <TaskScheduler.h>

void sensor_readings_update();

Adafruit_BME280 bme;

TFT_eSPI tft = TFT_eSPI();

uint16_t bg = TFT_BLACK;
uint16_t fg = TFT_WHITE;

// Tasks for the Scheduler
Task t1_bme280(2000, TASK_FOREVER, &sensor_readings_update);

Scheduler skeduler;


void setup() {
  pinMode(LED_BUILTIN, OUTPUT);

  if (!SPIFFS.begin()) {
    // DEBUGPRINTLN("SPIFFS iniz failed");
    while(1) yield();
  }

  skeduler.addTask(t1_bme280);
  t1_bme280.enable();


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
  drawBmp("/te.bmp", 160, 198, &tft); 
}


void loop() {
  skeduler.execute();
}

void sensor_readings_update() {
  refresh_readings(&bme, &tft);
}
