#include "Finish.h"
#include <iostream>
#include <string>

Finish::Finish() : Obstacle('X', "You reached the finish, press q to exit         ") {

}

bool Finish::touched(Maze* maze, Person* person, int keyPress) {
	movePerson(maze, person, keyPress);	
	//mvprintw(maze->getMapHeight(), 0, "                              ");
	mvprintw(maze->getMapHeight(),0, message.c_str());
	return 1;
}

Finish::~Finish() {

}
