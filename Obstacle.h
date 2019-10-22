#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "Entity.h"
#include "Person.h"
#include "Maze.h"

#include <string>
#include <curses.h>


class Obstacle : public Entity
{
public:

	Obstacle(char aSprite, std::string aMessage);
	virtual bool touched(Maze* maze, Person* person, int keyPress); 	//touched() returns 1 if the player can move onto the obstacle 
																		//&& runs any code to be executed when you 'hit' the object
	virtual bool isWall();
	~Obstacle();		

protected:
	std::string message;
	
};

#endif //OBSTACLE_H
