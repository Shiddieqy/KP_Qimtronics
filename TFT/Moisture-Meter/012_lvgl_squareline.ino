
void ui_Screen1_screen_init(void)
{
    ui_Screen1 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Screen1, lv_color_hex(0x090329), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Screen1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel1 = lv_obj_create(ui_Screen1);
    lv_obj_set_width(ui_Panel1, 76);
    lv_obj_set_height(ui_Panel1, 43);
    lv_obj_set_x(ui_Panel1, -56);
    lv_obj_set_y(ui_Panel1, 18);
    lv_obj_set_align(ui_Panel1, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Panel1, lv_color_hex(0x94AEB4), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Panel1, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Density = lv_textarea_create(ui_Screen1);
    lv_obj_set_width(ui_Density, 54);
    lv_obj_set_height(ui_Density, 43);
    lv_obj_set_x(ui_Density, -84);
    lv_obj_set_y(ui_Density, 18);
    lv_obj_set_align(ui_Density, LV_ALIGN_CENTER);
    lv_textarea_set_text(ui_Density, "122");
    lv_textarea_set_placeholder_text(ui_Density, "Placeholder...");
    lv_obj_set_style_text_color(ui_Density, lv_color_hex(0x0078FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Density, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_Density, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_decor(ui_Density, LV_TEXT_DECOR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Density, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Density, lv_color_hex(0x97AEB3), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Density, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Density, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_text_color(ui_Density, lv_color_hex(0x808080), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Density, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_Density, LV_TEXT_ALIGN_CENTER, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Density, &lv_font_montserrat_16, LV_PART_SELECTED | LV_STATE_DEFAULT);

    lv_obj_set_style_text_color(ui_Density, lv_color_hex(0x808080), LV_PART_TEXTAREA_PLACEHOLDER | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Density, 255, LV_PART_TEXTAREA_PLACEHOLDER | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_Density, LV_TEXT_ALIGN_CENTER, LV_PART_TEXTAREA_PLACEHOLDER | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Density, &lv_font_montserrat_16, LV_PART_TEXTAREA_PLACEHOLDER | LV_STATE_DEFAULT);

    ui_Panel2 = lv_obj_create(ui_Screen1);
    lv_obj_set_width(ui_Panel2, 104);
    lv_obj_set_height(ui_Panel2, 100);
    lv_obj_set_x(ui_Panel2, 0);
    lv_obj_set_y(ui_Panel2, -63);
    lv_obj_set_align(ui_Panel2, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Panel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Panel2, lv_color_hex(0x94AEB4), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Panel2, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Moisture = lv_textarea_create(ui_Panel2);
    lv_obj_set_width(ui_Moisture, 85);
    lv_obj_set_height(ui_Moisture, 47);
    lv_obj_set_x(ui_Moisture, 2);
    lv_obj_set_y(ui_Moisture, 5);
    lv_obj_set_align(ui_Moisture, LV_ALIGN_CENTER);
    lv_textarea_set_text(ui_Moisture, "20.1%");
    lv_textarea_set_placeholder_text(ui_Moisture, "Placeholder...");
    lv_textarea_set_one_line(ui_Moisture, true);
    lv_obj_set_style_text_color(ui_Moisture, lv_color_hex(0x0078FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Moisture, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_Moisture, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_decor(ui_Moisture, LV_TEXT_DECOR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Moisture, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_Moisture, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Moisture, lv_color_hex(0x97AEB3), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Moisture, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Moisture, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_text_color(ui_Moisture, lv_color_hex(0x808080), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Moisture, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_Moisture, LV_TEXT_ALIGN_CENTER, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Moisture, &lv_font_montserrat_16, LV_PART_SELECTED | LV_STATE_DEFAULT);

    lv_obj_set_style_text_color(ui_Moisture, lv_color_hex(0x808080), LV_PART_TEXTAREA_PLACEHOLDER | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Moisture, 255, LV_PART_TEXTAREA_PLACEHOLDER | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_Moisture, LV_TEXT_ALIGN_CENTER, LV_PART_TEXTAREA_PLACEHOLDER | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Moisture, &lv_font_montserrat_16, LV_PART_TEXTAREA_PLACEHOLDER | LV_STATE_DEFAULT);

    ui_MoistArc = lv_arc_create(ui_Panel2);
    lv_obj_set_width(ui_MoistArc, 104);
    lv_obj_set_height(ui_MoistArc, 150);
    lv_obj_set_x(ui_MoistArc, 0);
    lv_obj_set_y(ui_MoistArc, 25);
    lv_obj_set_align(ui_MoistArc, LV_ALIGN_CENTER);
    lv_arc_set_value(ui_MoistArc, 90);

    lv_obj_set_style_opa(ui_MoistArc, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_Label2 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Label2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label2, -47);
    lv_obj_set_y(ui_Label2, 17);
    lv_obj_set_align(ui_Label2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label2, "g/cm");
    lv_obj_set_style_text_color(ui_Label2, lv_color_hex(0x0073FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label1 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Label1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label1, -26);
    lv_obj_set_y(ui_Label1, 8);
    lv_obj_set_align(ui_Label1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label1, "3");
    lv_obj_set_style_text_color(ui_Label1, lv_color_hex(0x0879FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label1, &lv_font_montserrat_8, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Temp = lv_textarea_create(ui_Screen1);
    lv_obj_set_width(ui_Temp, 82);
    lv_obj_set_height(ui_Temp, 43);
    lv_obj_set_x(ui_Temp, 70);
    lv_obj_set_y(ui_Temp, 19);
    lv_obj_set_align(ui_Temp, LV_ALIGN_CENTER);
    lv_textarea_set_text(ui_Temp, "20.5");
    lv_textarea_set_placeholder_text(ui_Temp, "Placeholder...");
    lv_obj_set_style_text_color(ui_Temp, lv_color_hex(0x0078FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Temp, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_Temp, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_decor(ui_Temp, LV_TEXT_DECOR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Temp, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Temp, lv_color_hex(0x97AEB3), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Temp, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Temp, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_text_color(ui_Temp, lv_color_hex(0x808080), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Temp, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_Temp, LV_TEXT_ALIGN_CENTER, LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Temp, &lv_font_montserrat_16, LV_PART_SELECTED | LV_STATE_DEFAULT);

    lv_obj_set_style_text_color(ui_Temp, lv_color_hex(0x808080), LV_PART_TEXTAREA_PLACEHOLDER | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Temp, 255, LV_PART_TEXTAREA_PLACEHOLDER | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_Temp, LV_TEXT_ALIGN_CENTER, LV_PART_TEXTAREA_PLACEHOLDER | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Temp, &lv_font_montserrat_16, LV_PART_TEXTAREA_PLACEHOLDER | LV_STATE_DEFAULT);

    ui_Label3 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Label3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label3, 94);
    lv_obj_set_y(ui_Label3, 8);
    lv_obj_set_align(ui_Label3, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label3, "o");
    lv_obj_set_style_text_color(ui_Label3, lv_color_hex(0x0879FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label3, &lv_font_montserrat_8, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button2 = lv_btn_create(ui_Screen1);
    lv_obj_set_width(ui_Button2, 95);
    lv_obj_set_height(ui_Button2, 50);
    lv_obj_set_x(ui_Button2, -65);
    lv_obj_set_y(ui_Button2, 80);
    lv_obj_set_align(ui_Button2, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Button2, 100, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button1 = lv_btn_create(ui_Screen1);
    lv_obj_set_width(ui_Button1, 95);
    lv_obj_set_height(ui_Button1, 50);
    lv_obj_set_x(ui_Button1, 66);
    lv_obj_set_y(ui_Button1, 80);
    lv_obj_set_align(ui_Button1, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Button1, 100, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label5 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Label5, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label5, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label5, -64);
    lv_obj_set_y(ui_Label5, 80);
    lv_obj_set_align(ui_Label5, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label5, "Measure");
    lv_obj_set_style_text_color(ui_Label5, lv_color_hex(0xC0D5EE), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label4 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Label4, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label4, 66);
    lv_obj_set_y(ui_Label4, 80);
    lv_obj_set_align(ui_Label4, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label4, "Tare");
    lv_obj_set_style_text_color(ui_Label4, lv_color_hex(0xC0D5EE), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label6 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Label6, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label6, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label6, 0);
    lv_obj_set_y(ui_Label6, -129);
    lv_obj_set_align(ui_Label6, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label6, "Coffe Moisture Meter");
    lv_obj_set_style_text_color(ui_Label6, lv_color_hex(0x94AEB4), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_Label6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_decor(ui_Label6, LV_TEXT_DECOR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label6, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

}
void ui_init(void)
{
//    LV_EVENT_GET_COMP_CHILD = lv_event_register_id();

    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Screen1_screen_init();
//    ui_Screen2_screen_init();
    ui____initial_actions0 = lv_obj_create(NULL);
    lv_disp_load_scr(ui_Screen1);
}
