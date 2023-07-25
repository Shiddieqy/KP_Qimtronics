void sensor_sampling(){
  if (taree == 0){
      tempSum = 0;
    weightSum = 0;
    moistSum = 0;
   scale.power_up();
      for (int i = 0; i < numMeasurements; i++) {
        sensors.requestTemperatures(); 
        tempSum += sensors.getTempCByIndex(0);
        weightSum += scale.get_units(1);
        moistSum += analogRead(Moisture_Pin);
        delay(samplingInterval);
      }
    scale.power_down();
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

//    taree=2;
//  
  }
  else if (taree == 1){
    scale.power_up();
    scale.tare();
    scale.power_down();
    moisture = 0;
    density = 0;
    temperature = 0;
//    taree=2;
  }
   else if (taree == 2) { // If 'c' is received
      weightSum = 0;
      for (int i = 0; i < 10; i++) {
        weightSum += scale.get_units();
        //weightSum += MovDensity.reading(scale.get_units());
      }
      float weightTemp = weightSum/10;
      SCALE = 200/weightTemp;
//      lv_label_set_text(ui_Label6, "Measuring ..."); 
//      taree =0;
//      lv_timer_handler();
//      sensor_sampling();
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
  scale.power_down();
}
