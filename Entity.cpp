#include "Entity.h"
#include <string>

Entity::Entity() {
	sprite='?';

}

Entity::Entity(char aSprite) {
	sprite = aSprite;
}

bool Entity::setSprite(char aSprite) {
	sprite = aSprite;
	return 1;
}

char Entity::getSprite() {
	return sprite;
}

Entity::~Entity() {

}
