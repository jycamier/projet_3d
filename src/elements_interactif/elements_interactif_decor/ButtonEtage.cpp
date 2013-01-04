#include <GL/gl.h>
#include <GL/glu.h>
#include "Button.h"
#include "ButtonEtage.h"

ButtonEtage::ButtonEtage(double x, double y, double z, char direction, double diam, int text, EtageFactory* fct, int e) : Button(x, y, z, direction, diam, text)
{

	this->factory = fct;
	this->etage = e;

}


ButtonEtage::~ButtonEtage(){

}


void ButtonEtage::interaction()
{

	this->factory->loadEtage(this->etage);

}
