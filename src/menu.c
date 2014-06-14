//
//  menu.c
//  
//
//  Created by Alejandro on 14/06/14.
//
//

#include <stdio.h>
#include "menu.h"
#include "game.h"


void initMenuWindow(){
    
    menu_activity.window = window_create();
    window_set_click_config_provider(menu_activity.window, menu_config_provider);
    menu_activity.window_layer  = window_get_root_layer(menu_activity.window); //obtains layer's dad app from main screen
    menu_activity.bounds = layer_get_bounds(menu_activity.window_layer); //obtains main layer's size
    menu_activity.frames = layer_get_frame(menu_activity.window_layer);
    menu_activity.bounds = GRect(0,0,144,168);
    imageMenu = gbitmap_create_with_resource(RESOURCE_START_MENU); //load an image in memory
    frameMenuLayout = bitmap_layer_create(menu_activity.bounds);
    bitmap_layer_set_bitmap(frameMenuLayout,imageMenu);
    layer_add_child(menu_activity.window_layer,bitmap_layer_get_layer(frameMenuLayout));
    
}
void displayMenuWindow(){
    const bool animated = true;
    window_stack_push(menu_activity.window, animated);
}
static void menuActionButton(){
    initializeGame();
    displayGameWindow();
    window_stack_remove(menu_activity.window,true);
    window_destroy(menu_activity.window);
}
void menu_config_provider(void *context) {
    window_single_click_subscribe(BUTTON_ID_UP, menuActionButton);
}

