//FOR TESTING
//#include "Obstacle.h"
#include "Wall.h"
#include "Finish.h"
#include "Maze.h"
#include "Person.h"
#include <string>
#include <iostream>
int main(void)
{
	Wall *wall;
	Finish *finish;
	Person *person;
	
	wall = new Wall();
	finish = new Finish();
	person = new Person();

	std::cout << wall->getSprite() << "\n";
	wall->touched();

	
	std::cout << finish->getSprite() << '\n';
	finish->touched();

	Obstacle* myMap[5,5] = 
	[	wall,wall,wall,wall,wall,
		wall,NULL,NULL,finish,wall,
		wall,NULL,NULL,NULL,wall,
		wall,NULL,NULL,NULL,wall,
		wall,wall,wall,wall,wall,	];

	Maze maze = Maze();
	maze.setMap(myMap);


	return 0;
}