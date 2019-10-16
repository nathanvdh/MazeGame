#ifndef HOLE_H
#define HOLE_H

#include "Obstacle.h"
#include <string>
class Hole : public Obstacle
{
public:

	Hole();
	virtual bool touched(int yPos, Person* person);
	~Hole();
};

#endif //WALL_H
