#include "Element_Interactif.h"

ElementInteractif::ElementInteractif(double x, double y, double z) : Element() {
	this->setPosition(x, y, z);
}

void ElementInteractif::setPosition(double x, double y, double z) {
	this->position = new Point(x,y,z);
}


void ElementInteractif::draw() {

}

ElementInteractif::~ElementInteractif() {

}
