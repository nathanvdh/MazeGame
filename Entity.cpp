#include "Entity.h"
#include <string>

Entity::Entity() {

}

Entity::Entity(std::string aName, int aSize[2], char aSprite) {
	name = aName;
	size[0] = aSize[0];
	size[1] = aSize[1];
	sprite = aSprite;
}

void Entity::setName(std::string aName) {
	name = aName;
}

std::string Entity::getName() {
	return name;
}

void Entity::setSprite(char aSprite) {
	sprite = aSprite;
}

char Entity::getSprite() {
	return sprite;
}

void Entity::setSize(int aSize[2]) {
	size[0] = aSize[0];
	size[1] = aSize[1];
}

int* Entity::getSize() {
	return size;
}


Entity::~Entity() {

}