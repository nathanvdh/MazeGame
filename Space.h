#ifndef SPACE_H
#define SPACE_H

#include "Obstacle.h"
#include <string>
class Space : public Obstacle
{
public:

	Space();
	virtual bool touched(Maze* maze, Person* person, int keyPress);
	~Space();
};

#endif //SPACE_H