//
// Created by dillo on 3/6/2025.
//

#include <stdbool.h>
#include "renderer.h"
#include "GLFW/glfw3.h"

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