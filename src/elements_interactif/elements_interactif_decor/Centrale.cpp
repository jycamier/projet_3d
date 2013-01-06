#include <GL/gl.h>
#include <GL/glu.h>
#include "Centrale.h"
#include "../../sdlglutils.h"

Centrale::Centrale(double x, double y, double z, double longu, double larg,
		double haut, int nbrQte, int qteActive, string discourNormal,
		Etage* current) :
		ElementInteractifDecorQuete(x, y, z, nbrQte, qteActive, discourNormal,
				current) {
	this->hauteur = longu;
	this->longueur = haut;
	this->largeur = larg;

	this->cubeCentrale = new Cube(x, y, z, longu, haut, larg);
	this->cubeFeu = new Cube(x + 1, y, z - 2, longu, haut - 2, larg - 4);

}

Centrale::~Centrale() {

}

void Centrale::draw() {

	if (this->talk) {
		glRasterPos3i(this->position->x, this->position->y + 8,
				this->position->z);
		const unsigned char* toto =
				reinterpret_cast<const unsigned char*>(this->blabla.c_str());
		glutBitmapString(GLUT_BITMAP_HELVETICA_18, toto);
	}

	glColor3ub(255, 0, 0);
	this->cubeCentrale->draw();
	glColor3ub(0, 0, 0);
	this->cubeFeu->draw();

	glColor3ub(223, 223, 223);

	this->createHitboxes(this->position->x, this->position->y,
			this->position->z, 10, 10, 10);

	this->hitboxCreated = true;
}

