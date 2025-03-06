//
// Created by dillo on 3/5/2025.
//

#ifndef CENGINE_ECS_H
#define CENGINE_ECS_H

#include "util/util.h"

#define MAX_ENTITIES 100

struct Ecs{

};

typedef enum {
    ECS_SYSTEM_UPDATE,
    ECS_SYSTEM_DRAW,
} EcsSystemType;

typedef int Entity;

struct CPosition{
    f32 x;
    f32 y;
};

#endif //CENGINE_ECS_H
