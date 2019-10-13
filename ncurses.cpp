#include <curses.h>
#include <iostream>
//#include <string>

//Takes input, checks that player remains inside boundaries and moves player
//Returns a 'true', if player's position is moved
bool playerMove(int inp, int *xPos, int *yPos, char map[][40]) {
	bool result = 0;
	switch (inp) {
		case KEY_UP:
			if (map[*yPos-1][*xPos]!='#') {
				result= 1;
				*yPos=*yPos-1;
			}
			break;
		case KEY_DOWN:
			if (map[*yPos+1][*xPos]!='#') {
				result= 1;
				*yPos=*yPos+1;
			}
			break;
		case KEY_LEFT:
			if (map[*yPos][*xPos-1]!='#') {
				result= 1;
				*xPos=*xPos-1;
			}
			break;
		case KEY_RIGHT:
			if (map[*yPos][*xPos+1]!='#') {
				result= 1;
				*xPos=*xPos+1;
			}
			break;
	}
return result;
}

bool endZone(int *xPos, int *yPos, char map[][40], int MAPHEIGHT) {
	bool result = 0;
	if (map[*yPos][*xPos]=='X') {
		mvprintw(MAPHEIGHT+3,1,"Congrats you win, press any key to exit");
		getch();
		result = 1;
		//*inp = 'q';
	}
return result;
}

void drawMap(char map[][40], int MAPWIDTH, int MAPHEIGHT) {
	int row,column;
  	for (row=0;row<MAPHEIGHT;row++ ){
    	for (column=0;column<MAPWIDTH;column++) {
      		mvaddch(row,column,map[row][column]);
    	}
  	}
}

int main(void)
{
	initscr(); //initialize screen
	cbreak(); //force cbreak mode (dont need to press enter to put character)
	keypad(stdscr, TRUE); //enable function/arrow keys
	curs_set(0); //disable cursor
	noecho(); //disable echoing of input
	int inp = '\0';
	
	//setting map boundaries
	char map [][40] = {	
				'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',
				'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
				'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X',' ',' ',' ',' ',' ',' ',' ','#',
				'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
				'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
				'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
				'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
				'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
				'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
				'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
				'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
				'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
				'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
				'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
				'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
				'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
				'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
				'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
				'#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',
				'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#' };
	
	//initialisation of map dimensions
	const int MAPHEIGHT = 20, MAPWIDTH = 40;
	//intialisation of position variables
	int xPos=2, yPos=2;
	
	//drawing of map and text ******* Not sure if it should be height or length used *******************
	drawMap(map,MAPWIDTH, MAPHEIGHT);
	mvprintw(MAPHEIGHT,1,"Reach the end zone (X) to complete the game");
	mvprintw(MAPHEIGHT+2,1,"Press q to quit game");
	
	//Puts cursor at starting position
	move(yPos,xPos);
	mvaddch(yPos,xPos,'@');
	
	while (inp !='q')
	{
		//mvprintw(MAPHEIGHT+3,1,"%d",xPos);
		inp = getch();
		mvaddch(yPos,xPos,' ');
		if (!(playerMove(inp, &xPos, &yPos, map))) {
			//mvprintw(MAPHEIGHT+3,1,"You didn't press an arrow key");
		}

		mvaddch(yPos,xPos,'@');

		if (endZone(&xPos, &yPos, map, MAPHEIGHT)) {
			endwin();
			return 0;
		};

	}

	endwin();
	return 0;
}	
