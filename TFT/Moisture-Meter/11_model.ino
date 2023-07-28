
// Measurement function
void sensor_sampling(){
  // measure if the state is 0
  if (sys_State == 0){
    tempSum = 0;
    weightSum = 0;
    moistSum = 0;
    scale.power_up();
    //Averaging <numMeasurement> times
    for (int i = 0; i < (5*numMeasurements); i++) {
      if (i>(4*numMeasurements-1)){
        sensors.requestTemperatures(); 
        tempSum += sensors.getTempCByIndex(0);
        weightSum += MovDensity.reading(scale.get_units());
        moistSum += analogRead(Moisture_Pin);
      } else {
        MovDensity.reading(scale.get_units());
      }

    moisture =(moistSum / numMeasurements) * gradient + offset ;
    density = weightSum / numMeasurements* SCALE / VOLUME;
    if (density < 1){
      density = 0;
    }
    temperature = tempSum / numMeasurements;

    Serial.print(moisture);
    Serial.print("   ");
    Serial.print(density);
    Serial.print("   ");
    Serial.println(temperature);


  }

  // Taring if the state is 1
  else if (sys_State == 1){
    scale.power_up();
    scale.tare();

    moisture = 0;
    density = 0;
    temperature = 0;

  }

  // calibr
  else if (sys_State == 2) { 
      weightSum = 0;
      for (int i = 0; i < 10; i++) {
        weightSum += scale.get_units();
        //weightSum += MovDensity.reading(scale.get_units());
      }
      float weightTemp = weightSum/10;
      SCALE = 200/weightTemp;
    }
}

void setup_loadcell(){
  rtc_clk_cpu_freq_set(RTC_CPU_FREQ_80M);
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  Serial.println("Please wait, tare...");
  delay(1000);
  scale.tare();
  Serial.println();
  Serial.println("Tare done, measurement start!");
  // scale.power_down();
}
