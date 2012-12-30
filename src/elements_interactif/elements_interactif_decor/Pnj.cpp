#include "Pnj.h"
#include "../../utils/point.h"
#include "../../sdlglutils.h"


Pnj::Pnj(double x, double y, double z, char direction) : ElementInteractifDecor (x,y,z)  
{
		this->quadriqueTete = gluNewQuadric();
		this->quadriqueTorse = gluNewQuadric();
		this->quadriqueBrasGauche = gluNewQuadric();
		this->quadriqueBrasDroit = gluNewQuadric();
		this->quadriqueJambeGauche = gluNewQuadric();
		this->quadriqueJambeDroite = gluNewQuadric();

		texture_happy = loadTexture("textures/smilet_happy.jpg");

		if (direction == 'N')
		{
			this->orientation = 0;
		}
		else if (direction == 'S')
		{
			this->orientation = -180;
		}
		else if (direction == 'E')
		{
			this->orientation = 90;
		}
		else if (direction == 'O')
		{
			this->orientation = -90;
		}

}


void Pnj::draw()
{


	glPushMatrix();
	gluQuadricTexture(quadriqueTete,GL_TRUE);
	
	glBindTexture(GL_TEXTURE_2D, texture_happy);
	
	gluQuadricDrawStyle(quadriqueTete, GLU_FILL);
	glTranslated(this->position->x, this->position->y + 9, this->position->z);
	glRotatef( -90, 1, 0, 0 );
	glRotatef( -this->orientation, 0, 0, 1 );//
	gluSphere(this->quadriqueTete,2.45,25,25);

	glPopMatrix();	

	glPushMatrix();
	
	gluQuadricDrawStyle(quadriqueTorse, GLU_FILL);
	glTranslated(this->position->x, this->position->y + 3.5, this->position->z);
	glRotatef( -90, 1, 0, 0 );
	glRotatef( -this->orientation, 0, 0, 1 );//
	gluCylinder(this->quadriqueTorse,1,1,6,25,25);

	glPopMatrix();

	glPushMatrix();
	
	gluQuadricDrawStyle(quadriqueBrasDroit, GLU_FILL);
	glTranslated(this->position->x, this->position->y + 6.5, this->position->z);
	glRotatef( this->orientation - 90, 0, 1, 0 );
	// glRotatef( -90, 0, 1, 0 );//
	glRotatef( 50, 1, 0, 0 );
	gluCylinder(this->quadriqueBrasDroit,0.5,0.5,5,25,25);
	
	glPopMatrix();

	glPushMatrix();
	
	gluQuadricDrawStyle(quadriqueBrasGauche, GLU_FILL);
	glTranslated(this->position->x, this->position->y + 6.5, this->position->z);
	glRotatef( this->orientation + 90, 0, 1, 0 );
	// glRotatef( 90, 0, 1, 0 );//
	glRotatef( 50, 1, 0, 0 );
	gluCylinder(this->quadriqueBrasDroit,0.5,0.5,5,25,25);
	
	glPopMatrix();

	glPushMatrix();
	
	gluQuadricDrawStyle(quadriqueJambeGauche, GLU_FILL);
	glTranslated(this->position->x, this->position->y + 3.5, this->position->z);
	glRotatef( this->orientation - 90, 0, 1, 0 );
	// glRotatef( 90, 0, 1, 0 );
	glRotatef( 60, 1, 0, 0 );
	gluCylinder(this->quadriqueJambeDroite,0.8,0.8,5,25,25);
	
	glPopMatrix();

	glPushMatrix();

	gluQuadricDrawStyle(quadriqueJambeDroite, GLU_FILL);
	glTranslated(this->position->x, this->position->y + 3.5, this->position->z);
	glRotatef( this->orientation + 90, 0, 1, 0 );
	// glRotatef( 90, 0, 1, 0 );
	glRotatef( 60, 1, 0, 0 );
	gluCylinder(this->quadriqueJambeDroite,0.8,0.8,5,25,25);
	
	glPopMatrix();

}


Pnj::~Pnj()
{

}



	




