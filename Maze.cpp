#include "Maze.h"

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

void Maze::drawMap(){//Obstacle* aMap[5,5], int mapWidth, int mapHeight) {
  int row,column;
  	for (row = 0; row < mapHeight; row++ ){
    	for (column = 0; column < mapWidth; column++) {
      		//if (dynMap[row][column]) {
      		mvaddch(row, column, dynMap[row][column]->getSprite());	
      		//} else {
      		//	mvaddch(row, column, ' ');
      		//  }
    	}
  	}
}

Maze::~Maze() {
  for (int i = 0; i < mapHeight; ++i)
  {
    delete[] dynMap[i];
  }

  delete[] dynMap;

}
