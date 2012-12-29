#include <GL/gl.h>
#include <GL/glu.h>
#include "Pilier.h"

Pilier::Pilier(double x, double y, double z, int text, double ep, double haut) : ElementDecor(x, y, z)
{
	quadrique = gluNewQuadric();
	this->texture = text;
	this->epaisseur = ep;
	this->hauteur = haut;

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
		gluCylinder(quadrique,this->epaisseur,this->epaisseur,this->hauteur,20,20);
		glPopMatrix();


		gluQuadricTexture(quadrique,GL_TRUE);
		glBindTexture(GL_TEXTURE_2D, this->texture);
		glColor3ub(168,163,165);		

		glPushMatrix();
		glTranslated(position->x,position->y,position->z); // choix de l’emplacement futur du disque
		glRotatef( 90, 1, 0, 0 );
		gluDisk(quadrique,0, this->epaisseur, 20, 20);
		gluQuadricDrawStyle(quadrique, GLU_FILL);
		glPopMatrix();
}