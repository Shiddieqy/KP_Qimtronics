void update_data(){
      if (millis() - tim > 500){
        sensor_sampling();
        sprintf(Moisture, "%.1f%%", moisture);
        sprintf(Temperature, "%.1f", temperature);
        sprintf(Density, "%.1f", density);
        lv_arc_set_value(ui_MoistArc, int(moisture));
        lv_textarea_set_text(ui_Moisture, Moisture);
        lv_textarea_set_text(ui_Temp, Temperature);
        lv_textarea_set_text(ui_Density, Density);
        tim = millis();
    }
}
