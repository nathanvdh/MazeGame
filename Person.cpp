Person::Person() : Entity('@') {
}

void Person::move(int aKey) {
	switch (aKey) {
		case KEY_UP:
				yPos--;
			break;
		case KEY_DOWN:
				yPos++;
			break;
		case KEY_LEFT:
				xPos--;
			break;
		case KEY_RIGHT:
				xPos++;
			break;
	}
}

Person::~Person() {

}
