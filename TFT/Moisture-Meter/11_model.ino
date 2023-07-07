void sensor_sampling(){
  if (taree == 0){

  scale.power_up();
   for (int i = 0; i < numMeasurements; i++) {
    tempSum += thermocouple.readCelsius();
    weightSum += scale.get_units(1);
    moistSum += analogRead(Moisture_Pin);
    delay(samplingInterval);
  }
  scale.power_down();
  moisture =(moistSum / numMeasurements) * gradient + offset ;
  density = weightSum / numMeasurements* SCALE / VOLUME;
  temperature = tempSum / numMeasurements;

  Serial.print(moisture);
  Serial.print("   ");
  Serial.print(density);
  Serial.print("   ");
  Serial.println(temperature);
  tempSum = 0;
  weightSum = 0;
  moistSum = 0;
  taree=2;
//  
  }
  else if (taree == 1){
      scale.power_up();
   scale.tare();
  scale.power_down();
    moisture = 0;
    density = 0;
    temperature = 0;
    taree=2;
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
