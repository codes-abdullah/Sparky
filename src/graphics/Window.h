/*
 * Window.h
 *
 *  Created on: Jul 4, 2024
 *      Author: abod
 */

#ifndef GRAPHICS_WINDOW_H_
#define GRAPHICS_WINDOW_H_
#include <GLFW/glfw3.h>
#include <iostream>
namespace sparky {
namespace graphics {
class Window {
private:
	const char *title;
	int width, height;
	GLFWwindow *window;
public:
	Window(const char *title, int width, int height);
	~Window();
	void update();
	bool isClosed() const;
	void clear() const;
	static void error_callback(int error, const char *description) {
		fprintf(stderr, "Error: %s\n", description);
	}

};
}
}
#endif /* GRAPHICS_WINDOW_H_ */
