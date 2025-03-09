//
// Created by dillo on 3/7/2025.
//

#include <stdio.h>
#include "player.h"

#define PLAYER_MOVE_SYSTEM_MASK \
ECS_MASK(2, COMPONENT_PLAYER, COMPONENT_POSITION)
void player_move_system(Ecs *ecs,GameState *state){
    for (u32 i = 0; i < ecs_for_count(ecs); i++)
    {
        EcsEnt e = ecs_get_ent(ecs, i);
        if (ecs_ent_has_mask(ecs, e, PLAYER_MOVE_SYSTEM_MASK))
        {
            CPosition *pos = ecs_ent_get_component(ecs, e, COMPONENT_POSITION);

            if(check_key_pressed(state,GLFW_KEY_W)){
                pos->y-=3;
            }
        }
    }
}

EcsEnt new_player_arch(GameState *state){
    EcsEnt entity = ecs_ent_make(state->ecs);
    CPlayer cPlayer = {};
    CPosition cPosition = {0,0};
    CSprite cSprite = {0,0};
    //ecs_ent_add_component(state->ecs,entity,COMPONENT_PLAYER,&cPlayer);
    ecs_ent_add_component(state->ecs,entity,COMPONENT_POSITION,&cPosition);
    ecs_ent_add_component(state->ecs,entity,COMPONENT_SPRITE,&cSprite);
    return entity;
}