#include "Maze.h"

Maze::Maze() {

}

void Maze::setMap(Obstacle* aMap[][5]) {
	int row, column;
  	
  	for (row=0; row < mapHeight; row++ ){
    	for (column=0; column < mapWidth ;column++) {
      		map[row][column] = aMap[row][column];
    	}
  	}
}

void Maze::drawMap(){//Obstacle* aMap[5,5], int mapWidth, int mapHeight) {
	int row,column;

  	for (row=0;row<5;row++ ){
    	for (column=0;column<5;column++) {
      		if (myMap[row][column]) {
      		mvaddch(row,column,myMap[row][column]->getSprite());	
      		} else {
      			mvaddch(row,column,' ');
      		}

    	}
  	}
}

Maze::~Maze() {

}
