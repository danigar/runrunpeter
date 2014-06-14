//
//  scores.c
//  
//
//  Created by Alejandro on 12/06/14.
//
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "scores.h"
#include "Ubicua.h"
#include "game.h"
#include "box.h"

void initializeScores(){
    scores = (Scores*) malloc(sizeof(Scores));
    scores->score = 0;
    scores->increase = 1;
    scores->speed = 1000;
    scores->count = 1;
    scores->score_layer = text_layer_create(GRect(5,5,50,50));
    final_score_layer = text_layer_create(GRect(70,80,30,30));
    app_timer_register(scores->speed,increaseScores,"pitos pitos");
    initWindowScores();
    APP_LOG(APP_LOG_LEVEL_DEBUG, "Initialized menu window");
}
void initWindowScores(){
    scores_activity.window = window_create();
    window_set_click_config_provider(scores_activity.window, scores_config_provider);
    scores_activity.window_layer  = window_get_root_layer(scores_activity.window); //obtains layer's dad app from main screen
    scores_activity.bounds = layer_get_bounds(scores_activity.window_layer); //obtains main layer's size
    scores_activity.frames = layer_get_frame(scores_activity.window_layer);
    scores_activity.bounds = GRect(0,0,144,168);
    imageScores = gbitmap_create_with_resource(RESOURCE_SCORES); //load an image in memory
    frameScoresLayout = bitmap_layer_create(scores_activity.bounds);
    bitmap_layer_set_bitmap(frameScoresLayout,imageScores);
    text_layer_set_text(final_score_layer,itoa(scores->score));
    layer_add_child(scores_activity.window_layer,bitmap_layer_get_layer(frameScoresLayout));
    layer_add_child(window_get_root_layer(scores_activity.window), text_layer_get_layer(final_score_layer));

}

void increaseScores(){
    if(scores->count == 1){
        scores->score += scores->increase;
        sawScore();
        app_timer_register(scores->speed,increaseScores,"pitos pitos");
    }
}
void stopScores(){
    scores->count = 0;
}


char *itoa(int num){
	static char buff[20] = {};
	int i = 0, temp_num = num, length = 0;
	char *string = buff;
	
	if(num >= 0) {
		// count how many characters in the number
		while(temp_num) {
			temp_num /= 10;
			length++;
		}
        length++;
		// assign the number to the buffer starting at the end of the
		// number and going to the begining since we are doing the
		// integer to character conversion on the last number in the
		// sequence
		for(i = 0; i < length; i++) {
		 	buff[(length-2)-i] = '0' + (num % 10);
			num /= 10;
		}
        buff[i-1] = 'M';
		buff[i] = '\0'; // can't forget the null byte to properly end our string
	}
	else
		return "Unsupported Number";
	
	return string;
}

void sawScore(){
    
    text_layer_set_text(scores->score_layer,itoa(scores->score));
    layer_add_child(window_get_root_layer(window_struct.window), text_layer_get_layer(scores->score_layer));
    
}

void sawFinalScore(){
    final_score_layer = text_layer_create(GRect(70,70,100,100));
}

void displayScoreWindow(){
    const bool animated = true;
    window_stack_push(scores_activity.window, animated);
    sawScore();
}
static void scoresActionButton(){
    window_stack_pop(true);
    initializeGame();
    displayGameWindow();
    
}
void scores_config_provider(void *context) {
    window_single_click_subscribe(BUTTON_ID_UP, scoresActionButton);
    window_single_click_subscribe(BUTTON_ID_BACK, quitApp);
}

