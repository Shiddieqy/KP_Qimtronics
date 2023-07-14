void update_data(){
//      if (millis() - tim > 10){
        sensor_sampling();
        if(taree == 0){
        sprintf(Moisture, "%.1f%%", moisture);
        sprintf(Temperature, "%.1f", temperature);
        sprintf(Density, "%.1f", density);
        lv_arc_set_value(ui_MoistArc, int(moisture*5));
        lv_textarea_set_text(ui_Moisture, Moisture);
        lv_textarea_set_text(ui_Temp, Temperature);
        lv_textarea_set_text(ui_Density, Density);
        }
        lv_label_set_text(ui_Label6, "Coffee Moisture Meter");

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
        
//        tim = millis();
//    }
}
