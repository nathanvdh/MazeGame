#include "Finish.h"
#include <iostream>
#include <string>

Finish::Finish() : Obstacle('F', "You reached the finish") {

}

bool Finish::touched() {
	
	std::cout << message << "\n";
	//exit program?? not sure how
	return 1;
}

Finish::~Finish() {

}
