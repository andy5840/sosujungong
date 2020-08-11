#include "Rectangle.h"

int main() {
	Shape* ps = new Rectangle();
	ps->draw();
	delete ps;
	
	Rectangle* r = new Rectangle();
	return 0;
}