//
//  game.h
//  
//
//  Created by Alejandro on 10/06/14.
//
//
#include "pebble.h"
#include "player.h"
#include "scores.h"
#include "box.h"
#include "Ubicua.h"

#ifndef _game_h
#define _game_h

static const int RESOURCE_FONDO = {
    RESOURCE_ID_IMAGE_ACTION_ICON_FONDO
};


Player *peter;
Box *box;
int boxes;
Scores *scores;
System window_struct;

GBitmap * imageFondo;
BitmapLayer *frameFondoLayout;


void initializeGame();
void displayGameWindow();
void deinitGame();
void gameOver();
void initGameWindow();
void initializeFondo();

#endif
