//
// Created by dillo on 3/7/2025.
//

#ifndef CENGINE_SPRITE_H
#define CENGINE_SPRITE_H

#include <malloc.h>
#include "../util/types.h"

const f32 QUAD_MESH[12] = {
    -1, -1, 0, // bottom left corner
    -1,  1, 0, // top left corner
    1,  1, 0, // top right corner
    1, -1, 0
};

typedef struct{
    u32 VAO;
    u32 shaderId;
    u32 textureId;
}Sprite;

Sprite* create_sprite();


#endif //CENGINE_SPRITE_H
