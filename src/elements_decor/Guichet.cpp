#include "Guichet.h"
#include <vector> 
#include <iostream> 
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

using namespace std;

Guichet::Guichet(double x, double y, double z,double longueur, double largeur, double hauteur) : ElementDecor(x, y, z)
{
	this->heigth = hauteur;
	this->length = longueur;
	this->width = largeur;
	int espace = width + 8;

	this->personnage =	new Pnj(this->position->x - this->width/2,0,this->position->z - longueur/2);

	vector<Point> points;

	points.push_back(Point(this->position->x - length,this->position->y,this->position->z));
	points.push_back(Point(this->position->x - length,this->position->y,this->position->z - width/2));
	this->walls.push_back(new Mur(this->position->x,this->position->y,this->position->z,points,this->heigth + 2,0));	

	points.clear();

	points.push_back(Point(this->position->x - length,this->position->y,this->position->z - espace));
	points.push_back(Point(this->position->x - length,this->position->y,this->position->z - (espace-width/2)));
	this->walls.push_back(new Mur(this->position->x,this->position->y,this->position->z - espace,points,this->heigth + 2,0));

	points.clear();

	points.push_back(Point(this->position->x - length,this->position->y-5,this->position->z - width/2));
	this->walls.push_back(new Mur(this->position->x - length,this->position->y-5,this->position->z - (espace-width/2),points,this->heigth,0));		

	points.clear();

	points.push_back(Point(this->position->x - length,this->position->y + 10,this->position->z - width/2));
	this->walls.push_back(new Mur(this->position->x - length,this->position->y + 10,this->position->z - (espace-width/2),points,2,0));		

	this->bars.push_back(new Pilier(this->position->x - length,this->position->y,(this->position->z - width/2)-1,0,0.2,10));
	this->bars.push_back(new Pilier(this->position->x - length,this->position->y,(this->position->z - width/2)-2,0,0.2,10));
	this->bars.push_back(new Pilier(this->position->x - length,this->position->y,(this->position->z - width/2)-3,0,0.2,10));
	this->bars.push_back(new Pilier(this->position->x - length,this->position->y,(this->position->z - width/2)-4,0,0.2,10));
	this->bars.push_back(new Pilier(this->position->x - length,this->position->y,(this->position->z - width/2)-5,0,0.2,10));
	this->bars.push_back(new Pilier(this->position->x - length,this->position->y,(this->position->z - width/2)-6,0,0.2,10));
	this->bars.push_back(new Pilier(this->position->x - length,this->position->y,(this->position->z - width/2)-7,0,0.2,10));

}


void Guichet::draw()
{
	int i = 0;
	int espace = width + 8;

	while (i < this->walls.size())
	{
		this->walls[i]->draw();
		i++;
	}

	i = 0;
	
	while (i < this->bars.size())
	{
		this->bars[i]->draw();
		i++;
	}

	glBegin(GL_QUADS);		
	glColor3ub(255,0,255);

	glTexCoord2d(20,10); glVertex3d(this->position->x,this->heigth + 2,this->position->z - espace);
	glTexCoord2d(10,10); glVertex3d(this->position->x - length,this->heigth +2,this->position->z - espace);
	glTexCoord2d(10,20); glVertex3d(this->position->x - length,this->heigth + 2,this->position->z);
	glTexCoord2d(20,20); glVertex3d(this->position->x,this->heigth + 2,this->position->z);	
	
	glEnd() ;	
	glColor3ub(223,223,223);

	this->personnage->draw();


}

Guichet::~Guichet()
{

}