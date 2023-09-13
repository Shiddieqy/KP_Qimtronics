float SCALE = 0.002505538;
#define VOLUME 0.4
#define TS_TOUCH 10
#define TS_MA 20
int timer_ma = millis();
long int dis;
long int tim = millis();
float moisture = 10.23;
float temperature = 24.23;
float density = 130.23;
float weight = 20;
char Moisture[20];
char Temperature[20];
char Density[20];
int sys_State = 1;
char Weight[20];
float ScaleConst = 1;
float gradient = -0.0254;
float offset = 83.043;
float tempSum = 0;
float weightSum = 0;
float moistSum = 0;
int densityAvg = 0;
float moisture_round;
float temperature_round;
float density_round;
float weight_round;
static NimBLECharacteristic *pMeasurementCharacteristic;
uint8_t arr_data[8];
uint16_t moisture_data;
uint16_t temperature_data;
uint16_t density_data; 
uint16_t weight_data; 
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
