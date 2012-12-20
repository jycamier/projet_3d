#include <GL/gl.h>
#include <GL/glu.h>
#include "Pilier.h"

Pilier::Pilier(double x, double y, double z) : ElementDecor(x, y, z)
{
	quadrique = gluNewQuadric();
}


void Pilier::draw(int id_texture)
{
		
		gluQuadricTexture(quadrique,GL_TRUE);
		glBindTexture(GL_TEXTURE_2D, id_texture);
		glColor3ub(168,163,165);		

		gluQuadricDrawStyle(quadrique, GLU_FILL);
		
		glPushMatrix();
		glTranslated(position->x,position->y,position->z); // choix de l’emplacement cylindre
		glRotatef( -90, 1, 0, 0 );
		gluCylinder(quadrique,2,2,20,20,20);
		glPopMatrix();


		gluQuadricTexture(quadrique,GL_TRUE);
		glBindTexture(GL_TEXTURE_2D, id_texture);
		glColor3ub(168,163,165);		

		glPushMatrix();
		glTranslated(position->x,position->y,position->z); // choix de l’emplacement futur du disque
		glRotatef( 90, 1, 0, 0 );
		gluDisk(quadrique,0, 1, 20, 20);
		gluQuadricDrawStyle(quadrique, GLU_FILL);
		glPopMatrix();
}