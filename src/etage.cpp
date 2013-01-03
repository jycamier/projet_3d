#include <GL/gl.h>
#include <GL/glu.h>
#include <vector> 
#include "sdlglutils.h"
#include "elements/element_decor.h"
#include "etage.h"
#include "elements_decor/Mur.h"
#include "elements_interactif/elements_interactif_decor/Elevator.h"
#include "elements_interactif/elements_interactif_decor/Button.h"

using namespace std;

Etage::Etage(double x, double y, double z, int plafond, int sol, int murs, double base_etage)
{
	this->longueur_etage = x;
	this->hauteur_etage = y;
	this->largeur_etage = z;
	this->texture_plafond = plafond;
	this->texture_murs = murs;
	this->texture_sol = sol;
	this->base = base_etage;

	int texture_happy = loadTexture("textures/smilet_happy.jpg");
	int longueur_porte_ascenseur = (longueur_etage-10);
	double xButton = longueur_etage-longueur_porte_ascenseur+2;
	double zButton = longueur_etage-26;

	this->elevator = new Elevator(longueur_etage-longueur_porte_ascenseur,base,longueur_etage-25,20,25,15);
	this->addElementDecorInteractif(elevator);
	
	this->addElementDecorInteractif(new Button(xButton,7,zButton,'z',0.6,texture_happy,elevator));

	// mur à gauche de l'ascenseur
	vector<Point> points;

	points.push_back(Point (longueur_etage-10,base,longueur_etage-25));
	this->addElementDecor(new Mur(longueur_etage,base,longueur_etage-25,points,this->hauteur_etage,texture_murs));
	points.clear();


	points.push_back(Point (longueur_etage-longueur_porte_ascenseur,base,longueur_etage-25));
	points.push_back(Point (longueur_etage-longueur_porte_ascenseur,base,longueur_etage));
	this->addElementDecor(new Mur(longueur_etage-20,base,longueur_etage-25,points,this->hauteur_etage,texture_murs));
	points.clear();

	//mur à droite de l'ascenseur
	points.push_back(Point (-(longueur_etage-10),base,longueur_etage-25));
	this->addElementDecor(new Mur(-longueur_etage,base,longueur_etage-25,points,this->hauteur_etage,texture_murs));
	points.clear();

	points.push_back(Point (-(longueur_etage-longueur_porte_ascenseur),base,longueur_etage-25));
	points.push_back(Point (-(longueur_etage-longueur_porte_ascenseur),base,longueur_etage));
	this->addElementDecor(new Mur(-(longueur_etage-20),base,longueur_etage-25,points,this->hauteur_etage,texture_murs));
	points.clear();


}

void Etage::addElementDecor(ElementDecor* element)
{
	this->decor.push_back(element);
	this->elements.push_back(element);
}

void Etage::addElementDecorInteractif(ElementInteractifDecor* element)
{
	this->decorInteractif.push_back(element);	
	this->elements.push_back(element);
}

void Etage::removeElementDecor(ElementDecor* element)
{
	// this->decor.erase(element);
}

void Etage::drawSurface()
{
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
}


void Etage::drawElementsDecor()
{
	int i = 0;
	while (i < this->decor.size())
	{
		this->decor[i]->draw();
		i++;
	}

	i = 0;
	while (i < this->decorInteractif.size())
	{
		this->decorInteractif[i]->draw();
		i++;
	}

}


// void Etage::drawElevatorDoor()
// {
// 	int i = 0;
// 	while (i < this->elevatorDoors.size())
// 	{
// 		this->elevatorDoors[i]->draw();
// 		i++;
// 	}

// }

void Etage::openElevatorDoors()
{
	this->elevator->close();
}

void Etage::closeElevatorDoors()
{

	this->elevator->open();
}

void Etage::draw()
{

	int longueur_porte_ascenseur = (longueur_etage-10);
	this->drawSurface();
	this->drawElementsDecor();
	glColor3ub(255,0,0);
	this->elevator->draw();
	

	//////////////////////////////////////////////////////////////////////////
	glBegin(GL_QUADS);		
	// glColor3ub(223,223,223);
	glColor3ub(0,0,255);

	glVertex3d(longueur_etage,0,largeur_etage);
	glVertex3d(longueur_etage-10,0,largeur_etage);
	glVertex3d(longueur_etage-10,0,largeur_etage-25);
	glVertex3d(longueur_etage,0,largeur_etage-25);
					
	glEnd() ;

	glBegin(GL_QUADS);		
	// glColor3ub(223,223,223);
	glColor3ub(0,0,255);

	glVertex3d(longueur_etage-10,0,largeur_etage-10);
	glVertex3d(longueur_etage-longueur_porte_ascenseur,0,largeur_etage-10);
	glVertex3d(longueur_etage-longueur_porte_ascenseur,0,largeur_etage-25);
	glVertex3d(longueur_etage-10,0,largeur_etage-25);
					
	glEnd() ;

	glBegin(GL_QUADS);		
	// glColor3ub(223,223,223);
	glColor3ub(0,0,255);

	glVertex3d(longueur_etage-43,0,largeur_etage);
	glVertex3d(longueur_etage-longueur_porte_ascenseur,0,largeur_etage);
	glVertex3d(longueur_etage-longueur_porte_ascenseur,0,largeur_etage-10);
	glVertex3d(longueur_etage-43,0,largeur_etage-10);
					
	glEnd() ;

	//***********************************************************//
	glBegin(GL_QUADS);		
	// glColor3ub(223,223,223);
	glColor3ub(0,0,255);

	glVertex3d(-longueur_etage,0,largeur_etage);
	glVertex3d(-longueur_etage+10,0,largeur_etage);
	glVertex3d(-longueur_etage+10,0,largeur_etage-25);
	glVertex3d(-longueur_etage,0,largeur_etage-25);
					
	glEnd() ;

	glBegin(GL_QUADS);		
	// glColor3ub(223,223,223);
	glColor3ub(0,0,255);

	glVertex3d(-longueur_etage+10,0,largeur_etage-10);
	glVertex3d(-longueur_etage+longueur_porte_ascenseur,0,largeur_etage-10);
	glVertex3d(-longueur_etage+longueur_porte_ascenseur,0,largeur_etage-25);
	glVertex3d(-longueur_etage+10,0,largeur_etage-25);
					
	glEnd() ;

	glBegin(GL_QUADS);		
	// glColor3ub(223,223,223);
	glColor3ub(0,0,255);

	glVertex3d(-longueur_etage+43,0,largeur_etage);
	glVertex3d(-longueur_etage+longueur_porte_ascenseur,0,largeur_etage);
	glVertex3d(-longueur_etage+longueur_porte_ascenseur,0,largeur_etage-10);
	glVertex3d(-longueur_etage+43,0,largeur_etage-10);
					
	glEnd() ;

}

