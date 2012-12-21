#include <GL/gl.h>
#include <GL/glu.h>
#include <vector> 
#include "sdlglutils.h"
#include "elements/element_decor.h"
#include "etage.h"
#include "elements_decor/Mur.h"


Etage::Etage(double x, double y, double z, int plafond, int sol, int murs, double base_etage)
{
	this->longueur_etage = x;
	this->hauteur_etage = y;
	this->largeur_etage = z;
	this->texture_plafond = plafond;
	this->texture_murs = murs;
	this->texture_sol = sol;
	this->base = base_etage;

}

void Etage::addElementDecor(ElementDecor* element)
{
	this->decor.push_back(element);
}

void Etage::removeElementDecor(ElementDecor* element)
{
	// this->decor.erase(element);
}

void Etage::draw(int texture_ascenseur)
{

	int i = 0;
	while (i < this->decor.size())
	{
		this->decor[i]->draw();
		// printf("%s\n", this->decor[i]);
		i++;
	}

	int longueur_porte_ascenseur = (longueur_etage-10);

	//plate-forme
	glBindTexture(GL_TEXTURE_2D, texture_sol);

	glBegin(GL_QUADS);		
	glColor3ub(223,223,223);

	glTexCoord2d(20,10); glVertex3d(-longueur_etage,base,-largeur_etage);
	glTexCoord2d(10,10); glVertex3d(-longueur_etage,base,largeur_etage-25);
	glTexCoord2d(10,20); glVertex3d(longueur_etage,base,largeur_etage-25);
	glTexCoord2d(20,20); glVertex3d(longueur_etage,base,-largeur_etage);	
	glEnd() ;


	//plafond
	glBindTexture(GL_TEXTURE_2D, texture_plafond);
	glBegin(GL_QUADS);		
	glColor3ub(223,223,223);

	glTexCoord2d(15,7); glVertex3d(-longueur_etage,hauteur_etage,-largeur_etage);
	glTexCoord2d(7,7); glVertex3d(-longueur_etage,hauteur_etage,largeur_etage-25);
	glTexCoord2d(7,15); glVertex3d(longueur_etage,hauteur_etage,largeur_etage-25);
	glTexCoord2d(15,15); glVertex3d(longueur_etage,hauteur_etage,-largeur_etage);
		
	glEnd() ;

	//mur 1
	glBindTexture(GL_TEXTURE_2D, texture_murs);		
	glBegin(GL_QUADS);
	glColor3ub(223,223,223);

	glTexCoord2d(5,2); glVertex3d(-longueur_etage,base,-largeur_etage);
	glTexCoord2d(2,2); glVertex3d(-longueur_etage,base,largeur_etage);
	glTexCoord2d(2,5); glVertex3d(-longueur_etage,hauteur_etage,largeur_etage);
	glTexCoord2d(5,5); glVertex3d(-longueur_etage,hauteur_etage,-largeur_etage);
		
	glEnd() ;

	//mur 2
	glBindTexture(GL_TEXTURE_2D, texture_murs);		
	glBegin(GL_QUADS);

	glTexCoord2d(5,2); glVertex3d(longueur_etage,base,-largeur_etage);
	glTexCoord2d(2,2); glVertex3d(longueur_etage,base,largeur_etage);
	glTexCoord2d(2,5); glVertex3d(longueur_etage,hauteur_etage,largeur_etage);
	glTexCoord2d(5,5); glVertex3d(longueur_etage,hauteur_etage,-largeur_etage);

	glEnd() ;


	//mur 3
	glBindTexture(GL_TEXTURE_2D, texture_murs);		
	glBegin(GL_QUADS);

	glTexCoord2d(5,2); glVertex3d(longueur_etage,base,-largeur_etage);
	glTexCoord2d(2,2); glVertex3d(-longueur_etage,base,-largeur_etage);
	glTexCoord2d(2,5); glVertex3d(-longueur_etage,hauteur_etage,-largeur_etage);
	glTexCoord2d(5,5); glVertex3d(longueur_etage,hauteur_etage,-largeur_etage);
		
	glEnd() ;

	// mur 4
	glBindTexture(GL_TEXTURE_2D, texture_murs);		
	glBegin(GL_QUADS);

	glTexCoord2d(5,2); glVertex3d(longueur_etage,base,largeur_etage);
	glTexCoord2d(2,2); glVertex3d(-longueur_etage,base,largeur_etage);
	glTexCoord2d(2,5); glVertex3d(-longueur_etage,hauteur_etage,largeur_etage);
	glTexCoord2d(5,5); glVertex3d(longueur_etage,hauteur_etage,largeur_etage);
		
	glEnd() ;

	// portes et ascenseur
	/////////////////////////////////////////////////////////
	// mur de gauche
	vector<Point> points;

	points.push_back(Point (longueur_etage-10,base,longueur_etage-25));
	Mur* mur_gauche1 = new Mur(longueur_etage,base,longueur_etage-25,points,this->hauteur_etage,texture_murs);
	mur_gauche1->draw();
	points.clear();


	points.push_back(Point (longueur_etage-longueur_porte_ascenseur,base,longueur_etage-25));
	points.push_back(Point (longueur_etage-longueur_porte_ascenseur,base,longueur_etage));
	Mur* mur_gauche2 = new Mur(longueur_etage-20,base,longueur_etage-25,points,this->hauteur_etage,texture_murs);
	mur_gauche2->draw();
	points.clear();

	//mur de droite
	points.push_back(Point (-(longueur_etage-10),base,longueur_etage-25));
	Mur* mur_droite1 = new Mur(-longueur_etage,base,longueur_etage-25,points,this->hauteur_etage,texture_murs);
	mur_droite1->draw();
	points.clear();


	points.push_back(Point (-(longueur_etage-longueur_porte_ascenseur),base,longueur_etage-25));
	points.push_back(Point (-(longueur_etage-longueur_porte_ascenseur),base,longueur_etage));
	Mur* mur_droite2 = new Mur(-(longueur_etage-20),base,longueur_etage-25,points,this->hauteur_etage,texture_murs);
	mur_droite2->draw();
	points.clear();


	//porte ascenseur
	glBindTexture(GL_TEXTURE_2D, texture_ascenseur);		
	glBegin(GL_QUADS);

	glTexCoord2d(1,0); glVertex3d(-(longueur_etage-longueur_porte_ascenseur),base,longueur_etage-25);
	glTexCoord2d(0,0); glVertex3d(longueur_etage-longueur_porte_ascenseur,base,longueur_etage-25);
	glTexCoord2d(0,1); glVertex3d(longueur_etage-longueur_porte_ascenseur,hauteur_etage,longueur_etage-25);
	glTexCoord2d(1,1); glVertex3d(-(longueur_etage-longueur_porte_ascenseur),hauteur_etage,longueur_etage-25);

	glEnd() ;
	//////////////////////////////////////////////////////////////////////////
}