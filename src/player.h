//
//  player_animations.h
//  
//
//  Created by Alejandro on 10/06/14.
//
//

#include "pebble.h"


#ifndef _player_h
#define _player_h


static const int RESOURCE_IDS_RUNNING[6] = {
    RESOURCE_ID_IMAGE_ACTION_ICON_MONIGOTE1,
    RESOURCE_ID_IMAGE_ACTION_ICON_MONIGOTE2,
    RESOURCE_ID_IMAGE_ACTION_ICON_MONIGOTE3,
    RESOURCE_ID_IMAGE_ACTION_ICON_MONIGOTE4,
    RESOURCE_ID_IMAGE_ACTION_ICON_MONIGOTE5,
    RESOURCE_ID_IMAGE_ACTION_ICON_MONIGOTE6
};

static const int RESOURCE_JUMPINGGUY = {
    RESOURCE_ID_IMAGE_ACTION_ICON_JUMPINGGUY
};

typedef struct{
    int id;
    int frame_number;
    GBitmap *image[6];
    BitmapLayer *frameLayout[6];
    int speed;
    bool continueRunning;
}Running;

typedef struct{
    int id;
    int frame_number;
    GBitmap *image[1];
    BitmapLayer *frameLayout[1];
    int jumpPixels;
    int speed;
    int cont;
    bool jumping;
    bool continueJumping;
}Jumping;


typedef struct{
    Running runningFrames; // Estructura de frames para cuando corre
    Jumping jumpingFrames; // Estructura de frames para cuando salta
    BitmapLayer *guy_container_layer; // BitmapLayer para el monigote
    GRect posGuy; // Tamanio y posicion del monigote
    GRect sizeGuy;
    int16_t crashFrom;
    int16_t crashTo;
}Player;



void initializeRunningFrames(Player * p);
void initializeJumpingFrames(Player * p);
void startRunningGuy();
void jumpGuy();
void stopAllAnimation();
void startAnimation(int i);
void initializePlayer(Player * p);
void up_click_jump_handler(ClickRecognizerRef recognizer, void *context) ;

#endif
