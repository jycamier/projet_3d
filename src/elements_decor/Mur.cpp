#include "Mur.h"
#include <vector> 
#include <iostream> 
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
using namespace std;


Mur::Mur(double x, double y, double z, vector<Point> coords, double height) : ElementDecor(x, y, z){

	int i = 0;
	this->epaisseur = 0.5;
	this->hauteur = height;
	this->coordinates.push_back(Point(x,y,z));

	while (i < coords.size())
	{
		this->coordinates.push_back(coords[i]);
		i++;
	}

}

void Mur::draw(){

	int i = 0;

	//coordonnées du point à l'indice i
	double x1;
	double y1;
	double z1;

	//coordonnées du point à l'indice i+1
	double x2;
	double y2;
	double z2;

	double epaisseur_mur;

	while (i < this->coordinates.size())
	{
		epaisseur_mur = this->epaisseur;

		if (i < this->coordinates.size()-1)
		{

		x1 = this->coordinates[i].x;
		y1 = this->coordinates[i].y;
		z1 = this->coordinates[i].z;

		x2 = this->coordinates[i+1].x;
		y2 = this->coordinates[i+1].y;
		z2 = this->coordinates[i+1].z;

			
			if (this->isHorizontal(this->coordinates[i],this->coordinates[i+1]))
			{

				if (i == 0)
				{
					this->drawHorizontalClosing(this->coordinates[i]);
				}
				else
				{
					if (this->coordinates[i-1].z < z1)
					{
						z1 = z1 - epaisseur_mur;
					}
					else
					{
						z1 = z1 + epaisseur_mur;
					}

					if (x2 < x1)
					{
						x1 = x1 + epaisseur_mur;
					}
					else
					{
						x1 = x1 - epaisseur_mur;	
					}
				}

				glBegin(GL_QUADS);
				glColor3ub(0,255,0);

				glVertex3d(x1,y1,z1 + epaisseur_mur);
				glVertex3d(x2,y1,z2 + epaisseur_mur);
				glVertex3d(x2,y1 + this->hauteur,z2 + epaisseur_mur);
				glVertex3d(x1,y1 + this->hauteur,z1 + epaisseur_mur);
					
				glEnd();

				glBegin(GL_QUADS);
				glColor3ub(0,255,0);

				glVertex3d(x1,y1,z1 - epaisseur_mur);
				glVertex3d(x2,y1,z2 - epaisseur_mur);
				glVertex3d(x2,y1 + this->hauteur,z2 - epaisseur_mur);
				glVertex3d(x1,y1 + this->hauteur,z1 - epaisseur_mur);
					
				glEnd();


			}
			else if (this->isVertical(this->coordinates[i],this->coordinates[i+1]))
			{
				if (i == 0)
				{
					this->drawVerticalClosing(this->coordinates[i]);
				}
				else
				{
					if (this->coordinates[i-1].x < x1)
					{
						x1 = x1 - epaisseur_mur;
					}
					else
					{
						x1 = x1 + epaisseur_mur;
					}


					if (z2 < z1)
					{
						z1 = z1 + epaisseur_mur;
					}
					else
					{
						z1 = z1 - epaisseur_mur;	
					}

				}

				glBegin(GL_QUADS);
				glColor3ub(0,0,255);

				glVertex3d(x1 + epaisseur_mur,y1,z1);
				glVertex3d(x2 + epaisseur_mur,y1,z2);
				glVertex3d(x2 + epaisseur_mur,y1 + this->hauteur,z2);
				glVertex3d(x1 + epaisseur_mur,y1 + this->hauteur,z1);
						
				glEnd();

				glBegin(GL_QUADS);
				glColor3ub(0,0,255);

				glVertex3d(x1 - epaisseur_mur,y1,z1);
				glVertex3d(x2 - epaisseur_mur,y1,z2);
				glVertex3d(x2 - epaisseur_mur,y1 + this->hauteur,z2);
				glVertex3d(x1 - epaisseur_mur,y1 + this->hauteur,z1);
						
				glEnd();
				
			}
		}
		else
		{
			if (this->isVertical(this->coordinates[i],this->coordinates[i-1]))
			{
				this->drawVerticalClosing(this->coordinates[i]);
			}
			else
			{
				this->drawHorizontalClosing(this->coordinates[i]);
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

//dessine la fermeture située entre 2 épaisseurs
void Mur::drawVerticalClosing(Point p)
{
	glBegin(GL_QUADS);
	glColor3ub(0,255,0);

	glVertex3d(p.x - this->epaisseur,p.y,p.z );
	glVertex3d(p.x + this->epaisseur,p.y,p.z );
	glVertex3d(p.x + this->epaisseur,p.y + this->hauteur,p.z);
	glVertex3d(p.x - this->epaisseur,p.y + this->hauteur,p.z);
						
	glEnd();
}

//dessine la fermeture située entre 2 épaisseurs
void Mur::drawHorizontalClosing(Point p)
{
	glBegin(GL_QUADS);
	glColor3ub(0,255,0);

	glVertex3d(p.x,p.y,p.z - this->epaisseur);
	glVertex3d(p.x,p.y,p.z + this->epaisseur);
	glVertex3d(p.x,p.y + this->hauteur,p.z + this->epaisseur);
	glVertex3d(p.x,p.y + this->hauteur,p.z - this->epaisseur);
						
	glEnd();
}