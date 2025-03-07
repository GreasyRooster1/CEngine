//
// Created by dillo on 3/6/2025.
//

#include <stdio.h>
#include "gamesetup.h"
#include "gamestate.h"
#include "../renderer/renderer.h"
#include "../renderer/window.h"


void main_loop(GameState *state);
void check_state(GameState *state);

void start_game(){
    setup_renderer();
    GameState state = {
            true,true,NULL,NULL,
    };

    setup(&state);
    check_state(&state);

    while(is_window_alive(state.window)) {
        clear_window();

        #ifdef GAME_PRELOOP
            pre_loop(&state);
        #endif

        main_loop(&state);

        #ifdef GAME_POSTLOOP
            pre_loop(&state);
        #endif

        glfwSwapBuffers(state.window);
        glfwPollEvents();
    }
}

void check_state(GameState *state){
    if(state->ecs==NULL){
        printf("%s\n","ECS not passed to GameState... did you forget to initialize?");
        exit(-1);
    }
    if(state->window==NULL){
        printf("%s\n","window not passed to GameState... did you forget to initialize?");
        exit(-1);
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