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
	bool setPos(int x, int y, int MAPHEIGHT, int MAPWIDTH);
	int getxPos();
	int getyPos();
	bool drawPerson();
	void promptName();
	std::string getName();
	~Person();

private:
	int xPos, yPos;
	std::string name;

};

#endif //PERSON_H
