//
// Created by dillo on 3/7/2025.
//

#ifndef CENGINE_INPUT_H
#define CENGINE_INPUT_H

#include "GLFW/glfw3.h"
#include "gamestate.h"

typedef struct {
    int keys[GLFW_KEY_LAST];
} InputState;

bool check_key_pressed(GameState *state,int code, int action);

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

#endif //CENGINE_INPUT_H
