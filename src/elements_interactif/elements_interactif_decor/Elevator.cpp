#include "Elevator.h"
#include "../../utils/point.h"
#include "../../sdlglutils.h"
#include <pthread.h>

using namespace std;

Elevator::Elevator(double x, double y, double z, double longueur, double largeur, double hauteur) : ElementInteractifDecor (x,y,z)  
{
	this->lenght = longueur;
	this->width = largeur;
	this->height = hauteur;
	this->createElevatorShaft();
	this->createElevatorDoors();
	isClosed = true;
}

Elevator::~Elevator()
{

}

void Elevator::createElevatorShaft()
{
	vector<Point> points;
	points.push_back(Point(this->position->x,this->position->y,this->position->z + width));
	points.push_back(Point(this->position->x - lenght,this->position->y,this->position->z + width));
	points.push_back(Point(this->position->x - lenght,this->position->y,this->position->z));
	this->walls.push_back(new Mur(this->position->x,this->position->y,this->position->z,points,this->height,0));
}

void Elevator::createElevatorDoors()
{
	vector<Point> points;
	points.push_back(Point(this->position->x - lenght/2,this->position->y,this->position->z+1));
	this->doors.push_back(new Mur(this->position->x,this->position->y,this->position->z+1,points,this->height,0));
	points.clear();

	points.push_back(Point(this->position->x - lenght,this->position->y,this->position->z+1));
	this->doors.push_back(new Mur(this->position->x -lenght/2,this->position->y,this->position->z+1,points,this->height,0));
	points.clear();
}

void Elevator::draw()
{
	int i = 0;

	while (i < this->walls.size())
	{
		this->walls[i]->draw();
		i++;
	}
	i=0;

	glColor3ub(0,0,255);
	while (i < this->doors.size())
	{
		this->doors[i]->draw();	
		i++;
	}
}
	
void Elevator::open()
{
	int i = 0;
	if (isClosed)
	{
		while( i < lenght/2)
		{
			this->doors[0]->coordinates[0].x = this->doors[0]->coordinates[0].x + 1;
			this->doors[0]->coordinates[1].x = this->doors[0]->coordinates[1].x + 1;
			this->doors[1]->coordinates[0].x = this->doors[1]->coordinates[0].x - 1;
			this->doors[1]->coordinates[1].x = this->doors[1]->coordinates[1].x - 1;
			i++;
		}
		isClosed = false;
	}

}


void Elevator::close()
{
	int i = 0;
	if (!isClosed)
	{
		 while( i < lenght/2)
		 {
			this->doors[0]->coordinates[0].x = this->doors[0]->coordinates[0].x - 1;
			this->doors[0]->coordinates[1].x = this->doors[0]->coordinates[1].x - 1;
			this->doors[1]->coordinates[0].x = this->doors[1]->coordinates[0].x + 1;
			this->doors[1]->coordinates[1].x = this->doors[1]->coordinates[1].x + 1;
			i++;
		 }	
		 isClosed = true;
	}

}



