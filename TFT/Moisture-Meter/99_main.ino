void setup()
{
    Serial.begin( 115200 ); /* prepare for possible serial debug */
    lvgl_setup();
    view_setup();
    NimBLE_setup();
    setup_loadcell();
      sensors.begin();
      MovDensity.begin();
    
    Serial.println( "Setup done" );
}
void loop()
{   
    lv_timer_handler(); /* let the GUI do its work */
        lv_tick_inc(1);
    delay(1);
    processSerialInput();
//    update_data();
    if(millis() - timer_touch > TS_TOUCH){
      touch_read();
      timer_touch = millis();
      Serial.println("masih jalan");
    }
    if(millis() - timer_ma > TS_MA){
//      scale.power_up();
      densityAvg = MovDensity.reading(scale.get_units());
//      scale.power_down();
      timer_ma = millis();
    }
//    lv_event_send(obj, LV_EVENT_..., &custom_data)


}
