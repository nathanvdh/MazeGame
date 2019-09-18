#ifndef ENTITY_H
#define ENTITY_H

#include <string>

class Entity
{
public:
	Entity();
	~Entity();

private:
	std::string name;
	char sprite;
	int size[2];

	
};

#endif