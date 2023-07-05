/*Using LVGL with Arduino requires some extra steps:
 *Be sure to read the docs here: https://docs.lvgl.io/master/get-started/platforms/arduino.html  */

#include <lvgl.h>
#include <TFT_eSPI.h>

/*To use the built-in examples and demos of LVGL uncomment the includes below respectively.
 *You also need to copy `lvgl/examples` to `lvgl/src/examples`. Similarly for the demos `lvgl/demos` to `lvgl/src/demos`.
 Note that the `lv_examples` library is for LVGL v7 and you shouldn't install it for this version (since LVGL v8)
 as the examples and demos are now part of the main LVGL library. */

/*Change to your screen resolution*/
static const uint16_t screenWidth  = 320;
static const uint16_t screenHeight = 240;

static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[ screenWidth * screenHeight / 10 ];

TFT_eSPI tft = TFT_eSPI(screenWidth, screenHeight); /* TFT instance */

#if LV_USE_LOG != 0
/* Serial debugging */
void my_print(const char * buf)
{
    Serial.printf(buf);
    Serial.flush();
}
#endif
lv_obj_t * ui_Screen1;
lv_obj_t * ui_Panel1;
lv_obj_t * ui_TextArea1;
lv_obj_t * ui_Panel2;
lv_obj_t * ui_TextArea2;
lv_obj_t * ui_Arc2;
lv_obj_t * ui_Label2;
lv_obj_t * ui_Label1;
lv_obj_t * ui_TextArea3;
lv_obj_t * ui_Label3;
lv_obj_t * ui_Button2;
lv_obj_t * ui_Button1;
lv_obj_t * ui_Label5;
lv_obj_t * ui_Label4;
lv_obj_t * ui_Label6;
lv_obj_t * ui____initial_actions0;
void ui_Screen1_screen_init(void)
{
    ui_Screen1 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Screen1, lv_color_hex(0x090329), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Screen1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel1 = lv_obj_create(ui_Screen1);
    lv_obj_set_width(ui_Panel1, 58);
    lv_obj_set_height(ui_Panel1, 43);
    lv_obj_set_x(ui_Panel1, -86);
    lv_obj_set_y(ui_Panel1, 16);
    lv_obj_set_align(ui_Panel1, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Panel1, lv_color_hex(0x94AEB4), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Panel1, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TextArea1 = lv_textarea_create(ui_Screen1);
    lv_obj_set_width(ui_TextArea1, 54);
    lv_obj_set_height(ui_TextArea1, 43);
    lv_obj_set_x(ui_TextArea1, -114);
    lv_obj_set_y(ui_TextArea1, 16);
    lv_obj_set_align(ui_TextArea1, LV_ALIGN_CENTER);
    lv_textarea_set_text(ui_TextArea1, "122");
    lv_textarea_set_placeholder_text(ui_TextArea1, "Placeholder...");
    lv_obj_set_style_text_color(ui_TextArea1, lv_color_hex(0x0078FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_TextArea1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_TextArea1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_decor(ui_TextArea1, LV_TEXT_DECOR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_TextArea1, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_TextArea1, lv_color_hex(0x97AEB3), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_TextArea1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_TextArea1, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_text_color(ui_TextArea1, lv_color_hex(0x808080), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_TextArea1, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_TextArea1, LV_TEXT_ALIGN_CENTER, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_TextArea1, &lv_font_montserrat_16, LV_PART_SELECTED | LV_STATE_DEFAULT);

    lv_obj_set_style_text_color(ui_TextArea1, lv_color_hex(0x808080), LV_PART_TEXTAREA_PLACEHOLDER | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_TextArea1, 255, LV_PART_TEXTAREA_PLACEHOLDER | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_TextArea1, LV_TEXT_ALIGN_CENTER, LV_PART_TEXTAREA_PLACEHOLDER | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_TextArea1, &lv_font_montserrat_16, LV_PART_TEXTAREA_PLACEHOLDER | LV_STATE_DEFAULT);

    ui_Panel2 = lv_obj_create(ui_Screen1);
    lv_obj_set_width(ui_Panel2, 104);
    lv_obj_set_height(ui_Panel2, 100);
    lv_obj_set_x(ui_Panel2, -1);
    lv_obj_set_y(ui_Panel2, -42);
    lv_obj_set_align(ui_Panel2, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Panel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Panel2, lv_color_hex(0x94AEB4), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Panel2, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TextArea2 = lv_textarea_create(ui_Panel2);
    lv_obj_set_width(ui_TextArea2, 85);
    lv_obj_set_height(ui_TextArea2, 47);
    lv_obj_set_x(ui_TextArea2, 2);
    lv_obj_set_y(ui_TextArea2, 5);
    lv_obj_set_align(ui_TextArea2, LV_ALIGN_CENTER);
    lv_textarea_set_text(ui_TextArea2, "20.1%");
    lv_textarea_set_placeholder_text(ui_TextArea2, "Placeholder...");
    lv_textarea_set_one_line(ui_TextArea2, true);
    lv_obj_set_style_text_color(ui_TextArea2, lv_color_hex(0x0078FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_TextArea2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_TextArea2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_decor(ui_TextArea2, LV_TEXT_DECOR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_TextArea2, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_TextArea2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_TextArea2, lv_color_hex(0x97AEB3), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_TextArea2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_TextArea2, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_text_color(ui_TextArea2, lv_color_hex(0x808080), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_TextArea2, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_TextArea2, LV_TEXT_ALIGN_CENTER, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_TextArea2, &lv_font_montserrat_16, LV_PART_SELECTED | LV_STATE_DEFAULT);

    lv_obj_set_style_text_color(ui_TextArea2, lv_color_hex(0x808080), LV_PART_TEXTAREA_PLACEHOLDER | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_TextArea2, 255, LV_PART_TEXTAREA_PLACEHOLDER | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_TextArea2, LV_TEXT_ALIGN_CENTER, LV_PART_TEXTAREA_PLACEHOLDER | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_TextArea2, &lv_font_montserrat_16, LV_PART_TEXTAREA_PLACEHOLDER | LV_STATE_DEFAULT);

    ui_Arc2 = lv_arc_create(ui_Panel2);
    lv_obj_set_width(ui_Arc2, 104);
    lv_obj_set_height(ui_Arc2, 150);
    lv_obj_set_x(ui_Arc2, 0);
    lv_obj_set_y(ui_Arc2, 25);
    lv_obj_set_align(ui_Arc2, LV_ALIGN_CENTER);
    lv_arc_set_value(ui_Arc2, 90);

    lv_obj_set_style_opa(ui_Arc2, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_Label2 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Label2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label2, -79);
    lv_obj_set_y(ui_Label2, 15);
    lv_obj_set_align(ui_Label2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label2, "g/cm");
    lv_obj_set_style_text_color(ui_Label2, lv_color_hex(0x0073FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label1 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Label1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label1, -65);
    lv_obj_set_y(ui_Label1, 7);
    lv_obj_set_align(ui_Label1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label1, "3");
    lv_obj_set_style_text_color(ui_Label1, lv_color_hex(0x0879FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label1, &lv_font_montserrat_8, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TextArea3 = lv_textarea_create(ui_Screen1);
    lv_obj_set_width(ui_TextArea3, 75);
    lv_obj_set_height(ui_TextArea3, 43);
    lv_obj_set_x(ui_TextArea3, 93);
    lv_obj_set_y(ui_TextArea3, 16);
    lv_obj_set_align(ui_TextArea3, LV_ALIGN_CENTER);
    lv_textarea_set_text(ui_TextArea3, "20.5");
    lv_textarea_set_placeholder_text(ui_TextArea3, "Placeholder...");
    lv_obj_set_style_text_color(ui_TextArea3, lv_color_hex(0x0078FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_TextArea3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_TextArea3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_decor(ui_TextArea3, LV_TEXT_DECOR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_TextArea3, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_TextArea3, lv_color_hex(0x97AEB3), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_TextArea3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_TextArea3, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_text_color(ui_TextArea3, lv_color_hex(0x808080), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_TextArea3, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_TextArea3, LV_TEXT_ALIGN_CENTER, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_TextArea3, &lv_font_montserrat_16, LV_PART_SELECTED | LV_STATE_DEFAULT);

    lv_obj_set_style_text_color(ui_TextArea3, lv_color_hex(0x808080), LV_PART_TEXTAREA_PLACEHOLDER | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_TextArea3, 255, LV_PART_TEXTAREA_PLACEHOLDER | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_TextArea3, LV_TEXT_ALIGN_CENTER, LV_PART_TEXTAREA_PLACEHOLDER | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_TextArea3, &lv_font_montserrat_16, LV_PART_TEXTAREA_PLACEHOLDER | LV_STATE_DEFAULT);

    ui_Label3 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Label3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label3, 117);
    lv_obj_set_y(ui_Label3, 4);
    lv_obj_set_align(ui_Label3, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label3, "o");
    lv_obj_set_style_text_color(ui_Label3, lv_color_hex(0x0879FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label3, &lv_font_montserrat_8, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button2 = lv_btn_create(ui_Screen1);
    lv_obj_set_width(ui_Button2, 95);
    lv_obj_set_height(ui_Button2, 50);
    lv_obj_set_x(ui_Button2, -71);
    lv_obj_set_y(ui_Button2, 79);
    lv_obj_set_align(ui_Button2, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Button2, 100, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button1 = lv_btn_create(ui_Screen1);
    lv_obj_set_width(ui_Button1, 95);
    lv_obj_set_height(ui_Button1, 50);
    lv_obj_set_x(ui_Button1, 66);
    lv_obj_set_y(ui_Button1, 80);
    lv_obj_set_align(ui_Button1, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Button1, 100, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label5 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Label5, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label5, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label5, -70);
    lv_obj_set_y(ui_Label5, 79);
    lv_obj_set_align(ui_Label5, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label5, "Measure");
    lv_obj_set_style_text_color(ui_Label5, lv_color_hex(0xC0D5EE), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label4 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Label4, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label4, 66);
    lv_obj_set_y(ui_Label4, 80);
    lv_obj_set_align(ui_Label4, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label4, "Tare");
    lv_obj_set_style_text_color(ui_Label4, lv_color_hex(0xC0D5EE), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label6 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Label6, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label6, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label6, -2);
    lv_obj_set_y(ui_Label6, -101);
    lv_obj_set_align(ui_Label6, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label6, "Coffe Moisture Meter");
    lv_obj_set_style_text_color(ui_Label6, lv_color_hex(0x94AEB4), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_Label6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_decor(ui_Label6, LV_TEXT_DECOR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label6, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

}
void ui_init(void)
{
//    LV_EVENT_GET_COMP_CHILD = lv_event_register_id();

    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Screen1_screen_init();
    ui____initial_actions0 = lv_obj_create(NULL);
    lv_disp_load_scr(ui_Screen1);
}

/* Display flushing */
void my_disp_flush( lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_p )
{
    uint32_t w = ( area->x2 - area->x1 + 1 );
    uint32_t h = ( area->y2 - area->y1 + 1 );

    tft.startWrite();
    tft.setAddrWindow( area->x1, area->y1, w, h );
    tft.pushColors( ( uint16_t * )&color_p->full, w * h, true );
    tft.endWrite();

    lv_disp_flush_ready( disp_drv );
}

/*Read the touchpad*/
//void my_touchpad_read( lv_indev_drv_t * indev_drv, lv_indev_data_t * data )
//{
//    uint16_t touchX, touchY;
//
////    bool touched = tft.getTouch( &touchX, &touchY, 600 );
//
//    if( !touched )
//    {
//        data->state = LV_INDEV_STATE_REL;
//    }
//    else
//    {
//        data->state = LV_INDEV_STATE_PR;
//
//        /*Set the coordinates*/
//        data->point.x = touchX;
//        data->point.y = touchY;
//
//        Serial.print( "Data x " );
//        Serial.println( touchX );
//
//        Serial.print( "Data y " );
//        Serial.println( touchY );
//    }
//}

void setup()
{
    Serial.begin( 115200 ); /* prepare for possible serial debug */

    String LVGL_Arduino = "Hello Arduino! ";
    LVGL_Arduino += String('V') + lv_version_major() + "." + lv_version_minor() + "." + lv_version_patch();

    Serial.println( LVGL_Arduino );
    Serial.println( "I am LVGL_Arduino" );

    lv_init();

#if LV_USE_LOG != 0
    lv_log_register_print_cb( my_print ); /* register print function for debugging */
#endif

    tft.begin();          /* TFT init */
    tft.setRotation( 3 ); /* Landscape orientation, flipped */

    /*Set the touchscreen calibration data,
     the actual data for your display can be acquired using
     the Generic -> Touch_calibrate example from the TFT_eSPI library*/
    uint16_t calData[5] = { 275, 3620, 264, 3532, 1 };
//    tft.setTouch( calData );

    lv_disp_draw_buf_init( &draw_buf, buf, NULL, screenWidth * screenHeight / 10 );

    /*Initialize the display*/
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init( &disp_drv );
    /*Change the following line to your display resolution*/
    disp_drv.hor_res = screenWidth;
    disp_drv.ver_res = screenHeight;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register( &disp_drv );

    /*Initialize the (dummy) input device driver*/
    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init( &indev_drv );
    indev_drv.type = LV_INDEV_TYPE_POINTER;
//    indev_drv.read_cb = my_touchpad_read;
    lv_indev_drv_register( &indev_drv );
  
    /* Create simple label */
    lv_obj_t *label = lv_label_create( lv_scr_act() );
    lv_label_set_text( label, "Hello Ardino and LVGL!");
    lv_obj_align( label, LV_ALIGN_CENTER, 0, 0 );
 
    /* Try an example. See all the examples 
     * online: https://docs.lvgl.io/master/examples.html
     * source codes: https://github.com/lvgl/lvgl/tree/e7f88efa5853128bf871dde335c0ca8da9eb7731/examples */
//     lv_example_btn_1();
   
     /*Or try out a demo. Don't forget to enable the demos in lv_conf.h. E.g. LV_USE_DEMOS_WIDGETS*/
//    lv_demo_widgets();               
    // lv_demo_benchmark();          
    // lv_demo_keypad_encoder();     
    // lv_demo_music();              
    // lv_demo_printer();
    // lv_demo_stress();
    ui_Screen1_screen_init();
    ui_init();
    
    Serial.println( "Setup done" );
}
long int dis;
long int tim = millis();
char valstring1[20];
char valstring2[20];
char valstring3[20];
void loop()
{
    lv_timer_handler(); /* let the GUI do its work */
    delay( 5 );
//    lv_tick_inc(5);
//    if (millis() - tim > 500){
//      dis = millis() % 100;
//      sprintf(valstring1, "%d", dis);
//      dis = millis() % 100;
//      sprintf(valstring2, "%d", dis);
//      dis = millis() % 100;
//      lv_arc_set_value(ui_Arc2, dis);
//      lv_textarea_set_text(ui_TextArea1, valstring1);
//      lv_textarea_set_text(ui_TextArea2, valstring2);
//      tim = millis();
//      Serial.println(valstring1);
//    }
}
