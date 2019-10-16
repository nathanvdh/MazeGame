#ifndef FINISH_H
#define FINISH_H

#include "Obstacle.h"
#include <string>
class Finish : public Obstacle
{
public:

	Finish();
	virtual bool touched(int yPos, Person* person);
	~Finish();

};

#endif //FINISH_H
