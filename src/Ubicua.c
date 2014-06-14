#include "pebble.h"
#include "Ubicua.h"
#include "menu.h"
//PROYECTO
//RUN RUN PETER









void initializeApp(){
    APP_LOG(APP_LOG_LEVEL_DEBUG, "Initializing app");
   /* window_struct.window_layer  = window_get_root_layer(window_struct.window); //obtains layer's dad app from main screen
    window_struct.bounds = layer_get_bounds(window_struct.window_layer); //obtains main layer's size
    window_struct.frames = layer_get_frame(window_struct.window_layer);  //obtains main layer's size*/

}



static void init(void) {
  /*window_struct.window = window_create();
  window_set_click_config_provider(window_struct.window, click_config_provider);
  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });
  const bool animated = true;
  window_stack_push(window_struct.window, animated);
  APP_LOG(APP_LOG_LEVEL_DEBUG, "Initialized app");
   */
    initMenuWindow();
    displayMenuWindow();
}


static void deinit(void){
    /*for( int i = 0 ; i < 6 ; i ++){
       gbitmap_destroy(frame->image[i]); // cambiar si peta
    }*/
    //window_destroy(window_struct.window);
}
void quitApp(){
    window_stack_pop_all(true);
}

int main(void) {
    init();
    initializeApp();
    
    //initializeFrame();
    
    app_event_loop();
    
    deinit();
    

}
