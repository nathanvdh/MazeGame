#ifndef MAZE_H
#define MAZE_H

#include <curses.h>

class Person;
class Obstacle;

class Maze {
public:
	Maze(int height, int width, int astartY, int astartX);
	bool setMap(Obstacle*** aDynMap);
	bool drawMap(Person* person);
	Obstacle*** getMap();
	Obstacle* getNextObstacle(Person* person, int keyPress);
	Obstacle* getCurrentObstacle(Person* person);
	int getMapHeight();
	int getMapWidth();
	int getStartY();
	int getStartX();
	~Maze();
	
private:
	int mapWidth;
	int mapHeight;
	int startX;
	int startY;

	Obstacle*** dynMap;
};

#endif //MAZE_H
