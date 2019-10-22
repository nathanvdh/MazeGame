#ifndef ENTITY_H
#define ENTITY_H

#include <string>

class Entity
{
public:
	Entity();
	Entity(char aSprite);
	
	bool setSprite(char aSprite);
	char getSprite();
	
	~Entity();

protected:
	char sprite;
	
};

#endif //ENTITY_H
