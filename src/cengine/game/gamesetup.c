//
// Created by dillo on 3/6/2025.
//

#include <stdio.h>
#include "gamesetup.h"
#include "gamestate.h"
#include "../renderer/renderer.h"
#include "../renderer/window.h"
#include "input.h"

void check_state(GameState *state);
void cleanup_game(GameState *state);
void process_input(GLFWwindow *window);

void start_game(){
    setup_renderer();
    GameState state = {
            true,true,NULL,NULL,create_input_state()
    };

    setup(&state);
    check_state(&state);

    glfwSetKeyCallback(state.window, key_callback);
    while(is_window_alive(state.window)) {
        clear_window();

        #ifdef GAME_PRELOOP
            pre_loop(&state);
        #endif

        if (state.updating)
        {
            ecs_run_systems(state.ecs, ECS_SYSTEM_UPDATE,&state);
        }
        if (state.rendering)
        {
            ecs_run_systems(state.ecs, ECS_SYSTEM_RENDER,&state);
        }

        #ifdef GAME_POSTLOOP
            pre_loop(&state);
        #endif

        glfwSwapBuffers(state.window);
        glfwPollEvents();
    }

    cleanup_game(&state);
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

void cleanup_game(GameState *state){
    cleanup_renderer();
}