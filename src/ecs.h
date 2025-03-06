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

typedef struct {
    Entity e;
}CGeneric;

typedef struct {
    Entity e;
    f32 x;
    f32 y;
} CPosition;
typedef struct {
    Entity e;
    f32 x;
    f32 y;
}CVelocity;

enum ComponentType{
    COMPONENT_POSITION,
    COMPONENT_VELOCITY,
};

CGeneric* add_component(Entity e,enum ComponentType type,int size){
    CGeneric *comp = malloc(size);
    comp->e=e;
    return comp;
}

#endif //CENGINE_ECS_H
