//
// Created by dillo on 3/6/2025.
//

#include <stdbool.h>
#include "renderer.h"
#include "../util/types.h"

void setup_renderer(){
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
}

void cleanup_renderer(){
    glfwTerminate();
}

bool is_window_alive(GLFWwindow *window){
    return !glfwWindowShouldClose(window);
}

void clear_window(){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
}

u32 gen_vbo(f32 vert_data[]){
    u32 VBO;
    glGenBuffers(1,&VBO);
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER,sizeof(*vert_data),vert_data,GL_STATIC_DRAW);
    return VBO;
};