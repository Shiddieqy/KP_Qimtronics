unsigned long int timer_touch = millis();
boolean Touch_getXY(uint16_t *x, uint16_t *y) {
    TSPoint p = ts.getPoint();
    pinMode(YP, OUTPUT);      //restore shared pins
    pinMode(XM, OUTPUT);
    digitalWrite(YP, HIGH);   //because TFT control pins
    digitalWrite(XM, HIGH);
    bool pressed = (p.z > MINPRESSURE && p.z < MAXPRESSURE);
    *x = map(p.x, coords[0], coords[1], 0, tft.width()); 
    *y = map(p.y, coords[2], coords[3], 0, tft.height());
    return pressed;
}
void touch_read()
{
    uint16_t touchX, touchY;

    bool touched = Touch_getXY( &touchX, &touchY);

    if(touched)
    {
      if (touchX < 120){
        taree = 0;
        lv_label_set_text(ui_Label6, "Measuring ...");
      }
      if (touchX > 120){
        taree = 1;
         lv_label_set_text(ui_Label6, "Taring ...");
      }
      Serial.print( "Data x " );
        Serial.println( touchX );
      lv_textarea_set_text(ui_Moisture, "##");
      lv_textarea_set_text(ui_Density, "##");
      lv_textarea_set_text(ui_Temp, "##");
          lv_timer_handler(); /* let the GUI do its work */
//        lv_tick_inc(1);
//    delay(1);

      update_data();
    }
//        data->state = LV_INDEV_STATE_PR;

//        /*Set the coordinates*/
//        data->point.x = touchX;
//        data->point.y = touchY;

//        Serial.print( "Data x " );
//        Serial.println( touchX );
//
//        Serial.print( "Data y " );
//        Serial.println( touchY );
//    }
}
void tare12(lv_event_t * e)
{
  taree = 1;
}
void Meassure21(lv_event_t * e)
{
  // Your code here
  taree = 0;
}

void ui_event_Button1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
//    if(event_code == LV_EVENT_CLICKED) {
        tare12(e);
//    }
}
void ui_event_Button2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
//    if(event_code == LV_EVENT_CLICKED) {
        Meassure21(e);
//    }
}
