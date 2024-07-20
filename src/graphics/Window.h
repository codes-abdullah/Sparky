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
	typedef void (*ON_ERROR_LISTENER)(Window *w, int error, std::string *msg);
protected:
private:
	const char *title;
	int width, height;
	GLFWwindow *window;
	static bool KEYS[MAX_KEYS];
	static bool MOUSE_BUTTONS[MAX_MOUSE_BUTTONS];
	static double mx, my;
	ON_ERROR_LISTENER errorListener;

public:

	Window(const char *title, int width, int height);
	~Window();
	void update();
	bool isClosed() const;
	void clear() const;
	void close();
	static void onKeyEvent(GLFWwindow *window, int key, int scancode,
			int action, int mods);
	static bool isKeyPressed(unsigned int keycode);
	static bool isMouseButtonPressed(unsigned int keycode);
	void setErrorListener(ON_ERROR_LISTENER l);
protected:
	static void onErrorEvent(int error, const char *description);
	static void onMouseButtonEvent(GLFWwindow *window, int button, int action,
			int mods);
	static void onResizeEvent(GLFWwindow *window, int width, int height);

protected:
	bool is_closed = false;
};
}
}

#endif /* GRAPHICS_WINDOW_H_ */
