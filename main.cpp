//FOR TESTING
//#include "Obstacle.h"
#include "Wall.h"
#include <string>
#include <iostream>
int main(void)
{
	Wall wall1 = Wall('|');
	Wall wall2 = Wall('-');
	std::cout << wall1.getSprite() << "\n";
	wall1.touched();
	std::cout << wall2.getSprite() << "\n";
	wall2.touched();

	return 0;
}