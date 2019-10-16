#ifndef WALL_H
#define WALL_H

#include "Obstacle.h"
#include <string>
class Wall : public Obstacle
{
public:

	Wall();
	virtual bool touched(int yPos, Person* person, int keyPress);
	~Wall();
};

#endif //WALL_H
