#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <stdio.h>
#include "renderer/window.h"
#include "cengine.h"

void processInput(GLFWwindow *window);
void render_loop();

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main() {

    start_game();

	while () {
		processInput(window);


        render_loop();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	return 0;
}

void render_loop(){

}

void processInput(GLFWwindow *window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, 1);
}
