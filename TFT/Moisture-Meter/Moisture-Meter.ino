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

// adjust pressure sensitivity - note works 'backwards'
#define MINPRESSURE 200
#define MAXPRESSURE 1000
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
