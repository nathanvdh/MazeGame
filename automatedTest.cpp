#include "Person.h"
#include <curses.h>
#include <iostream>

int main(void) {

	Person *player;
	player = new Person();

	int xPos = 0;
	int yPos = 0;

	std::cout <<"Enter xPos: " << "\n";
	std::cin >> xPos;

	std::cout <<"Enter yPos: " << "\n";
	std::cin >> yPos;
	
	player->setPos(xPos,yPos);

	std::cout << player->getxPos() << ", " << player->getyPos() <<"\n";


	std::cout << "Did player move? " << player->move(KEY_DOWN) << "\n";
}