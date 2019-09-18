#ifndef ENTITY_H
#define ENTITY_H

#include <string>

class Entity
{
public:
	Entity();

	void setName(std::string aName);
	std::string getName();

	void setSprite(char aSprite);
	char getSprite();
	
	
	~Entity();

private:
	std::string name;
	char sprite;
	int size[2];

	
};

#endif