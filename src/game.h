//
// Created by dillo on 3/6/2025.
//

#ifndef CENGINE_GAME_H
#define CENGINE_GAME_H

#include "cengine/cengine.h"
#include "cengine/game/gamestate.h"
#include "cengine/util/types.h"

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
    COMPONENT_PLAYER,

    COMPONENT_COUNT
} ComponentType;

void setup(GameState *state);
void update(GameState *state);

//#define GAME_PRELOOP
//void pre_loop(GameState *state);
//#define GAME_POSTLOOP
//void post_loop(GameState *state);

#endif //CENGINE_GAME_H
