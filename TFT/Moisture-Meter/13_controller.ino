void update_data(){
      if (millis() - tim > 500){
        sensor_sampling();

        sprintf(Moisture, "%.1f%%", moisture);
        sprintf(Temperature, "%.1f", temperature);
        sprintf(Density, "%.1f", density);
        lv_arc_set_value(ui_MoistArc, int(moisture*5));
        lv_textarea_set_text(ui_Moisture, Moisture);
        lv_textarea_set_text(ui_Temp, Temperature);
        lv_textarea_set_text(ui_Density, Density);

        static char MoistBLE[6];
        dtostrf(moisture, 6, 2, MoistBLE);
        //Set temperature Characteristic value and notify connected client
        MoistureCharacteristics.setValue(MoistBLE);
        MoistureCharacteristics.notify();

        static char TempBLE[6];
        dtostrf(temperature, 6, 2, TempBLE);
        //Set temperature Characteristic value and notify connected client
        TemperatureCharacteristics.setValue(TempBLE);
        TemperatureCharacteristics.notify();

        static char DenseBLE[6];
        dtostrf(density, 6, 2, DenseBLE);
        //Set temperature Characteristic value and notify connected client
        DensityCharacteristics.setValue(DenseBLE);
        DensityCharacteristics.notify();
        
        tim = millis();
    }
}

void processSerialInput() {
  if (Serial.available()) { // Check if data is available to read
    char receivedChar = Serial.read(); // Read a character from the serial monitor
    
    if (receivedChar == 'm') { // If 'm' is received
      taree = 1; // Set taree value to 1
    } else if (receivedChar == 't') { // If 't' is received
      taree = 0; // Set taree value to 0
    }
  }
}
