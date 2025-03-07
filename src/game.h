//
// Created by dillo on 3/6/2025.
//

#ifndef CENGINE_GAME_H
#define CENGINE_GAME_H

#include "cengine.h"
#include "game/gamestate.h"

void setup(GameState *state);
void update(GameState *state);

#define GAME_PRELOOP
void pre_loop(GameState *state);
#define GAME_POSTLOOP
void post_loop(GameState *state);

#endif //CENGINE_GAME_H
