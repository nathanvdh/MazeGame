#ifndef HOLE_H
#define HOLE_H

#include "Obstacle.h"
#include <string>
class Hole : public Obstacle
{
public:

	Hole();
	virtual int touched(Maze* maze, Person* person, int keyPress);
	~Hole();
};

#endif //HOLE_H