#include "Maze.h"
#include "Obstacle.h"
#include "Person.h"

//If map height and width are greater than zero, allocates memory for 2D map
//else, returns dimensionless map
Maze::Maze(int height,int width, int astartY, int astartX) {
  if (height >0 && width>0 && astartY > 0 && astartX >0) {   
    mapHeight=height;
    mapWidth=width;
    startX = astartX;
    startY = astartY;
    dynMap = new Obstacle**[mapHeight];
    for (int i = 0; i < mapHeight; ++i)
      {
        dynMap[i] = new Obstacle*[mapWidth];
      }
  } else {                    
    mapHeight=0;
    mapWidth=0;
  }
}

//sets the maze to the inputted map
bool Maze::setMap(Obstacle*** aDynMap) {
	if (mapHeight >0 && mapWidth>0) {
		int row, column;
  	
  		for (row=0; row < mapHeight; row++ ){
    			for (column=0; column < mapWidth ;column++) {
      				dynMap[row][column] = aDynMap[row][column];
    			}
  		}
		return 1;
	} else {
		return 0;
	}
}

//draws the map using curses
bool Maze::drawMap(Person* person){
  if (mapHeight < 1 || mapWidth < 1)
  {
    return 0;
  }
  int row,column;
  	for (row = 0; row < mapHeight; row++ ){
    		for (column = 0; column < mapWidth; column++) {
      			mvaddch(row, column, dynMap[row][column]->getSprite());	
    		}
  	}

  mvprintw(mapHeight+1,0,"Reach the end zone (X) to complete the game");
  mvprintw(mapHeight+2,0,"Press q to quit game");
  mvprintw(mapHeight+3,0,"Username: ");
  mvprintw(mapHeight+3,10,person->getName().c_str());
return 1;
}

Obstacle*** Maze::getMap() {
	return dynMap;
}

int Maze::getMapHeight() {
  return mapHeight;
}

int Maze::getMapWidth() {
	return mapWidth;
}

//returns the obstacle next to a person object in the direction of keyPress
Obstacle* Maze::getNextObstacle(Person* person, int keyPress) {
      switch (keyPress) {
      case KEY_UP :
        return dynMap[person->getyPos()-1][person->getxPos()];
        break;
      case KEY_DOWN :
        return dynMap[person->getyPos()+1][person->getxPos()];
        break;
      case KEY_LEFT :
        return dynMap[person->getyPos()][person->getxPos()-1];
        break;
      case KEY_RIGHT :
        return dynMap[person->getyPos()][person->getxPos()+1];
        break;
      default:
        return NULL;
    }
}

Obstacle* Maze::getCurrentObstacle(Person* person) {
  return dynMap[person->getyPos()][person->getxPos()];
}

int Maze::getStartY() {
  return startY;
}

int Maze::getStartX() {
  return startX;
}

Maze::~Maze() {
  if (mapHeight > 0 ) {
    for (int i = 0; i < mapHeight; ++i)
      {
        delete[] dynMap[i];
      }

    delete[] dynMap;
  }
}
