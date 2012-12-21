#include <GL/gl.h>
#include <GL/glu.h>
#include "Pilier.h"

Pilier::Pilier(double x, double y, double z, int text) : ElementDecor(x, y, z)
{
	quadrique = gluNewQuadric();
	this->texture = text;

}


void Pilier::draw()
{
		
		gluQuadricTexture(quadrique,GL_TRUE);
		glBindTexture(GL_TEXTURE_2D, this->texture);
		glColor3ub(168,163,165);		

		gluQuadricDrawStyle(quadrique, GLU_FILL);
		
		glPushMatrix();
		glTranslated(position->x,position->y,position->z); // choix de l’emplacement cylindre
		glRotatef( -90, 1, 0, 0 );
		gluCylinder(quadrique,2,2,20,20,20);
		glPopMatrix();


		gluQuadricTexture(quadrique,GL_TRUE);
		glBindTexture(GL_TEXTURE_2D, this->texture);
		glColor3ub(168,163,165);		

		glPushMatrix();
		glTranslated(position->x,position->y,position->z); // choix de l’emplacement futur du disque
		glRotatef( 90, 1, 0, 0 );
		gluDisk(quadrique,0, 1, 20, 20);
		gluQuadricDrawStyle(quadrique, GLU_FILL);
		glPopMatrix();
}