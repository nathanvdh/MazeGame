//FOR TESTING
#include "Obstacle.h"
#include <string>
#include <iostream>
int main(void)
{
	Obstacle genOb = Obstacle('|');

	std::cout << genOb.getSprite() <<"\n";
	genOb.touched();
	genOb.setSprite('-');
	std::cout << genOb.getSprite() <<"\n";

	return 0;
}