//
// Created by dillo on 3/7/2025.
//

#include "sprite.h"
#include "renderer.h"

f32 QUAD_MESH[] = {
    -1, -1, 0, // bottom left corner
    -1,  1, 0, // top left corner
    1,  1, 0, // top right corner
    1, -1, 0
};

Sprite* create_sprite(){
    Sprite *sprite = malloc(sizeof(Sprite));

    u32 VBO = gen_vbo(QUAD_MESH);

    return sprite;
}

u32 create_sprite_shader(){

}
