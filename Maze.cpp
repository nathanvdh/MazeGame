#include "Maze.h"
#include "Obstacle.h"
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

Maze::~Maze() {
  for (int i = 0; i < mapHeight; ++i)
  {
    delete[] dynMap[i];
  }

  delete[] dynMap;

}
