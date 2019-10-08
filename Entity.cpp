#include "Entity.h"
#include <string>

Entity::Entity() {
	sprite='?';

}

Entity::Entity(char aSprite) {
	sprite = aSprite;
}

void Entity::setSprite(char aSprite) {
	sprite = aSprite;
}

char Entity::getSprite() {
	return sprite;
}

Entity::~Entity() {

}
