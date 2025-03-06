//
// Created by dillo on 3/5/2025.
//

#ifndef CENGINE_ECS_H
#define CENGINE_ECS_H

#include <stdio.h>
#include "util/util.h"

#define MAX_ENTITIES 100

struct Ecs{

};

typedef enum {
    ECS_SYSTEM_UPDATE,
    ECS_SYSTEM_DRAW,
} EcsSystemType;

typedef int Entity;

typedef struct {
    Entity e;
    UT_hash_handle hh;
}CGeneric;

typedef struct {
    Entity e;
    UT_hash_handle hh;

    f32 x;
    f32 y;
} CPosition;
typedef struct {
    Entity e;
    UT_hash_handle hh;

    f32 x;
    f32 y;
}CVelocity;

enum ComponentType{
    COMPONENT_POSITION,
    COMPONENT_VELOCITY,
};

CPosition *position_map;

void* add_component(Entity e,enum ComponentType type,int size);
void get_component(Entity e);

#endif //CENGINE_ECS_H
