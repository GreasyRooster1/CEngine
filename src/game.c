//
// Created by dillo on 3/6/2025.
//
#define ECS_IMPLEMENTATION
#include "cengine/cengine.h"
#include "game/player.h"


#define MOVEMENT_SYSTEM_MASK \
ECS_MASK(2, COMPONENT_POSITION, COMPONENT_VELOCITY)
void apply_velocity_system(Ecs *ecs,GameState *state){
    for (u32 i = 0; i < ecs_for_count(ecs); i++)
    {
        EcsEnt e = ecs_get_ent(ecs, i);
        if (ecs_ent_has_mask(ecs, e, MOVEMENT_SYSTEM_MASK))
        {
            CPosition *pos   = ecs_ent_get_component(ecs, e, COMPONENT_POSITION);
            CVelocity *velocity = ecs_ent_get_component(ecs, e, COMPONENT_VELOCITY);

            pos->x += velocity->dx;
            pos->y += velocity->dy;
        }
    }
}

#define SPRITE_RENDER_SYSTEM_MASK \
ECS_MASK(2, COMPONENT_POSITION, COMPONENT_SPRITE)
void sprite_render_system(Ecs *ecs,GameState *state){
    for (u32 i = 0; i < ecs_for_count(ecs); i++)
    {
        EcsEnt e = ecs_get_ent(ecs, i);
        if (ecs_ent_has_mask(ecs, e, SPRITE_RENDER_SYSTEM_MASK))
        {
            CPosition *pos = ecs_ent_get_component(ecs, e, COMPONENT_POSITION);
            CSprite *sprite   = ecs_ent_get_component(ecs, e, COMPONENT_SPRITE);
            //render_sprite(sprite->gl_id, sprite->rotation);
        }
    }
}


void register_components(Ecs *ecs){
    //Ecs, component index, component pool size, size of component, and component free func
    ecs_register_component(ecs, COMPONENT_POSITION, 1000, sizeof(CPosition), NULL);
    ecs_register_component(ecs, COMPONENT_VELOCITY, 200, sizeof(CVelocity), NULL);
    ecs_register_component(ecs, COMPONENT_SPRITE, 1000, sizeof(CSprite), NULL);
    ecs_register_component(ecs, COMPONENT_PLAYER, 1, sizeof(CPlayer), NULL);

}

void register_systems(Ecs *ecs){
    //Systems are run in order
    ecs_register_system(ecs, player_move_system, ECS_SYSTEM_UPDATE);
    ecs_register_system(ecs, apply_velocity_system, ECS_SYSTEM_UPDATE);
    ecs_register_system(ecs, sprite_render_system, ECS_SYSTEM_RENDER);
}

void setup(GameState *state){
    Ecs *ecs = ecs_make(1000, COMPONENT_COUNT, 3);
    register_components(ecs);
    register_systems(ecs);

    state->ecs = ecs;
    state->window = create_window(800,600);

    //new_player_arch(state);
}

void processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}