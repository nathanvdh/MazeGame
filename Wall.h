#ifndef WALL_H
#define WALL_H

#include "Obstacle.h"
#include <string>
class Wall : public Obstacle
{
public:

	Wall();
	virtual bool isWall();
	~Wall();
};

#endif //WALL_H
