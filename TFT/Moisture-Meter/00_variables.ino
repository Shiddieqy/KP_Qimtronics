float SCALE= 277.2/110032.30;
#define VOLUME 0.4
#define TS_TOUCH 10
long int dis;
long int tim = millis();
float moisture = 10.23;
float temperature = 24.23;
float density = 130.23;
char Moisture[20];
char Temperature[20];
char Density[20];
int taree = 1;
float ScaleConst = 1;
float gradient = -0.0254;
float offset = 83.043;
float tempSum = 0;
float weightSum = 0;
float moistSum = 0;
const int oneWireBus = 18; 
OneWire oneWire(oneWireBus);
DallasTemperature sensors(&oneWire);
HX711 scale;
// SCREEN: ui_Screen1
void ui_Screen1_screen_init(void);
lv_obj_t * ui_Screen1;
lv_obj_t * ui_Panel6;
lv_obj_t * ui_Label15;
lv_obj_t * ui_Panel7;
lv_obj_t * ui_Label16;
lv_obj_t * ui_Panel1;
lv_obj_t * ui_Density;
lv_obj_t * ui_Panel2;
lv_obj_t * ui_Moisture;
lv_obj_t * ui_Label2;
lv_obj_t * ui_MoistArc;
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
void ui_event_Button3(lv_event_t * e);
lv_obj_t * ui_Button3;
lv_obj_t * ui_Label7;
lv_obj_t * ui____initial_actions0;


bool deviceConnected = false;
