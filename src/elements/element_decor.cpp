#include "element_decor.h"

ElementDecor::ElementDecor(double x, double y, double z) : Element() {
	this->setPosition(x, y, z);
}

void ElementDecor::setPosition(double x, double y, double z) {
	this->position = new Point(x,y,z);
}

ElementDecor::~ElementDecor() {

}
