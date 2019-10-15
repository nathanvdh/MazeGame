#include "Finish.h"
#include <iostream>
#include <string>

Finish::Finish() : Obstacle('F', "You reached the finish") {

}

void Finish::touched() {
	
	std::cout << message << "\n";
	//exit program?? not sure how
}

Finish::~Finish() {

}