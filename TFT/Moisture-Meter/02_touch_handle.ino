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
    if(event_code == LV_EVENT_CLICKED) {
        tare12(e);
    }
}
void ui_event_Button2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        Meassure21(e);
    }
}
