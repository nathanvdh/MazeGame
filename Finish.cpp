#include "Finish.h"
#include <iostream>
#include <string>
#include <stdlib.h>

Finish::Finish() : Obstacle('X', "You reached the finish, press any key to exit         ") {

}

bool Finish::touched(Maze* maze, Person* person, int keyPress) {
	Obstacle::touched(maze, person, keyPress);
	person->drawPerson();
	//clear();
	getch();
	endwin();
	exit(0);

}

Finish::~Finish() {

}
