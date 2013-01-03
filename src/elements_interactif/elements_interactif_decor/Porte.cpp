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
	double tempTaille = this->taillePorte;
	this->texture_porte = loadTexture("textures/crate2.jpg");

	if (direction == 'x')
	{
		if (this->position->x < 0)
		{
			tempTaille = tempTaille * (-1);
		}
			points.push_back(Point(this->position->x + tempTaille,this->position->y,this->position->z));

	}
	else if (direction == 'z')
	{
		if (this->position->z < 0)
		{
			tempTaille = tempTaille * (-1);
		}

			points.push_back(Point(this->position->x,this->position->y,this->position->z + tempTaille));
	}


	this->door = new Mur(this->position->x,this->position->y,this->position->z,points,this->height,texture_porte, true);
	points.clear();
	this->open = true;

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

double Porte::calculerDistance(double val1, double val2)
{

	double distance = 0;

	if (val2 >= 0 && val1 >= 0)
	{
		if (val2 > val1)
		{
			distance = val2 - val1;
		}
		else
		{
			distance = val1 - val2;	
		}
	}
	else if ((val2 < 0 && val1 >= 0)||(val2 >= 0 && val1 < 0))
	{
		distance = abs(val1) + abs(val2);
	}
	else
	{
		if (val2 < val1)
		{
			distance = abs(val2) - abs(val1);
		}
		else
		{
			distance = abs(val2) - abs(val1);	
		}
		
	}

	return distance;
}

void Porte::openDoor()
{
	printf("%s\n", "opening door");
	double tempX = this->door->coordinates[0].x;
	double tempZ = this->door->coordinates[0].z;
	double distance = 0;

	if (this->orientation == 'x')
	{	

		double ecart = this->calculerDistance(this->door->coordinates[0].z,this->door->coordinates[1].z);

		
		this->door->coordinates[1].z = this->door->coordinates[1].z + ecart ;
		

		if (this->door->coordinates[1].x < 0)
		{
				this->door->coordinates[1].x = tempX - ecart;
		}
		else
		{
				this->door->coordinates[1].x = tempX + ecart;		
		}

	}

	else
	{


		printf("%s\n", "opening x1 x2" );
		printf("%f\n", this->door->coordinates[0].x);
		printf("%f\n", this->door->coordinates[1].x);
		printf("%s\n", "opening z1 z2");
		printf("%f\n", this->door->coordinates[0].z);
		printf("%f\n", this->door->coordinates[1].z);

		double ecart = this->calculerDistance(this->door->coordinates[0].x,this->door->coordinates[1].x);
		
		if (this->door->coordinates[1].x < 0)
		{
			this->door->coordinates[1].x = this->door->coordinates[1].x + ecart ;
			this->door->coordinates[1].z = tempZ + ecart;
		}
		else
		{
			this->door->coordinates[1].x = this->door->coordinates[1].x - ecart ;
			this->door->coordinates[1].z = tempZ - ecart;	
		}

		

		printf("%s\n", "ecart" );
		printf("%f\n", ecart);
		printf("%s\n", "after opening x1 x2" );
		printf("%f\n", this->door->coordinates[0].x);
		printf("%f\n", this->door->coordinates[1].x);
		printf("%s\n", "after opening z1 z2");
		printf("%f\n", this->door->coordinates[0].z);
		printf("%f\n", this->door->coordinates[1].z);		


	}

	this->open = true;
}

void Porte::closeDoor()
{
	printf("%s\n", "closing door");
	double tempX = this->door->coordinates[0].x;
	double tempZ = this->door->coordinates[0].z;

	if (this->orientation == 'x')
	{		

		double ecart = this->calculerDistance(this->door->coordinates[0].x,this->door->coordinates[1].x);

		if (this->door->coordinates[1].x < 0)
		{
			this->door->coordinates[1].x = this->door->coordinates[1].x + ecart;
		}
		else
		{
			this->door->coordinates[1].x = this->door->coordinates[1].x - ecart;
		}
		// this->door->coordinates[1].z = -ecart;
		this->door->coordinates[1].z = this->door->coordinates[1].z-ecart;


	}
	else
	{

		// printf("%s\n", "closing x1 x2" );
		// printf("%f\n", this->door->coordinates[0].x);
		// printf("%f\n", this->door->coordinates[1].x);
		// printf("%s\n", "closing z1 z2");
		// printf("%f\n", this->door->coordinates[0].z);
		// printf("%f\n", this->door->coordinates[1].z);

		double ecart = this->calculerDistance(this->door->coordinates[0].z,this->door->coordinates[1].z);		
		this->door->coordinates[1].z = this->door->coordinates[1].z + ecart;
		this->door->coordinates[1].x = this->door->coordinates[1].x + ecart;	

		// printf("%s\n", "after closing x1 x2" );
		// printf("%f\n", this->door->coordinates[0].x);
		// printf("%f\n", this->door->coordinates[1].x);
		// printf("%s\n", "after closing z1 z2");
		// printf("%f\n", this->door->coordinates[0].z);
		// printf("%f\n", this->door->coordinates[1].z);

	}


	this->open = false;
	
}


Porte::~Porte()
{

}


vector<AABB3D> Porte::getHitboxes() const{
	return this->door->getHitboxes();
}
	




