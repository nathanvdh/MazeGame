#ifndef ENTITY_H
#define ENTITY_H

#include <string>

class Entity
{
public:
	Entity();
	Entity(std::string aName, int aSize[2], char aSprite);
	
	void setName(std::string aName);
	std::string getName();

	void setSprite(char aSprite);
	char getSprite();

	void setSize(int aSize[2]);
	int* getSize();
	
	
	~Entity();

private:
	std::string name;
	char sprite;
	int size[2];

	
};

#endif