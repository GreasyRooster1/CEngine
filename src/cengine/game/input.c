//
// Created by dillo on 3/7/2025.
//

#include "input.h"
#include "gamestate.h"


bool check_key_pressed(GameState *state,int code, int action){
    if(code>GLFW_KEY_LAST){
        return false;
    }
    return state->inputState.keys[code]==action;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){

}