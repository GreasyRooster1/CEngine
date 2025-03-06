#include "util/util.h"
#include "ecs.h"

CGeneric* add_component(Entity e,enum ComponentType type,int size){
    CGeneric *comp = malloc(size);
    comp->e=e;
    return comp;
}