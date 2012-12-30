#include "Porte.h"
#include "../../utils/point.h"
#include "../../sdlglutils.h"


Porte::Porte(double x, double y, double z, char direction, double taille, double hauteur) : ElementInteractifDecor (x,y,z)  
{
	this->taillePorte = taille;
	this->height = hauteur;
	vector<Point> points;
	this->orientation = direction;

	this->texture_porte = loadTexture("textures/crate2.jpg");

	if (direction == 'x')
	{
		points.push_back(Point(this->position->x + 10,this->position->y,this->position->z));
		this->door = new Mur(this->position->x,this->position->y,this->position->z,points,this->height,texture_porte);
	}
	else
	{
		points.push_back(Point(this->position->x,this->position->y,this->position->z + 10));
		this->door = new Mur(this->position->x,this->position->y,this->position->z,points,this->height,texture_porte);
	}

	this->open = false;

}


void Porte::draw()
{
	this->door->draw();

}

void Porte::openDoor()
{
	// if (!this->open)
	// {
	// 	if (this->orientation == 'x')
	// 	{
	// 		this->door->coordinates[0]->x 
	// 		this->door->coordinates[0]->y
	// 		this->door->coordinates[0]->z = 
	// 	}

	// 	this->open = true;
	// }

}

void Porte::closeDoor()
{
	// if (this->open)
	// {

	// 	this->open = false;
	// }
}


Porte::~Porte()
{

}



	




