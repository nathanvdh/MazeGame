#include "Banana.h"
#include <iostream>
#include <string>


Banana::Banana() : Obstacle('(', "You slipped on a banana                        ") {

}

bool Banana::touched(Maze* maze, Person* person, int keyPress) {
	mvprintw(maze->getMapHeight(),0, message.c_str());
	//moves person onto and off banana
	movePerson(maze, person, keyPress);	
	//person->move(keyPress,maze->getMap()[person->getyPos()][person->getxPos()]->getSprite());
	//continually moves person
	
	switch (keyPress) {
		case KEY_UP:
			while(maze->getMap()[person->getyPos()-1][person->getxPos()]->getSprite() == (' ')) {
				movePerson(maze, person, keyPress);	
			}
			break;
		case KEY_DOWN:
			while(maze->getMap()[person->getyPos()+1][person->getxPos()]->getSprite() == (' ')) {
				movePerson(maze, person, keyPress);	
			}
			break;
		case KEY_LEFT:
			while(maze->getMap()[person->getyPos()][person->getxPos()-1]->getSprite() == (' ')) {
				movePerson(maze, person, keyPress);	
			}
			break;
		case KEY_RIGHT:
			while(maze->getMap()[person->getyPos()][person->getxPos()+1]->getSprite() == (' ')) {
				movePerson(maze, person, keyPress);	
			}
			break;

	}
	return 0;
}

Banana::~Banana() {

}
