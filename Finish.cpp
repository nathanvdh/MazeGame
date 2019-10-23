#include "Finish.h"
#include <iostream>
#include <string>
#include <stdlib.h>

Finish::Finish() : Obstacle('X', "You reached the finish, press any key to exit         ") {

}

int Finish::touched(Maze* maze, Person* person, int keyPress) {
	Obstacle::touched(maze, person, keyPress); //prints the finish message
	person->drawPerson(); //draws the player on the finish space
	getch(); //press any key to exit
	//endwin(); //shutdown ncurses properly
	return 2; // to exit main

}

Finish::~Finish() {

}
