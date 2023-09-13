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
    lv_timer_handler(); // Refresh GUI
    lv_tick_inc(1);
    delay(1);
    processSerialInput(); // Reading serial input from BLE

    // Touch sampling
    if(millis() - timer_touch > TS_TOUCH){
      touch_read();
      timer_touch = millis();
      //Serial.println("masih jalan");
    }

    // Moving average sampling
    if(millis() - timer_ma > TS_MA){
//      scale.power_up();
      densityAvg = MovDensity.reading(scale.get_units());
      Serial.print(densityAvg);
      Serial.print("\t");
      Serial.println(scale.get_units());
//      scale.power_down();
      timer_ma = millis();
    }
}
