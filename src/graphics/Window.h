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
protected:
private:
	const char *title;
	int width, height;
	GLFWwindow *window;
	static bool KEYS[MAX_KEYS];
	static bool MOUSE_BUTTONS[MAX_MOUSE_BUTTONS];
	static Window *SINGLETON;

public:
	Window(const char *title, int width, int height);
	~Window();
	void update();
	bool isClosed() const;
	void clear() const;
	void close();
	static Window* getInstance(GLFWwindow *window){
		return SINGLETON;
	}

protected:
	bool is_closed = false;
};
}
}

sparky::graphics::Window sparky::graphics::Window::SINGLETON = nullptr;
#endif /* GRAPHICS_WINDOW_H_ */
