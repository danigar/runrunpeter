//
//  menu.h
//  
//
//  Created by Alejandro on 14/06/14.
//
//
#include "pebble.h"
#include "Ubicua.h"

#ifndef _menu_h
#define _menu_h


static const int RESOURCE_START_MENU = {
    RESOURCE_ID_IMAGE_ACTION_ICON_START
};

System menu_activity;
GBitmap * imageMenu;
BitmapLayer *frameMenuLayout;

void initMenuWindow();
void displayMenuWindow();
void menu_config_provider();

#endif
