//
//  box.c
//  
//
//  Created by Alejandro on 10/06/14.
//
//

#include "box.h"
#include "Ubicua.h"
#include "game.h"
#include <stdlib.h>


int randomMax(int max){
    int n=-1;
    while(n<0){
    n = rand()%max;
    }
    return n;
}
int randomMinMax(int min,int max){
    int n=-1;
    while(n<0){
        n = rand()%max;
    }
    if( n < min){
        n = min;
    }
    return n;
}

void initializeBox(Box * b){
    b->sizeBox = GRect(window_struct.frames.size.w-10,window_struct.frames.size.h-15,15,15);
    b->sizeBoxContainerLayer = GRect(window_struct.frames.size.w,window_struct.frames.size.h,window_struct.frames.size.w,window_struct.frames.size.h);
    b->box_container_layer = bitmap_layer_create(b->sizeBoxContainerLayer);
    b->box_layer = bitmap_layer_create(b->sizeBox);
    bitmap_layer_set_alignment(b->box_container_layer, GAlignBottom);
    b->imageBox = gbitmap_create_with_resource(RESOURCE_BOX);
    bitmap_layer_set_bitmap(b->box_layer, b->imageBox);
    layer_add_child(window_struct.window_layer, bitmap_layer_get_layer(b->box_container_layer));
    layer_add_child(window_struct.window_layer, bitmap_layer_get_layer(b->box_layer));
    b->moveBox = 5;
    b->speedBox = 50;
    b->crashYFrom = b->sizeBox.origin.y;
    b->displayed = 0;
    layer_set_hidden(bitmap_layer_get_layer(b->box_layer),true);
    lastDisplayed = 0;
    playBox = 1;
    animate = 0;
    level = 1;
    
}
void animateBox(){
    int indice = 0;
    if( playBox){
     //   for( int indice = 0; indice < 3 ; indice++){
            if(box->displayed==1){
                int valor = 0;
                int posX = box->sizeBox.origin.x;
                int posY = box->sizeBox.origin.y;
                int width = box->sizeBox.size.w;
                int height = box->sizeBox.size.h;
                if(posX >  0 ){
                    valor += box->moveBox;
                    posX -= valor;
                    layer_set_frame(bitmap_layer_get_layer(box->box_layer),GRect(posX,posY,width,height));
                    box->sizeBox = GRect(posX,posY,width,height);
                    bool crash = calculateCrash(box->sizeBox,box->crashYFrom);
                    app_timer_register(box->speedBox,animateBox,"pitos pitos");
                }else{
                    layer_set_hidden(bitmap_layer_get_layer(box->box_layer),true);
                    box->displayed = 0;
                    displayBox(0);
                    app_timer_register(box->speedBox,animateBox,"pitos pitos");
                }
            }
      //  }
    }
}

void startDisplayingBox(){
    displayBox(0);
    if(animate==0){
        animateBox();
        app_timer_register(15000,increaseLevel,"pitos pitos");
        animate = 1;
    }
}
void increaseLevel(){
    if(level < 7){
        int augmentSpeed = box->speedBox - (level + 2);
        //int augmentMove = box->moveBox + level;
        box->speedBox = augmentSpeed;
       // box->moveBox = augmentMove;
        level++;
    }
    app_timer_register(10000,increaseLevel,"pitos pitos");
    
}
void stopDisplayingBox(){
    playBox = 0;
    animate = 0;
}
void displayBox(int i){
    box->sizeBox = GRect(window_struct.frames.size.w-10,window_struct.frames.size.h-15,15,15);
    layer_set_hidden(bitmap_layer_get_layer(box->box_layer),false);
    box->displayed = 1;
}

bool calculateCrash(GRect boxPos,int16_t crashFromBox){
    bool resul = false;
    
    if(peter->crashFrom <= boxPos.origin.x + boxPos.size.w && peter->crashTo >= boxPos.origin.x){ //Si estamos en la zona crítica
        if(peter->posGuy.origin.y + peter->posGuy.size.h >= crashFromBox){
            //layer_set_hidden(bitmap_layer_get_layer(box->box_layer),true);
            gameOver();
        }
        
        
    }
    
    return resul;
}