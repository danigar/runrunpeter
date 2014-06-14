//
//  Ubicua.h
//  
//
//  Created by Alejandro on 10/06/14.
//
//
#include "pebble.h"

#ifndef _Ubicua_h
#define _Ubicua_h


static Window *window;

typedef struct{
    Window *window;
    Layer *window_layer;
    GRect bounds;
    GRect frames;
    
}System;






//PRUEBA
static BitmapLayer *image_layer;
int varCompartida;



//quitar

void initializeApp();
void deinitObjects();
void quitApp();

#endif
