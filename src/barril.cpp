#include <GL/gl.h>
#include <GL/glu.h>
#include "barril.h"

Barril::Barril(double x, double y, double z)
{

	this->x = x;
	this->y = y;
	this->z = z;
}


void Barril::draw(GLUquadricObj * quad1, int id_texture)
{
		
		gluQuadricTexture(quad1,GL_TRUE);
		glBindTexture(GL_TEXTURE_2D, id_texture);
		glColor3ub(168,163,165);		

		gluQuadricDrawStyle(quad1, GLU_FILL);
		
		glPushMatrix();
		glTranslated(this->x,this->y,this->z); // choix de l’emplacement cylindre
		glRotatef( -90, 1, 0, 0 );
		gluCylinder(quad1,2,2,20,20,20);
		glPopMatrix();


		gluQuadricTexture(quad1,GL_TRUE);
		glBindTexture(GL_TEXTURE_2D, id_texture);
		glColor3ub(168,163,165);		

		glPushMatrix();
		glTranslated(this->x,this->y,this->z); // choix de l’emplacement futur du disque
		glRotatef( 90, 1, 0, 0 );
		gluDisk(quad1,0, 1, 20, 20);
		gluQuadricDrawStyle(quad1, GLU_FILL);
		glPopMatrix();
}