//
// Created by dillo on 3/6/2025.
//

#include "gameutil.h"
#include "../util/util.h"

void start_game(){
    setup();

    while(1) {
        #ifdef GAME_PRELOOP
            pre_loop();
        #endif
            update();
        #ifdef GAME_POSTLOOP
            pre_loop();
        #endif
    }
}

void c

void update(){
    if (update)
    {
        ecs_run_systems(ecs, ECS_SYSTEM_UPDATE);
    }
    if (render)
    {
        ecs_run_systems(ecs, ECS_SYSTEM_RENDER);
    }
}