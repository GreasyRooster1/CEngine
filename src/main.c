#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <stdio.h>
#include "renderer/window.h"
#include "cengine.h"

void processInput(GLFWwindow *window);
void render_loop();

int main() {

    start_game();

	return 0;
}