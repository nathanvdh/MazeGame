#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "Entity.h"
#include <string>
class Obstacle : public Entity
{
public:

	Obstacle();
	Obstacle(char aSprite);
	virtual void touched();
	~Obstacle();
private:
	std::string message;
	
};

#endif //OBSTACLE_H
