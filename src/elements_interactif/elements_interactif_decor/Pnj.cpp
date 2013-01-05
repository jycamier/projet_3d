#include "Pnj.h"
#include "../../utils/point.h"
#include "../../sdlglutils.h"


#include <cmath>

Pnj::Pnj(double x, double y, double z, char direction, string discour) :
		ElementInteractifDecor(x, y, z) {
	this->quadriqueTete = gluNewQuadric();
	this->quadriqueTorse = gluNewQuadric();
	this->quadriqueBrasGauche = gluNewQuadric();
	this->quadriqueBrasDroit = gluNewQuadric();
	this->quadriqueJambeGauche = gluNewQuadric();
	this->quadriqueJambeDroite = gluNewQuadric();
	this->talk = false;


	// strcpy( (char*) this->blabla, "Hello World" );
	this->blabla = discour;
	

	texture_happy = loadTexture("textures/smilet_happy.jpg");
	texture_jambes = loadTexture("textures/texture_jean.jpg");
	texture_torse = loadTexture("textures/texture_torse.jpg");

	if (direction == 'N') {
		this->orientation = 0;
	} else if (direction == 'S') {
		this->orientation = -180;
	} else if (direction == 'E') {
		this->orientation = 90;
	} else if (direction == 'O') {
		this->orientation = -90;
	}

}

void Pnj::parler()
{
	if (this->talk)
	{
		this->talk = false;
	}
	else
	{
		this->talk = true;
	}

}

void Pnj::interaction()
{
	this->parler();
}

void Pnj::draw() {

	// unsigned char tmp[100] = "toto\n";
	if (this->talk)
	{
		glRasterPos3i(this->position->x,this->position->y + 13,this->position->z);
		glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
		const unsigned char* toto = reinterpret_cast<const unsigned char*>(this->blabla.c_str());
		glutBitmapString(GLUT_BITMAP_HELVETICA_18, toto);
		glColor3ub(223, 223, 223);
	}

	glPushMatrix();
	gluQuadricTexture(quadriqueTete, GL_TRUE);

	glBindTexture(GL_TEXTURE_2D, texture_happy);

	gluQuadricDrawStyle(quadriqueTete, GLU_FILL);
	glTranslated(this->position->x, this->position->y + 9, this->position->z);
	glRotatef(-90, 1, 0, 0);
	glRotatef(-this->orientation, 0, 0, 1);
	gluSphere(this->quadriqueTete, 2.45, 25, 25);

	glPopMatrix();

	glPushMatrix();

	gluQuadricTexture(quadriqueTorse,GL_TRUE);
	glBindTexture(GL_TEXTURE_2D, texture_torse);


	gluQuadricDrawStyle(quadriqueTorse, GLU_FILL);
	glTranslated(this->position->x, this->position->y + 3.5, this->position->z);
	glRotatef(-90, 1, 0, 0);
	glRotatef(-this->orientation, 0, 0, 1);
	gluCylinder(this->quadriqueTorse, 1, 1, 6, 25, 25);

	glPopMatrix();

	glPushMatrix();

	gluQuadricDrawStyle(quadriqueBrasDroit, GLU_FILL);
	glTranslated(this->position->x, this->position->y + 6.5, this->position->z);
	glRotatef(this->orientation - 90, 0, 1, 0);
	glRotatef(50, 1, 0, 0);
	gluCylinder(this->quadriqueBrasDroit, 0.5, 0.5, 5, 25, 25);

	glPopMatrix();

	glPushMatrix();

	gluQuadricDrawStyle(quadriqueBrasGauche, GLU_FILL);
	glTranslated(this->position->x, this->position->y + 6.5, this->position->z);
	glRotatef(this->orientation + 90, 0, 1, 0);
	glRotatef(50, 1, 0, 0);
	gluCylinder(this->quadriqueBrasDroit, 0.5, 0.5, 5, 25, 25);

	glPopMatrix();

	glPushMatrix();
	
	gluQuadricTexture(quadriqueJambeGauche,GL_TRUE);
	glBindTexture(GL_TEXTURE_2D, texture_jambes);

	gluQuadricDrawStyle(quadriqueJambeGauche, GLU_FILL);
	glTranslated(this->position->x, this->position->y + 3.5, this->position->z);
	glRotatef( this->orientation - 90, 0, 1, 0 );
	glRotatef( 60, 1, 0, 0 );
	gluCylinder(this->quadriqueJambeGauche,0.8,0.8,5,25,25);
	
	glPopMatrix();

	glPushMatrix();

	gluQuadricTexture(quadriqueJambeDroite,GL_TRUE);
	glBindTexture(GL_TEXTURE_2D, texture_jambes);

	gluQuadricDrawStyle(quadriqueJambeDroite, GLU_FILL);
	glTranslated(this->position->x, this->position->y + 3.5, this->position->z);
	glRotatef(this->orientation + 90, 0, 1, 0);
	glRotatef(60, 1, 0, 0);
	gluCylinder(this->quadriqueJambeDroite, 0.8, 0.8, 5, 25, 25);

	glPopMatrix();

	//création hitbox
	this->createHitboxes(this->position->x - 5 * sin(60 * M_PI / 180),
			this->position->y, this->position->z - 2.45,
			((this->position->x + 5) - (this->position->x - 5))
					* sin(60 * M_PI / 180), 11.45, 4.90);

	this->hitboxCreated = true;
}

Pnj::~Pnj() {

}

