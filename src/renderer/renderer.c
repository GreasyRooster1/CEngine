//
// Created by dillo on 3/6/2025.
//

#include <stdbool.h>
#include "renderer.h"
#include "GLFW/glfw3.h"

void cleanup_renderer(){
    glfwTerminate();
}

bool is_window_alive(GLFWwindow *window){
    return !glfwWindowShouldClose(window);
}

void clear_window(){

}