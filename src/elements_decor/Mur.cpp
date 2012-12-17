#include "Mur.h"
#include <vector> 
#include <iostream> 
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
using namespace std;


Mur::Mur(double x, double y, double z, vector<Point> coords) : ElementDecor(x, y, z){

	int i = 0;
	this->epaisseur = 1;
	this->hauteur = 20;
	this->coordinates.push_back(Point(x,y,z));

	while (i < coords.size())
	{
		this->coordinates.push_back(coords[i]);
		i++;
	}

}

void Mur::draw(){

	int i = 0;
	int epaisseur_mur;

	while (i < this->coordinates.size())
	{
		epaisseur_mur = this->epaisseur;

		if (i < this->coordinates.size()-1)
		{

			glBegin(GL_QUADS);
			glColor3ub(0,255,0);

			glVertex3d(this->coordinates[i].x,this->coordinates[i].y,this->coordinates[i].z);
			glVertex3d(this->coordinates[i+1].x ,this->coordinates[i].y,this->coordinates[i+1].z);
			glVertex3d(this->coordinates[i+1].x ,this->coordinates[i].y + this->hauteur,this->coordinates[i+1].z);
			glVertex3d(this->coordinates[i].x ,this->coordinates[i].y + this->hauteur,this->coordinates[i].z);
						
			glEnd();


			if (this->isHorizontal(this->coordinates[i],this->coordinates[i+1]))
			{

				if (i+2 < this->coordinates.size())
				{
					if (this->isVertical(this->coordinates[i+1],this->coordinates[i+2]))
					{

						if (this->coordinates[i+1].z >= this->coordinates[i+2].z)
						{
								epaisseur_mur = this->epaisseur * (-1);
						}
					}
				}
				else if (i+1 < this->coordinates.size())
				{
					if (this->isVertical(this->coordinates[i],this->coordinates[i-1]))
					{
						if (this->isHorizontal(this->coordinates[i-1],this->coordinates[i-2]))
						{
							if (this->coordinates[i-1].z < this->coordinates[i].x)
							{
									epaisseur_mur = this->epaisseur * (-1);
							}
						}
					}
				}


				glBegin(GL_QUADS);
				glColor3ub(0,0,255);

				glVertex3d(this->coordinates[i].x,this->coordinates[i].y,this->coordinates[i].z + epaisseur_mur);
				glVertex3d(this->coordinates[i+1].x,this->coordinates[i].y,this->coordinates[i+1].z + epaisseur_mur);
				glVertex3d(this->coordinates[i+1].x,this->coordinates[i].y + this->hauteur,this->coordinates[i+1].z + epaisseur_mur);
				glVertex3d(this->coordinates[i].x,this->coordinates[i].y + this->hauteur,this->coordinates[i].z + epaisseur_mur);
				
				glEnd();

			}
			else if (this->isVertical(this->coordinates[i],this->coordinates[i+1]))
			{

				if (i+2 < this->coordinates.size())
					{
					if (this->isHorizontal(this->coordinates[i+1],this->coordinates[i+2]))
						{

						if (this->coordinates[i+1].x >= this->coordinates[i+2].x)
							{
								epaisseur_mur = this->epaisseur * (-1);
							}
						}
					}
				else if (i+1 < this->coordinates.size())
				{

					if (this->isHorizontal(this->coordinates[i],this->coordinates[i-1]))
					{

						if (this->isVertical(this->coordinates[i-1],this->coordinates[i-2]))
						{
							if (this->coordinates[i-1].x < this->coordinates[i].x)
							{
									epaisseur_mur = this->epaisseur * (-1);
							}
						}
					}
				}

				glBegin(GL_QUADS);
				glColor3ub(255,0,255);

				glVertex3d(this->coordinates[i].x + epaisseur_mur,this->coordinates[i].y,this->coordinates[i].z);
				glVertex3d(this->coordinates[i+1].x + epaisseur_mur,this->coordinates[i].y,this->coordinates[i+1].z);
				glVertex3d(this->coordinates[i+1].x + epaisseur_mur,this->coordinates[i].y + this->hauteur,this->coordinates[i+1].z);
				glVertex3d(this->coordinates[i].x + epaisseur_mur,this->coordinates[i].y + this->hauteur,this->coordinates[i].z);
				
				glEnd();
			}

		}
		i++;
	}

}

bool Mur::isHorizontal(Point p1, Point p2) 
{
	if (p1.x != p2.x)
	{
		return true;
	}
	return false;
}

bool Mur::isVertical(Point p1, Point p2) 
{
	if (p1.z != p2.z)
	{
		return true;
	}
	return false;
}