#ifndef SPACE_H
#define SPACE_H

#include "Obstacle.h"
#include <string>
class Space : public Obstacle
{
public:

	Space();
	virtual bool touched(int yPos, Person* person);
	~Space();
};

#endif //SPACE_H