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

Player *peter;
Box *box;
int boxes;
Scores *scores;
System window_struct;

void initializeGame();
void displayGameWindow();
void deinitGame();
void gameOver();
void initGameWindow();

#endif
