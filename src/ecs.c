#include "util/util.h"
#include "ecs.h"


void* add_component(Entity e,enum ComponentType type,int size){
    CGeneric *comp = malloc(size);
    comp->e=e;
    return (void*) comp;
}
void get_component(Entity e){
    CGeneric *comp;
    HASH_FIND_INT(position_map,&e,comp);
    CPosition *pos = (CPosition*)&comp;
    printf("%f\n",pos->x);
}