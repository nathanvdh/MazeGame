#ifndef OBSTACLE_H
#define OBSTACLE_H

//Obstacle is an abstract class and cannot be instantiated

#include "Entity.h"
#include <string>
#include <curses.h>

class Obstacle : public Entity
{
public:

	Obstacle(char aSprite, std::string aMessage);
	virtual bool touched(int yPos, Person* person)=0; 	//touched() returns 1 if the player can move onto the obstacle, 0 if not 
														//&& runs any code to be executed when you 'hit' the object
	~Obstacle();		

protected:
	std::string message;
	
};

#endif //OBSTACLE_H
