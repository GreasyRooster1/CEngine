//
// Created by dillo on 3/6/2025.
//

#include <stdio.h>
#include "gamesetup.h"
#include "gamestate.h"
#include "../renderer/renderer.h"
#include "../renderer/window.h"


void main_loop(GameState *state);

void start_game(){
    setup_renderer();
    GameState state = {
            true,true,NULL,create_window(),
    };
    setup(&state);

    if(state.ecs==NULL){
        printf("%s","ECS not passed to GameState... did you forget to initialize?");
    }

    while(is_window_alive(state.window)) {
        #ifdef GAME_PRELOOP
            pre_loop(&state);
        #endif
        main_loop(&state);
        #ifdef GAME_POSTLOOP
            pre_loop(&state);
        #endif
    }
}

void main_loop(GameState *state){
    if (state->updating)
    {
        ecs_run_systems(state->ecs, ECS_SYSTEM_UPDATE);
    }
    if (state->rendering)
    {
        ecs_run_systems(state->ecs, ECS_SYSTEM_RENDER);
    }
}

void cleanup_game(){
    cleanup_renderer();
}

void process_input(){

}