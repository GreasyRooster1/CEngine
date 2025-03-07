//
// Created by dillo on 3/7/2025.
//

#include <malloc.h>
#include "input.h"
#include "gamestate.h"


bool check_key_pressed(GameState *state,int code){
    return check_key_state(state,code,GLFW_PRESS);
}

bool check_key_state(GameState *state,int code, int action){
    int keyState = glfwGetKey(state->window, code);
    return keyState == action;
}

InputState* create_input_state(){
    InputState *state = malloc(sizeof(InputState));
    return state;
}