//#include <GLFW/glfw3.h>
//#include "graphics/Window.h"
//#include "logs/Logger.h"
#include<iostream>
#include "Car.cpp"
int main(int argc, char **argv) {
//	logs::Logger::info("aaaaaaaxxxa");

//	sparky::graphics::Window w("title", 400, 400);
//	glClearColor(0.5f, 0.2f, 0.2f, 1.0f);
//	while (!w.isClosed()) {
//		w.update();
//	}

	Car c;
	c.myvar = 99;
	c.print();

	Car b;
	b.myvar = 3;


	b.print();


}
