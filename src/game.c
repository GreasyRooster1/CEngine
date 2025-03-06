//
// Created by dillo on 3/6/2025.
//
#define ECS_IMPLEMENTATION
#include "util/util.h"

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
void
sprite_render_system(Ecs *ecs)
{
    for (u32 i = 0; i < ecs_for_count(ecs); i++)
    {
        EcsEnt e = ecs_get_ent(ecs, i);
        if (ecs_ent_has_mask(ecs, e, SPRITE_RENDER_SYSTEM_MASK))
        {
            CPosition *pos = ecs_ent_get_component(ecs, e, COMPONENT_POSITION);
            CSprite *sprite   = ecs_ent_get_component(ecs, e, COMPONENT_SPRITE);

            render_sprite(sprite->gl_id, sprite->rotation);
        }
    }
}