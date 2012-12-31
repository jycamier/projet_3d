#include "Porte.h"
#include "../../utils/point.h"
#include "../../sdlglutils.h"


Porte::Porte(double x, double y, double z, char direction, double taille, double hauteur) : ElementInteractifDecor (x,y,z)  
{
	this->taillePorte = taille;
	this->height = hauteur;
	vector<Point> points;
	points.clear();
	this->orientation = direction;

	this->texture_porte = loadTexture("textures/crate2.jpg");

	if (direction == 'x')
	{
		points.push_back(Point(this->position->x + this->taillePorte,this->position->y,this->position->z));
	}
	else if (direction == 'X')
	{
		points.push_back(Point(this->position->x - this->taillePorte,this->position->y,this->position->z));
	}
	else if (direction == 'z')
	{
		points.push_back(Point(this->position->x,this->position->y,this->position->z + this->taillePorte));
	}
	else
	{
		points.push_back(Point(this->position->x,this->position->y,this->position->z - this->taillePorte));	
	}

	this->door = new Mur(this->position->x,this->position->y,this->position->z,points,this->height,texture_porte);
	points.clear();
	this->open = false;

}


void Porte::draw()
{
	this->door->draw();

}

void Porte::interaction()
{
	if (!this->open)
	{
		this->openDoor();
	}
	else
	{
		this->closeDoor();
	}
}

void Porte::openDoor()
{

	double tempX = this->door->coordinates[0].x;
	double tempZ = this->door->coordinates[0].z;

	if (this->orientation == 'x')
	{
		this->door->coordinates[1].x = tempX; 
		this->door->coordinates[1].z = -tempX; 
		// this->door->coordinates[1];
	}
	else if (this->orientation == 'X')
	{
		this->door->coordinates[1].x = this->door->coordinates[0].x; 
		this->door->coordinates[1].z = this->door->coordinates[0].x;
	}
	else if (this->orientation == 'z')
	{
		this->door->coordinates[1].x = this->height;
		this->door->coordinates[1].z = tempZ;
		
	}
	else
	{

	}

	this->open = true;
}

void Porte::closeDoor()
{
	double tempX = this->door->coordinates[0].x;
	if (this->orientation == 'x' || this->orientation == 'X')
	{	
		this->door->coordinates[1].x = tempX * 2; 
		this->door->coordinates[1].z = this->door->coordinates[0].z; 
	}
	else
	{
 
	}


	this->open = false;
	
}


Porte::~Porte()
{

}



	




