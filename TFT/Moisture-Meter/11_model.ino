void sensor_sampling(){
  if (taree == 0){
  float tempSum = 0;
  float weightSum = 0;
  float moistSum = 0;
   for (int i = 0; i < numMeasurements; i++) {
    tempSum += thermocouple.readCelsius();
    weightSum += scale.get_units(1);
    moistSum += analogRead(Moisture_Pin);
    delay(samplingInterval);
  }
  moisture =(moistSum / numMeasurements) * gradient + offset ;
  density = weightSum / numMeasurements* SCALE / VOLUME;
  temperature = tempSum / numMeasurements;

//  Serial.print(moisture);
//  Serial.print("   ");
//  Serial.print(density);
//  Serial.print("   ");
//  Serial.println(temperature);
//  
  }
  else {
    moisture = 0;
    density = 0;
    temperature = 0;
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
}
