/*
 * Window.cpp
 *
 *  Created on: Jul 4, 2024
 *      Author: abod
 */

#include "Window.h"

namespace sparky {
namespace graphics {
Window::Window(const char *title, int width, int height) {
	this->title = title;
	this->width = width;
	this->height = height;
	if(!glfwInit()){
		glfwTerminate();
		std::cout << "GLFW: failed to init" << std::endl;
		return;
	}
	glfwSetErrorCallback(error_callback);
	this->window = glfwCreateWindow(width, height, title, NULL, NULL);
	if(!window){
		glfwTerminate();
		std::cout << "GLFW: failed to create window" << std::endl;
		return;
	}


	glfwMakeContextCurrent(this->window)

}

Window::~Window() {
	glfwDestroyWindow(this->window);
}

bool Window::isClosed() const {
	return false;
}

void Window::update() {

}
void Window::clear() const {

}



}//graphics

}//sparky

