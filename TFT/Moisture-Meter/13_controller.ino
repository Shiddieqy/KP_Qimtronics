void update_data(){
//      if (millis() - tim > 10){
        sensor_sampling();
        if(sys_State == 0){
        sprintf(Moisture, "%.1f%%", moisture);
        sprintf(Temperature, "%.1f", temperature);
        sprintf(Density, "%.1f", density);
        lv_arc_set_value(ui_MoistArc, int(moisture*5));
        lv_textarea_set_text(ui_Moisture, Moisture);
        lv_textarea_set_text(ui_Temp, Temperature);
        lv_textarea_set_text(ui_Density, Density);
        }
        lv_label_set_text(ui_Label6, "Coffee Moisture Meter");
    
        moisture_round = rounded_02(moisture);
        temperature_round = rounded_02(temperature);
        density_round = rounded_02(density);

        moisture_data = ((uint16_t)(moisture_round * 100));
        temperature_data = ((uint16_t)(temperature_round * 100));
        density_data = ((uint16_t)(density_round * 100));

        arr_data[5]   = (temperature_data ) & 0xFF;
        arr_data[4]   = ((temperature_data >> 8) & 0xFF);
        arr_data[3]   = (density_data ) & 0xFF;
        arr_data[2]   = ((density_data >> 8) & 0xFF);
        arr_data[1]   = (moisture_data ) & 0xFF;
        arr_data[0]   = ((moisture_data >> 8) & 0xFF);
        
        pMeasurementCharacteristic->setValue(arr_data, sizeof(arr_data));
        pMeasurementCharacteristic->notify();
        scale.power_up();
//        tim = millis();
//    }
}
