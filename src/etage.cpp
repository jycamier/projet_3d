#include <GL/gl.h>
#include <GL/glu.h>
#include "etage.h"

Etage::Etage(int x, int y, int z, int plafond, int sol, int murs)
{
	this->longueur_etage = x;
	this->hauteur_etage = y;
	this->largeur_etage = z;
	this->texture_plafond = plafond;
	this->texture_murs = murs;
	this->texture_sol = sol;

}

void Etage::draw(int texture_ascenseur)
{
	//plate-forme
	glBindTexture(GL_TEXTURE_2D, texture_sol);

	glBegin(GL_QUADS);		
	glColor3ub(168,163,165);

	glTexCoord2d(20,10); glVertex3d(-longueur_etage,0,-largeur_etage);
	glTexCoord2d(10,10); glVertex3d(-longueur_etage,0,largeur_etage);
	glTexCoord2d(10,20); glVertex3d(longueur_etage,0,largeur_etage);
	glTexCoord2d(20,20); glVertex3d(longueur_etage,0,-largeur_etage);
		
	glEnd() ;

	//plafond
		glBindTexture(GL_TEXTURE_2D, texture_plafond);

		glBegin(GL_QUADS);		
		glColor3ub(223,223,223);

		glTexCoord2d(15,7); glVertex3d(-longueur_etage,hauteur_etage,-largeur_etage);
		glTexCoord2d(7,7); glVertex3d(-longueur_etage,hauteur_etage,largeur_etage);
		glTexCoord2d(7,15); glVertex3d(longueur_etage,hauteur_etage,largeur_etage);
		glTexCoord2d(15,15); glVertex3d(longueur_etage,hauteur_etage,-largeur_etage);
		
		glEnd() ;

		//mur 1
		glBindTexture(GL_TEXTURE_2D, texture_murs);		
		glBegin(GL_QUADS);
		glColor3ub(223,223,223);

		glTexCoord2d(5,2); glVertex3d(-longueur_etage,0,-largeur_etage);
		glTexCoord2d(2,2); glVertex3d(-longueur_etage,0,largeur_etage);
		glTexCoord2d(2,5); glVertex3d(-longueur_etage,hauteur_etage,largeur_etage);
		glTexCoord2d(5,5); glVertex3d(-longueur_etage,hauteur_etage,-largeur_etage);
		
		glEnd() ;

		//mur 2
		glBindTexture(GL_TEXTURE_2D, texture_murs);		
		glBegin(GL_QUADS);

		glTexCoord2d(5,2); glVertex3d(longueur_etage,0,-largeur_etage);
		glTexCoord2d(2,2); glVertex3d(longueur_etage,0,largeur_etage);
		glTexCoord2d(2,5); glVertex3d(longueur_etage,hauteur_etage,largeur_etage);
		glTexCoord2d(5,5); glVertex3d(longueur_etage,hauteur_etage,-largeur_etage);

		glEnd() ;


		//mur 3
		glBindTexture(GL_TEXTURE_2D, texture_murs);		
		glBegin(GL_QUADS);

		glTexCoord2d(5,2); glVertex3d(longueur_etage,0,-largeur_etage);
		glTexCoord2d(2,2); glVertex3d(-longueur_etage,0,-largeur_etage);
		glTexCoord2d(2,5); glVertex3d(-longueur_etage,hauteur_etage,-largeur_etage);
		glTexCoord2d(5,5); glVertex3d(longueur_etage,hauteur_etage,-largeur_etage);
		
		glEnd() ;

		// mur 4
		glBindTexture(GL_TEXTURE_2D, texture_murs);		
		glBegin(GL_QUADS);

		glTexCoord2d(5,2); glVertex3d(longueur_etage,0,largeur_etage);
		glTexCoord2d(2,2); glVertex3d(-longueur_etage,0,largeur_etage);
		glTexCoord2d(2,5); glVertex3d(-longueur_etage,hauteur_etage,largeur_etage);
		glTexCoord2d(5,5); glVertex3d(longueur_etage,hauteur_etage,largeur_etage);
		
		glEnd() ;

		// escalier ascenseur
		/////////////////////////////////////////////////////////
		
		//mur de gauche
		glBindTexture(GL_TEXTURE_2D, texture_murs);		
		glBegin(GL_QUADS);
		glColor3ub(223,223,223);

		glTexCoord2d(5,2); glVertex3d(60,0,45);
		glTexCoord2d(2,2); glVertex3d(7,0,45);
		glTexCoord2d(2,5); glVertex3d(7,hauteur_etage,45);
		glTexCoord2d(5,5); glVertex3d(60,hauteur_etage,45);

		glEnd() ;

		//mur de droite
		glBindTexture(GL_TEXTURE_2D, texture_murs);		
		glBegin(GL_QUADS);

		glTexCoord2d(5,2); glVertex3d(-60,0,45);
		glTexCoord2d(2,2); glVertex3d(-7,0,45);
		glTexCoord2d(2,5); glVertex3d(-7,hauteur_etage,45);
		glTexCoord2d(5,5); glVertex3d(-60,hauteur_etage,45);

		glEnd() ;

		//mur vertical gauche
		glBindTexture(GL_TEXTURE_2D, texture_murs);		
		glBegin(GL_QUADS);

		glTexCoord2d(5,2); glVertex3d(7,0,45);
		glTexCoord2d(2,2); glVertex3d(7,0,60);
		glTexCoord2d(2,5); glVertex3d(7,hauteur_etage,60);
		glTexCoord2d(5,5); glVertex3d(7,hauteur_etage,45);

		glEnd() ;

		//mur vertical droit
		glBindTexture(GL_TEXTURE_2D, texture_murs);		
		glBegin(GL_QUADS);

		glTexCoord2d(5,2); glVertex3d(-7,0,45);
		glTexCoord2d(2,2); glVertex3d(-7,0,60);
		glTexCoord2d(2,5); glVertex3d(-7,hauteur_etage,60);
		glTexCoord2d(5,5); glVertex3d(-7,hauteur_etage,45);

		glEnd() ;

		//porte ascenseur
		glBindTexture(GL_TEXTURE_2D, texture_ascenseur);		
		glBegin(GL_QUADS);

		glTexCoord2d(1,0); glVertex3d(-7,0,45);
		glTexCoord2d(0,0); glVertex3d(7,0,45);
		glTexCoord2d(0,1); glVertex3d(7,hauteur_etage,45);
		glTexCoord2d(1,1); glVertex3d(-7,hauteur_etage,45);

		glEnd() ;
}