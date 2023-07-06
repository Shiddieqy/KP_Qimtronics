#define SCALE 200/89529
#define VOLUME 1

long int dis;
long int tim = millis();
float moisture = 10.23;
float temperature = 24.23;
float density = 130.23;
char Moisture[20];
char Temperature[20];
char Density[20];
int taree = 0;
float ScaleConst = 1;
float gradient = -0.0254;
float offset = 83.043;

HX711 scale;
lv_obj_t * ui_Screen1;
lv_obj_t * ui_Panel6;
lv_obj_t * ui_Label15;
lv_obj_t * ui_Panel7;
lv_obj_t * ui_Label16;
lv_obj_t * ui_Panel1;
lv_obj_t * ui_Density;
lv_obj_t * ui_Panel2;
lv_obj_t * ui_Moisture;
lv_obj_t * ui_MoistArc;
lv_obj_t * ui_Label2;
lv_obj_t * ui_Label1;
lv_obj_t * ui_Temp;
lv_obj_t * ui_Label3;
void ui_event_Button2(lv_event_t * e);
lv_obj_t * ui_Button2;
void ui_event_Button1(lv_event_t * e);
lv_obj_t * ui_Button1;
lv_obj_t * ui_Label5;
lv_obj_t * ui_Label4;
lv_obj_t * ui_Label6;
lv_obj_t * ui_Label13;
lv_obj_t * ui____initial_actions0;
