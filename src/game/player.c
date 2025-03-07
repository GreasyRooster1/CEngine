//
// Created by dillo on 3/7/2025.
//

#include "player.h"
#include "../cengine/cengine.h"

#define PLAYER_MOVE_SYSTEM_MASK \
ECS_MASK(2, COMPONENT_PLAYER, COMPONENT_POSITION)
void player_move_system(Ecs *ecs){
    for (u32 i = 0; i < ecs_for_count(ecs); i++)
    {
        EcsEnt e = ecs_get_ent(ecs, i);
        if (ecs_ent_has_mask(ecs, e, PLAYER_MOVE_SYSTEM_MASK))
        {
            CPosition *pos = ecs_ent_get_component(ecs, e, COMPONENT_POSITION);

            check_key_pressed();
        }
    }
}