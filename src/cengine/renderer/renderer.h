//
// Created by dillo on 3/6/2025.
//

#ifndef CENGINE_RENDERER_H
#define CENGINE_RENDERER_H

#include "GLFW/glfw3.h"

void cleanup_renderer();
bool is_window_alive(GLFWwindow *window);
void setup_renderer();
void clear_window();

#endif //CENGINE_RENDERER_H
