#ifndef BANANA_H
#define BANANA_H

#include "Obstacle.h"
#include <string>
class Banana : public Obstacle
{
public:

	Banana();
	virtual int touched(Maze* maze, Person* person, int keyPress);
	~Banana();
};

#endif //BANANA_H
