// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.0
// LVGL version: 8.3.6
// Project name: SquareLine_Project

#include "../ui.h"

// COMPONENT Test

lv_obj_t * ui_Test_create(lv_obj_t * comp_parent)
{

    lv_obj_t * cui_Test;
    cui_Test = lv_obj_create(comp_parent);
    lv_obj_set_width(cui_Test, 100);
    lv_obj_set_height(cui_Test, 50);
    lv_obj_set_x(cui_Test, -83);
    lv_obj_set_y(cui_Test, -58);
    lv_obj_set_align(cui_Test, LV_ALIGN_CENTER);
    lv_obj_clear_flag(cui_Test, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_t ** children = lv_mem_alloc(sizeof(lv_obj_t *) * _UI_COMP_TEST_NUM);
    children[UI_COMP_TEST_TEST] = cui_Test;
    lv_obj_add_event_cb(cui_Test, get_component_child_event_cb, LV_EVENT_GET_COMP_CHILD, children);
    lv_obj_add_event_cb(cui_Test, del_component_child_event_cb, LV_EVENT_DELETE, children);
    ui_comp_Test_create_hook(cui_Test);
    return cui_Test;
}

