//#include <GLFW/glfw3.h>
//#include "graphics/Window.h"
//#include "logs/Logger.h"
#include<iostream>
#include "Car.cpp"
int Car::myvar;
int main(int argc, char **argv) {
//	logs::Logger::info("aaaaaaaxxxa");

//	sparky::graphics::Window w("title", 400, 400);
//	glClearColor(0.5f, 0.2f, 0.2f, 1.0f);
//	while (!w.isClosed()) {
//		w.update();
//	}

	Car c;
	Car::myvar = 99;

	Car b;
	Car::myvar = 3;


	c.print();
	b.print();


}
