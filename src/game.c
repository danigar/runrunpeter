//
//  game.c
//  
//
//  Created by Alejandro on 10/06/14.
//
//

#include "game.h"


static void game_config_provider(void *context) {
    window_single_click_subscribe(BUTTON_ID_UP, up_click_jump_handler);
}

void initializeGame(){
    initGameWindow();
    peter = (Player*) malloc(sizeof(Player));
    box = (Box*) malloc(sizeof(Box));
    initializePlayer(peter);
    initializeBox(box);
    startRunningGuy();
    initializeScores();
}
void initGameWindow(){
    window_struct.window = window_create();
    window_struct.window_layer  = window_get_root_layer(window_struct.window); //obtains layer's dad app from main screen
    window_struct.bounds = layer_get_bounds(window_struct.window_layer); //obtains main layer's size
    window_struct.frames = layer_get_frame(window_struct.window_layer);  //obtains main layer's
    window_set_click_config_provider(window_struct.window, game_config_provider);
    app_timer_register(2000,startDisplayingBox,"pitos pitos");
}


void gameOver(){
    stopAllAnimation();
    stopScores();
    stopDisplayingBox();
    deinitGame();
    displayScoreWindow();
}

void deinitGame(){
    layer_destroy(bitmap_layer_get_layer(peter->guy_container_layer));
    layer_destroy(bitmap_layer_get_layer(peter->jumpingFrames.frameLayout[0]));
    gbitmap_destroy(peter->jumpingFrames.image[0]);
    for( int i = 0; i < 6; i++){
        layer_destroy(bitmap_layer_get_layer(peter->runningFrames.frameLayout[i]));
        gbitmap_destroy(peter->runningFrames.image[i]);
    }
    
    layer_destroy(bitmap_layer_get_layer(box->box_container_layer));
    layer_destroy(bitmap_layer_get_layer(box->box_layer));
    window_stack_remove(window_struct.window, true);
    window_destroy(window_struct.window);
    free(peter);
    free(box);
    free(scores);
}
void displayGameWindow(){
    const bool animated = true;
    window_stack_push(window_struct.window, animated);
}

