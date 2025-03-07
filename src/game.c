//
// Created by dillo on 3/6/2025.
//
#define ECS_IMPLEMENTATION
#include "cengine.h"

typedef struct
{
    float x, y;
} CPosition;

typedef struct
{
    float dx, dy;
} CVelocity;

typedef struct
{
    u32 gl_id;
    float rotation;
} CSprite;

typedef enum
{
    COMPONENT_POSITION,
    COMPONENT_VELOCITY,
    COMPONENT_SPRITE,

    COMPONENT_COUNT
} ComponentType;

#define MOVEMENT_SYSTEM_MASK \
ECS_MASK(2, COMPONENT_POSITION, COMPONENT_VELOCITY)
void apply_velocity_system(Ecs *ecs){
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
void sprite_render_system(Ecs *ecs){
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
}

void register_systems(Ecs *ecs){
    //ecs_run_systems will run the systems in the order they are registered
    //ecs_run_system is also available if you wish to handle each system seperately
    //
    //Ecs, function pointer to system (must take a parameter of Ecs), system type
    ecs_register_system(ecs, apply_velocity_system, ECS_SYSTEM_UPDATE);
    ecs_register_system(ecs, sprite_render_system, ECS_SYSTEM_RENDER);
}

void setup(GameState *state){
    Ecs *ecs = ecs_make(1000, COMPONENT_COUNT, 3);
    register_components(ecs);
    register_systems(ecs);

    EcsEnt e = ecs_ent_make(ecs);
    CPosition xform = {0, 0};
    CVelocity velocity = {5, 0};
    ecs_ent_add_component(ecs, e, COMPONENT_POSITION, &xform);
    ecs_ent_add_component(ecs, e, COMPONENT_VELOCITY, &velocity);

    state->ecs = ecs;
    state->window = create_window(SCR_WIDTH,SCR_HEIGHT);
}

void update(GameState *state){

}

void pre_loop(GameState *state){

}

void post_loop(GameState *state){

}