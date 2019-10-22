#ifndef MAZE_H
#define MAZE_H

#include <curses.h>

class Person;
class Obstacle;

class Maze {
public:
	Maze(int height, int width);
	bool setMap(Obstacle*** aDynMap);
	bool drawMap();
	Obstacle*** getMap();
	Obstacle* getNextObstacle(Person* person, int keyPress);
	Obstacle* getCurrentObstacle(Person* person);
	int getMapHeight();
	~Maze();
	
private:
	int mapWidth;
	int mapHeight;

	Obstacle*** dynMap;
};

#endif //MAZE_H
