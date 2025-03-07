//
// Created by QuantumDeity on 3/6/2025.
//

#ifndef CENGINE_ECSTYPES_H
#define CENGINE_ECSTYPES_H

typedef uint64_t EcsEnt;
typedef uint32_t EcsComponentType;

#define ECS_MASK(ctypes_count, ...) \
    ctypes_count, (EcsComponentType[]){__VA_ARGS__}

typedef enum
{
    ECS_SYSTEM_UPDATE,
    ECS_SYSTEM_RENDER
} EcsSystemType;

typedef struct Ecs Ecs;

typedef void (*ecs_system_func)(struct Ecs *ecs);
typedef void (*ecs_component_destroy)(void *data);

#endif //CENGINE_ECSTYPES_H
