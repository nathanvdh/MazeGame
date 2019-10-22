#ifndef PERSON_H
#define PERSON_H

#include "Entity.h"
#include "Maze.h"
#include <curses.h>

//class Obstacle;
class Person : public Entity
{
public:
	Person();
	bool move(Maze* maze, int aKey);
	void setPos(int x, int y);
	int getxPos();
	int getyPos();
	void drawPerson();
	~Person();

private:
	int xPos, yPos;

};

#endif //PERSON_H