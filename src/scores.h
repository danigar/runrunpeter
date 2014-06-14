//
//  scores.h
//  
//
//  Created by Alejandro on 12/06/14.
//
//
#include "pebble.h"
#include "Ubicua.h"

#ifndef _scores_h
#define _scores_h

static const int RESOURCE_SCORES = {
    RESOURCE_ID_IMAGE_ACTION_ICON_FINAL
};

typedef struct{
    int score;
    int increase;
    int speed;
    bool count;
    TextLayer *score_layer;
}Scores;

Scores *scores;
System scores_activity;
GBitmap * imageScores;
BitmapLayer *frameScoresLayout;
TextLayer *final_score_layer;

void initializeScores();
void increaseScores();
void stopScores();
void sawScore();
void sawFinalScore();
char *itoa(int num);
void scores_config_provider(void *context);
void displayScoreWindow();
void initWindowScores();

#endif
