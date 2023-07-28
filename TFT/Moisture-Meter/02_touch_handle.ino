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
      if (touchX < 160 and touchX > 80){
        sys_State = 0;
        lv_label_set_text(ui_Label6, "Measuring ...");
      }
      if (touchX > 160){
        sys_State = 1;
         lv_label_set_text(ui_Label6, "Taring ...");
      }
      else if (touchX < 80){
        sys_State = 2;
        lv_label_set_text(ui_Label6, "Calibrating ...");
      }
      Serial.print( "Data x " );
       Serial.println( touchX );
      lv_textarea_set_text(ui_Moisture, "##");
      lv_textarea_set_text(ui_Density, "##");
      lv_textarea_set_text(ui_Temp, "##");
      lv_timer_handler(); /* let the GUI do its work */


      update_data();
    }
}
