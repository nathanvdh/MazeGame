#ifndef OBSTACLE_H
#define OBSTACLE_H

//Obstacle is an abstract class and cannot be instantiated

#include "Entity.h"
#include "Person.h"
#include "Maze.h"

#include <string>
#include <curses.h>


class Obstacle : public Entity
{
public:

	Obstacle(char aSprite, std::string aMessage);
	virtual bool touched(Maze* maze, Person* person, int keyPress); 	//touched() returns 1 if the player can move onto the obstacle, 0 if not 
														//&& runs any code to be executed when you 'hit' the object
	//void movePerson(Maze* maze, Person* person, int keyPress);
	virtual bool isWall();
	~Obstacle();		

protected:
	std::string message;
	
};

#endif //OBSTACLE_H
