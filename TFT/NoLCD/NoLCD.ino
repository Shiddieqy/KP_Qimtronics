// Include Library
#include <Arduino.h>
#include "max6675.h"
#include "soc/rtc.h"
#include "HX711.h"

// Pin
// Thermocouple
#define thermoDO 19
#define thermoCS 23
#define thermoCLK 5
// Load Cell
#define LOADCELL_DOUT_PIN 34
#define LOADCELL_SCK_PIN 13
// Moisture
#define Moisture_Pin 36

// Constants
const int numMeasurements = 10;  // Number of measurements for averaging
const int samplingInterval = 100;  // Time between measurements in milliseconds

// Variables
float ScaleConst = 1;
float gradient = -0.0254;
float offset = 83.043;

HX711 scale;
MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);

void setup() {
  Serial.begin(115200);
  rtc_clk_cpu_freq_set(RTC_CPU_FREQ_80M);
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  Serial.println("Please wait, tare...");
  delay(1000);
  scale.tare();
  Serial.println();
  Serial.println("Tare done, measurement start!");
  Serial.println("Temperature\t| Weight\t| Moisture");
  delay(1000);
}

void loop() {
  // Variables for averaging
  float tempSum = 0;
  float weightSum = 0;
  float moistSum = 0;

  // Perform measurements
  for (int i = 0; i < numMeasurements; i++) {
    tempSum += thermocouple.readCelsius();
    weightSum += scale.get_units(1);
    moistSum += analogRead(Moisture_Pin);
    delay(samplingInterval);
  }

  // Calculate averages
  float tempAvg = tempSum / numMeasurements;
  float weightAvg = weightSum / numMeasurements;
  float moistAvg = (moistSum / numMeasurements) * gradient + offset;

  // Print the results
  Serial.print(tempAvg, 2);
  Serial.print("\t\t| ");
  Serial.print(weightAvg, 2);
  Serial.print("\t| ");
  Serial.print(moistAvg, 2);
  Serial.println();

  delay(100);
}