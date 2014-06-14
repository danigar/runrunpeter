//
//  player_animations.c
//  
//
//  Created by Alejandro on 10/06/14.
//
//

#include "player.h"
#include "Ubicua.h"
#include "game.h"


void initializePlayer(Player * p){
    // p->sizeGuyContainerLayer = GRect(10,window_struct.frames.size.h/2 + 30,window_struct.frames.size.w,window_struct.frames.size.h);
    p->posGuy = GRect(25,window_struct.frames.size.h/2 + 30,33,47);
    p->sizeGuy = GRect(0,0,33,47);
    p->crashFrom = p->posGuy.origin.x;
    p->crashTo = (p->posGuy.origin.x + p->posGuy.size.w) - 10;
    p->guy_container_layer = bitmap_layer_create(p->posGuy);
    bitmap_layer_set_alignment( p->guy_container_layer, GAlignBottom);
    initializeRunningFrames(p);
    initializeJumpingFrames(p);
    layer_add_child(window_struct.window_layer, bitmap_layer_get_layer(p->guy_container_layer));
}

void initializeRunningFrames(Player * p){
    p->runningFrames.id = 0;
    p->runningFrames.frame_number = 0;
    for( int i = 0 ; i < 6 ; i ++){
        p->runningFrames.image[i] = gbitmap_create_with_resource(RESOURCE_IDS_RUNNING[i]); //load an image in memory
        p->runningFrames.frameLayout[i] = bitmap_layer_create(p->sizeGuy); //initialize bitmap layer with size
        bitmap_layer_set_alignment(p->runningFrames.frameLayout[i], GAlignBottom);
        bitmap_layer_set_bitmap(p->runningFrames.frameLayout[i],p->runningFrames.image[i]); //create an image within a bitmap layer
    }
    p->runningFrames.speed = 150;
    p->runningFrames.continueRunning = true;
    
}

void initializeJumpingFrames(Player * p){
    p->jumpingFrames.id = 1;
    p->jumpingFrames.frame_number = 0;
    int i = 0;
    //for( int i = 0 ; i < 6 ; i ++){
    p->jumpingFrames.image[i] = gbitmap_create_with_resource(RESOURCE_JUMPINGGUY); //load an image in memory
    p->jumpingFrames.frameLayout[i] = bitmap_layer_create(p->sizeGuy); //initialize bitmap layer with size
    bitmap_layer_set_alignment(p->jumpingFrames.frameLayout[i], GAlignBottom);
    bitmap_layer_set_bitmap(p->jumpingFrames.frameLayout[i],p->jumpingFrames.image[i]); //create an image within a bitmap layer
    // }
    p->jumpingFrames.speed = 90;
    p->jumpingFrames.cont = 0;
    p->jumpingFrames.jumpPixels = 3;
    p->jumpingFrames.jumping = 0;
    p->jumpingFrames.continueJumping = true;
    
}

void startAnimation(int i){
    switch(i){
        case 0:// peter->runningFrames.id:
            peter->runningFrames.continueRunning = true;
            startRunningGuy();
            break;
        case 1://peter->jumpingFrames.id:
            peter->runningFrames.continueRunning = false;
            jumpGuy();
            break;
    }
}
void stopAllAnimation(){
    peter->runningFrames.continueRunning = false;
    peter->jumpingFrames.continueJumping = false;
    playBox = 0;
}


void startRunningGuy(){
    if( peter->runningFrames.continueRunning){
        int frame_prev = (peter->runningFrames.frame_number - 1) % 5; //choses which frame we are loading
        layer_remove_child_layers(bitmap_layer_get_layer(peter->runningFrames.frameLayout[frame_prev])); //removes child's
        layer_add_child(bitmap_layer_get_layer(peter->guy_container_layer), bitmap_layer_get_layer(peter->runningFrames.frameLayout[peter->runningFrames.frame_number])); //add next image
        peter->runningFrames.frame_number = (peter->runningFrames.frame_number + 1) % 5; //change frame
        app_timer_register(peter->runningFrames.speed
                           ,startRunningGuy,"pitos pitos");
    }
}

void jumpGuy(){
    if(peter->jumpingFrames.continueJumping){
        int valor = 0;
        int cont = peter->jumpingFrames.cont;
        int posX = peter->posGuy.origin.x;
        int posY = peter->posGuy.origin.y;
        int width = peter->posGuy.size.w;
        int height = peter->posGuy.size.h;
        if(cont < 5 ){
            valor = (cont + 1 )* peter->jumpingFrames.jumpPixels;
            posY -= valor;
            if( cont == 0){
                int frame_prev = (peter->runningFrames.frame_number - 1) % 5; //choses which frame we are loading
                layer_remove_child_layers(bitmap_layer_get_layer(peter->runningFrames.frameLayout[frame_prev])); //removes child's
                layer_set_frame(bitmap_layer_get_layer(peter->guy_container_layer),GRect(posX,posY,width,height));
                layer_add_child(bitmap_layer_get_layer(peter->guy_container_layer), bitmap_layer_get_layer(peter->jumpingFrames.frameLayout[0]));//cambiar
            }else{
                layer_set_frame(bitmap_layer_get_layer(peter->guy_container_layer),GRect(posX,posY,width,height));
            }
            peter->posGuy = GRect(posX,posY,width,height);
            peter->jumpingFrames.cont++;
            app_timer_register(peter->jumpingFrames.speed,jumpGuy,"pitos pitos");
        }else{
            if(cont >= 5 && cont <= 10){
                valor = ( (cont+1) % 6) * peter->jumpingFrames.jumpPixels;
                posY += valor;
                layer_set_frame(bitmap_layer_get_layer(peter->guy_container_layer),GRect(posX,posY,width,height));
                peter->jumpingFrames.cont++;
                peter->posGuy = GRect(posX,posY,width,height);
                app_timer_register(peter->jumpingFrames.speed,jumpGuy,"pitos pitos");
            }
            else{
                peter->jumpingFrames.cont = 0;
                startAnimation(peter->runningFrames.id);
                peter->jumpingFrames.jumping = 0;
            }
        }
    }
}
void up_click_jump_handler(ClickRecognizerRef recognizer, void *context) {
    if( !peter->jumpingFrames.jumping ){
        peter->jumpingFrames.jumping = 1;
        startAnimation(peter->jumpingFrames.id);
    }
}


