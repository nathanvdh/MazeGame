#include "Maze.h"

Maze::Maze() {

  //int mapWidth=5;
  //int mapHeight=5;
}

void Maze::setMap(Obstacle* aMap[][5]) {
	int row, column;
  	
  	for (row=0; row < 5; row++ ){
    	for (column=0; column < 5 ;column++) {
      		map[row][column] = aMap[row][column];
    	}
  	}
}

void Maze::drawMap(){//Obstacle* aMap[5,5], int mapWidth, int mapHeight) {
	
  int row,column;

  	for (row=0;row<5;row++ ){
    	for (column=0;column<5;column++) {
      		if (map[row][column]) {
      		mvaddch(row,column,map[row][column]->getSprite());	
      		} else {
      			mvaddch(row,column,' ');
      		}

    	}
  	}
}

Maze::~Maze() {

}
