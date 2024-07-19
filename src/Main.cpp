#include <GLFW/glfw3.h>
#include "graphics/Window.h"
#include "logs/Logger.h"
#include<iostream>

using namespace logs;

int main() {
	sparky::graphics::Window w("main", 450, 450);
	glClearColor(0.3f, 0.4f, 0.5f, 1.0);
	while(!w.isClosed()){
		w.clear();
		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.0f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();
		w.update();
	}

	return 0;
}
