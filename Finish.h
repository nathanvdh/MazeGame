#ifndef FINISH_H
#define FINISH_H

#include "Obstacle.h"
#include <string>
class Finish : public Obstacle
{
public:

	Finish();
	virtual void touched();
	~Finish();

};

#endif //FINISH_H
