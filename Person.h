#ifndef PERSON_H
#define PERSON_H

#include "Entity.h"
#include <curses.h>

class Person : public Entity
{
public:
	Person();
	bool move(int aKey);
	void setPos(int x, int y);
	int getxPos();
	int getyPos();
	~Person();

private:
	int xPos, yPos;

};

#endif //PERSON_H