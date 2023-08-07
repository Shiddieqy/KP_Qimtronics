/*  COFFEE MOISTURE METER
 *   Made by :
 *   Shabri Ash Shiddieqy
 *   Ihsan M Fauzan
 *   
 *   @2023
 */




/*Using LVGL with Arduino requires some extra steps:
 *Be sure to read the docs here: https://docs.lvgl.io/master/get-started/platforms/arduino.html  */

#include <lvgl.h>
#include <TFT_eSPI.h>
#include <TouchScreen.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <NimBLEDevice.h>
#include <movingAvg.h>

// adjust pressure sensitivity - note works 'backwards'
#define MINPRESSURE 200
#define MAXPRESSURE 1000
#include "max6675.h"
#include "soc/rtc.h"
#include "HX711.h"


// Pin
// Load Cell
#define LOADCELL_DOUT_PIN 35
#define LOADCELL_SCK_PIN 13
// Moisture
#define Moisture_Pin 36
MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);
const int numMeasurements = 10;  // Number of measurements for averaging
const int samplingInterval = 10; 
const int XP = 27, XM = 15, YP = 4, YM = 14; // default ESP32 Uno touchscreen pins
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);
const int coords[] = {3800, 0, 0, 3800}; 

/*Change to your screen resolution*/
static const uint16_t screenWidth  = 240;
static const uint16_t screenHeight = 320;

static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[ screenWidth * screenHeight / 10 ];

TFT_eSPI tft = TFT_eSPI(screenWidth, screenHeight); /* TFT instance */

void my_disp_flush( lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_p );
void my_touchpad_read( lv_indev_drv_t * indev_drv, lv_indev_data_t * data );
void tare12(lv_event_t * e);
void Meassure21(lv_event_t * e);

movingAvg MovDensity(20);

// Bluetooth Properties
#define bleServerName "MoistureMeter"
#define SERVICE_UUID        "6e400001-b5a3-f393-e0a9-e50e24dcca9e"
#define CHARACTERISTIC_UUID "6e400003-b5a3-f393-e0a9-e50e24dcca9e"
