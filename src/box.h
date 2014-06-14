//
//  box.h
//  
//
//  Created by Alejandro on 10/06/14.
//
//

#include "pebble.h"
#include "player.h"

#ifndef _box_h
#define _box_h


static const int RESOURCE_BOX = {
    RESOURCE_ID_IMAGE_ACTION_ICON_BOX
};


typedef struct{
    BitmapLayer *box_container_layer;
    BitmapLayer *box_layer;
    GRect sizeBox;
    GRect sizeBoxContainerLayer;
    GBitmap * imageBox;
    int moveBox;
    int speedBox;
    int16_t crashYFrom;
    bool displayed;
}Box;

int lastDisplayed;
bool playBox;
bool animate;
int level;

void initializeBox(Box * b);
void animateBox();
void displayBox();
bool calculateCrash(GRect boxPos,int16_t );
void startDisplayingBox();
void stopDisplayingBox();
int randomMinMax(int min,int max);
int randomMax(int max);
void increaseLevel();
#endif
