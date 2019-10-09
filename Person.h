#ifdef PERSON_H
#define PERSON_H

#include "Entity.h"
///#include <ncurses.h>

class Person : public Entity
{
public:
	Person();
	void move(int aKey);
	~Person();

private:
	int xPos, yPos

};

#endif //PERSON_H