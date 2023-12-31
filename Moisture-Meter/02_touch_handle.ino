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

    bool touched = Touch_getXY( &touchX, &touchY); //return true when lcd touched and gives the coordinate (touchX,touchY)

    if(touched) // if lcd has touched enter switching mode
    {
      // There are 3 button 
      // hence there are 3 states
      if (touchX < 160 and touchX > 80){
        sys_State = 0; //change state
        lv_label_set_text(ui_Label6, "Measuring ..."); // To indicate that the system recieved the command
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

      // values leave blank to indicate the system still computing
      lv_textarea_set_text(ui_Moisture, "##");
      lv_textarea_set_text(ui_Density, "##");
      lv_textarea_set_text(ui_Temp, "##");
      lv_timer_handler(); // Refresh GUI

      // the corresponding state will be processed in this function on controller tab
      update_data();
    }
}
