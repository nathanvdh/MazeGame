#include "Maze.h"
#include "Obstacle.h"
#include "Person.h"
Maze::Maze(int height,int width) {
  mapHeight=height;
  mapWidth=width;
  dynMap = new Obstacle**[mapHeight];
  for (int i = 0; i < mapHeight; ++i)
  {
    dynMap[i] = new Obstacle*[mapWidth];
  }

}

void Maze::setMap(Obstacle*** aDynMap) {
	int row, column;
  	
  	for (row=0; row < mapHeight; row++ ){
    	for (column=0; column < mapWidth ;column++) {
      		dynMap[row][column] = aDynMap[row][column];
    	}
  	}
}

void Maze::drawMap(){
  

  int row,column;
  	for (row = 0; row < mapHeight; row++ ){
    	for (column = 0; column < mapWidth; column++) {
      		mvaddch(row, column, dynMap[row][column]->getSprite());	
    	}
  	}

  mvprintw(mapHeight+1,0,"Reach the end zone (X) to complete the game");
  mvprintw(mapHeight+2,0,"Press q to quit game");
}

Obstacle*** Maze::getMap() {
	return dynMap;
}

int Maze::getMapHeight() {
  return mapHeight;
}

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


Maze::~Maze() {
  for (int i = 0; i < mapHeight; ++i)
  {
    delete[] dynMap[i];
  }

  delete[] dynMap;

}
