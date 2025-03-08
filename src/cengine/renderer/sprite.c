//
// Created by dillo on 3/7/2025.
//

#include <stdio.h>
#include "sprite.h"
#include "glad.h"
#include "renderer.h"
#include "../util/file.h"

u32 create_sprite_shader();

f32 QUAD_MESH[] = {
    -1, -1, 0, // bottom left corner
    -1,  1, 0, // top left corner
    1,  1, 0, // top right corner
    1, -1, 0
};

Sprite* create_sprite(){
    Sprite *sprite = malloc(sizeof(Sprite));

    u32 VBO = gen_vbo(QUAD_MESH);
    u32 programId = create_sprite_shader();

    return sprite;
}

u32 create_sprite_shader(){
    FILE *frag_ptr;
    frag_ptr = fopen("resources/shaders/sprite.vert", "r");
    int len = get_file_size(frag_ptr);
    char vert_buf[len];
    fgets(vert_buf, len, frag_ptr);

    FILE *vert_ptr;
    vert_ptr = fopen("resources/shaders/sprite.frag", "r");
    len = get_file_size(vert_ptr);
    char frag_buf[len];
    fgets(vert_buf, len, vert_ptr);

    u32 vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, (const GLchar *const *) vert_buf, NULL);
    glCompileShader(vertexShader);

    u32 fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, (const GLchar *const *) frag_buf, NULL);
    glCompileShader(fragmentShader);

    u32 shader_program = glCreateProgram();
    glAttachShader(shader_program, vertexShader);
    glAttachShader(shader_program, fragmentShader);
    glLinkProgram(shader_program);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    free(vert_ptr);
    free(frag_ptr);

    return shader_program;
}
