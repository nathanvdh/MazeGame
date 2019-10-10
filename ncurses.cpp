#include <curses.h>

int main(void)
{
	initscr(); //initialize screen
	cbreak(); //force cbreak mode (dont need to press enter to put character)
	keypad(stdscr, TRUE); //enable function/arrow keys
	curs_set(0); //disable cursor
	noecho(); //disable echoing of input
	int inp = '\0';
	
	//setting map boundaries
	char map [40][20] = {	"########################################"
				"#                                      #",
				"#                                 X    #",
				"#                                      #",
				"#                                      #",
				"#                                      #",
				"#                                      #",
				"#                                      #",
				"#                                      #",
				"#                                      #",
				"#                                      #",
				"#                                      #",
				"#                                      #",
				"#                                      #",
				"#                                      #",
				"#                                      #",
				"#                                      #",
				"#                                      #",
				"#                                      #",
				"########################################" };
	
	//initialisation of map dimensions
	int MAPHEIGHT = 20, MAPWIDTH = 40;
	//intialisation of position variables
	int xPos =2, yPos=2;
	
	//drawing of map and text ******* Not sure if it should be height or length used *******************
	drawMap(map,MAPHEIGHT);
	mvprintw(MAPHEIGHT,1,"Reach the end zone to complete the game");
	mvprintw(MAPHEIGHT+2,1,"Press q to quit game");
	
	//Puts cursor at starting position
	move(yPos,xPos);
	
	while (inp !='q')
	{
		inp = getch();

		mvaddch(5,50,inp);
		
		//something to say, when the position is at X, force the input to be q and quit the game
	}

	endwin();
	return 0;
}	

