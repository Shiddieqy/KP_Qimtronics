// Main processing function
void update_data(){
        // obtain sensor values
        sensor_sampling();

        // only show values when state is 0 (measuring)
        if(sys_State == 0){
        sprintf(Moisture, "%.1f%%", moisture);
        sprintf(Temperature, "%.1f", temperature);
        sprintf(Density, "%.1f", density);
        sprintf(Weight, "%.1f", weight);
        lv_arc_set_value(ui_MoistArc, int(moisture*5));
        lv_textarea_set_text(ui_Moisture, Moisture);
        lv_textarea_set_text(ui_Temp, Temperature);
        lv_textarea_set_text(ui_Density, Density);
        }
        lv_label_set_text(ui_Label6, "Coffee Moisture Meter");
    
        moisture_round = rounded_02(moisture);
        temperature_round = rounded_02(temperature);
        density_round = rounded_02(density);
        weight_round = rounded_02(weight);

        moisture_data = ((uint16_t)(moisture_round * 100));
        temperature_data = ((uint16_t)(temperature_round * 100));
        density_data = ((uint16_t)(density_round * 100));
        weight_data = ((uint16_t)(weight_round * 100));

        arr_data[0]   = ((temperature_data >> 8) & 0xFF);
        arr_data[1]   = (temperature_data ) & 0xFF;
        arr_data[2]   = ((weight_data >> 8) & 0xFF);
        arr_data[3]   = (weight_data ) & 0xFF;
        arr_data[4]   = ((moisture_data >> 8) & 0xFF);
        arr_data[5]   = (moisture_data ) & 0xFF;
        arr_data[6]   = ((density_data >> 8) & 0xFF);
        arr_data[7]   = (density_data ) & 0xFF;
        
        pMeasurementCharacteristic->setValue(arr_data, sizeof(arr_data));
        pMeasurementCharacteristic->notify();
        scale.power_up();
}
