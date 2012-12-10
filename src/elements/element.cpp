#include "element.h"

Element::Element(double x, double y, double z) {
	this->setPosition(x, y, z);
}

void Element::setPosition(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;
}