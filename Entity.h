#ifndef ENTITY_H
#define ENTITY_H

#include <string>

class Entity
{
public:
	Entity();
	Entity(char aSprite);

	void setSprite(char aSprite);
	char getSprite();
	
	
	~Entity();

private:
	char sprite;
};

#endif
