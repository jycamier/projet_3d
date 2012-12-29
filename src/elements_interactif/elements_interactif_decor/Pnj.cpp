#include "Pnj.h"
#include "../../utils/point.h"
#include "../../sdlglutils.h"


Pnj::Pnj(double x, double y, double z) : ElementInteractifDecor (x,y,z)  
{
		this->quadriqueTete = gluNewQuadric();
		this->quadriqueTorse = gluNewQuadric();
		texture_happy = loadTexture("textures/smilet_happy.jpg");

}


void Pnj::draw()
{
	glPushMatrix();
	gluQuadricTexture(quadriqueTete,GL_TRUE);
	
	glBindTexture(GL_TEXTURE_2D, texture_happy);
	
	gluQuadricDrawStyle(quadriqueTete, GLU_FILL);
	glTranslated(this->position->x, this->position->y + 10, this->position->z);
	glRotatef( -90, 1, 0, 0 );
	gluSphere(this->quadriqueTete,2.45,25,25);

	glPopMatrix();	

	glPushMatrix();
	
	gluQuadricDrawStyle(quadriqueTorse, GLU_FILL);
	glTranslated(this->position->x, this->position->y, this->position->z);
	glRotatef( -90, 1, 0, 0 );
	gluCylinder(this->quadriqueTorse,1,1,10,25,25);
	glPopMatrix();

}


Pnj::~Pnj()
{

}



	




