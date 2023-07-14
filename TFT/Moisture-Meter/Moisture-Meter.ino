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
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>
// adjust pressure sensitivity - note works 'backwards'
#define MINPRESSURE 200
#define MAXPRESSURE 1000
#include "max6675.h"
#include "soc/rtc.h"
#include "HX711.h"


// Pin
// Thermocouple
#define thermoDO 19
#define thermoCS 23
#define thermoCLK 5
// Load Cell
#define LOADCELL_DOUT_PIN 35
#define LOADCELL_SCK_PIN 13
// Moisture
#define Moisture_Pin 36
MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);
const int numMeasurements = 4;  // Number of measurements for averaging
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


// Bluetooth Properties
#define bleServerName "MoistureMeter"
#define SERVICE_UUID "91bad492-b950-4226-aa2b-4ede9fa42f59"

BLECharacteristic MoistureCharacteristics("f78ebbff-c8b7-4107-93de-889a6a06d408", BLECharacteristic::PROPERTY_NOTIFY);
BLEDescriptor MoistureDescriptor(BLEUUID((uint16_t)0x2902));

BLECharacteristic TemperatureCharacteristics("cba1d466-344c-4be3-ab3f-189f80dd7518", BLECharacteristic::PROPERTY_NOTIFY);
BLEDescriptor TemperatureDescriptor(BLEUUID((uint16_t)0x2902));

BLECharacteristic DensityCharacteristics("be773d42-214d-11ee-be56-0242ac120002", BLECharacteristic::PROPERTY_NOTIFY);
BLEDescriptor DensityDescriptor(BLEUUID((uint16_t)0x2903));
