/*
 * Window.h
 *
 *  Created on: Jul 4, 2024
 *      Author: abod
 */

#ifndef GRAPHICS_WINDOW_H_
#define GRAPHICS_WINDOW_H_
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../logs/Logger.h"
#define MAX_KEYS 1024
#define MAX_MOUSE_BUTTONS 32
namespace sparky {
namespace graphics {
class Window {
private:

	const char *title;
	int width, height;
	GLFWwindow *window;
	static bool KEYS[MAX_KEYS];
	static bool MOUSE_BUTTONS[MAX_MOUSE_BUTTONS];

public:
	Window(const char *title, int width, int height);
	~Window();
	void update();
	bool isClosed() const;
	void clear() const;
	void close();
	static void error_callback(int error, const char *description) {
		logs::Logger::error(std::string(description));
	}
protected:
	bool is_closed= false;
};
}
}
#endif /* GRAPHICS_WINDOW_H_ */
