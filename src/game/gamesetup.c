//
// Created by dillo on 3/6/2025.
//

#include <stdio.h>
#include "gamesetup.h"
#include "../util/util.h"
#include "gamestate.h"



void start_game(){
    GameState state = {
            true,true,NULL
    };
    setup(&state);

    if(state.ecs==NULL){
        printf("%s","ECS not passed to GameState... did you forget to initialize?");
    }

    while(1) {
        #ifdef GAME_PRELOOP
            pre_loop(&state);
        #endif
        #ifdef GAME_UPDATE
            update();
        #endif
        #ifdef GAME_POSTLOOP
            pre_loop(&state);
        #endif
    }
}

void update(GameState *state){
    if (state->updating)
    {
        ecs_run_systems(state->ecs, ECS_SYSTEM_UPDATE);
    }
    if (state->rendering)
    {
        ecs_run_systems(state->ecs, ECS_SYSTEM_RENDER);
    }
}