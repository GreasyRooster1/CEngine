//
// Created by dillo on 3/6/2025.
//

#ifndef CENGINE_GAMESTATE_H
#define CENGINE_GAMESTATE_H

#include <stdbool.h>
#include "ecs.h"

typedef struct{
    bool updating;
    bool rendering;
    Ecs *ecs;
} GameState;

#endif //CENGINE_GAMESTATE_H
