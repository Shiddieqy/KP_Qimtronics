void setup()
{
    Serial.begin( 115200 ); /* prepare for possible serial debug */
    lvgl_setup();
    view_setup();
    Serial.println( "Setup done" );
}
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
