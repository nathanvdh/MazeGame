#include "Finish.h"
#include <iostream>
#include <string>
#include <stdlib.h>

Finish::Finish() : Obstacle('X', "You reached the finish, press any key to exit         ") {

}

bool Finish::touched(Maze* maze, Person* person, int keyPress) {
	Obstacle::touched(maze, person, keyPress); //prints the finish message
	person->drawPerson(); //draws the player on the finish space
	getch(); //press any key to exit
	endwin(); //shutdown ncurses properly
	exit(0); //exit the entire program

}

Finish::~Finish() {

}
