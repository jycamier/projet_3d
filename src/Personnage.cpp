/*
 * Personnage.cpp
 *
 *  Created on: 10 déc. 2012
 *      Author: jean-yves
 */

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "Personnage.h"

Personnage::Personnage(double x, double y, double z, int angle) {
	// TODO Auto-generated constructor stub
	this->x = x;
	this->y = y;
	this->z = z;
	this->angle = angle;

	this->pas = 1;
}

Personnage::~Personnage() {
	// TODO Auto-generated destructor stub
}

void Personnage::Avancer() {
	x = x - pas * sin((angle * 2 * M_PI) / 360);
	z = z + pas * cos((angle * 2 * M_PI) / 360);
}
void Personnage::Reculer() {
	x = x + pas * sin((angle * 2 * M_PI) / 360);
	z = z - pas * cos((angle * 2 * M_PI) / 360);
}
void Personnage::TournerGauche() {
	angle = angle - 3;
}
void Personnage::TournerDroite() {
	angle = angle + 3;
}

void Personnage::UpdateCamera() {
	glRotated(angle, 0, 1, 0);
	gluLookAt(x, y + 2, z, x, y + 2, z + 1, 0, 1, 0);
}

