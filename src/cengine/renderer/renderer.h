//
// Created by dillo on 3/6/2025.
//

#ifndef CENGINE_RENDERER_H
#define CENGINE_RENDERER_H

#include "../util/types.h"
#include "GLFW/glfw3.h"
#include "stdbool.h"

void cleanup_renderer();
bool is_window_alive(GLFWwindow *window);
void setup_renderer();
void clear_window();

u32 gen_vbo(f32 vert_data[]);

#endif //CENGINE_RENDERER_H
