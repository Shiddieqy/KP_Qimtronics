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
    lv_tick_inc(5);
    update_data();

}
