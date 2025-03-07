#include <stdio.h>
#include "cengine/cengine.h"

void processInput(GLFWwindow *window);
void render_loop();

int main() {
    printf("%s\n","Game starting...");
    start_game();
	return 0;
}