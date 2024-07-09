#include <iostream>

struct Car{
public:
	static int myvar;
	void print(){
		std::cout<<myvar<<std::endl;
	}
};


int Car::myvar;
