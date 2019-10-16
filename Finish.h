#ifndef FINISH_H
#define FINISH_H

#include "Obstacle.h"
#include <string>
class Finish : public Obstacle
{
public:

	Finish();
	virtual bool touched(int yPos);
	~Finish();

};

#endif //FINISH_H
