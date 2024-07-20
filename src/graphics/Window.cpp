/*
 * Window.cpp
 *
 *  Created on: Jul 4, 2024
 *      Author: abod
 */

#include "Window.h"

namespace sparky {
namespace graphics {

using namespace logs;

bool Window::KEYS[MAX_KEYS];
bool Window::MOUSE_BUTTONS[MAX_MOUSE_BUTTONS];
double Window::my;
double Window::mx;

Window::Window(const char *title, int width, int height) {
	this->title = title;
	this->width = width;
	this->height = height;
	if (!glfwInit()) {
		Logger::error("GLFW init failed");
		close();
		return;
	}

	glfwSetErrorCallback(onErrorEvent);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
	this->window = glfwCreateWindow(width, height, title, NULL, NULL);
	if (!window) {
		Logger::error("GLFW init window failed");
		close();
		return;
	}

	glfwMakeContextCurrent(this->window);
	glfwSetWindowSizeCallback(window, onResizeEvent);
	glfwSetKeyCallback(this->window, onKeyEvent);
	glfwSetMouseButtonCallback(this->window, onMouseButtonEvent);
	//=============
	//This must be always after glfwMakeContextCurrent
	//glew will ensure to load the new version of GL
	//=============
	if (glewInit() != GLEW_OK) {
		Logger::error("GLEW init failed");
		close();
		return;
	}

	glfwSetWindowUserPointer(this->window, this);
//	getInstance(window);

	for (int i = 0; i < MAX_KEYS; i++) {
		KEYS[i] = false;
	}

	for (int i = 0; i < MAX_MOUSE_BUTTONS; i++) {
		MOUSE_BUTTONS[i] = false;
	}

	//========================

	Logger::debug(
			std::string("CXX version: ").append(std::to_string(__cplusplus)));
	Logger::debug(
			std::string("GL version: ").append(
					(const char*) glGetString(GL_VERSION)));
	Logger::debug(std::string("GLFW version: ").append(glfwGetVersionString()));
}

bool Window::isKeyPressed(unsigned int keycode) {
	if (keycode > MAX_KEYS)
		return false;
	return KEYS[keycode];
}

bool Window::isMouseButtonPressed(unsigned int keycode) {
	if (keycode > MAX_MOUSE_BUTTONS)
		return false;
	return MOUSE_BUTTONS[keycode];
}

Window::~Window() {
	glfwDestroyWindow(this->window);
}

bool Window::isClosed() const {
	return this->is_closed || glfwWindowShouldClose(this->window);
}

void Window::update() {
	glfwSwapBuffers(this->window);
//	glfwGetFramebufferSize(this->window, &width, &height);
	glfwPollEvents();
}
void Window::clear() const {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::close() {
	this->is_closed = true;
	glfwTerminate();
	Logger::debug("Closing Window instance...");
}

void Window::onKeyEvent(GLFWwindow *window, int key, int scancode, int action,
		int mods) {
	//Window *w = (Window*)glfwGetWindowUserPointer(window);
	Logger::debug(std::string("KEY_EVENT: ").append(std::to_string(key)));
	KEYS[key] = action != GLFW_RELEASE;
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
}

void Window::onMouseButtonEvent(GLFWwindow *window, int button, int action,
		int mods) {
	Logger::debug(std::string("MOUSE_EVENT: ").append(std::to_string(button)));
	MOUSE_BUTTONS[button] = action != GLFW_RELEASE;
}

void Window::onResizeEvent(GLFWwindow *window, int width, int height) {
	glViewport(0, 0, width, height);
	Logger::debug(
			"window size changed: " + std::to_string(width) + "x"
					+ std::to_string(height));
}

void Window::onErrorEvent(int error, const char *description) {
	Logger::error(std::string(description));
	errorListener(this->window, error, std::string(description));
}

} //graphics

} //sparky

