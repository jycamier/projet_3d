#include "Escalier.h"
#include <vector> 
#include <iostream> 
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
using namespace std;

Escalier::Escalier(double x, double y, double z, double extremiteX, double extremiteY, double extremiteZ) : ElementDecor(x, y, z){
	this->extremite = new Point (extremiteX,extremiteY,extremiteZ);
}

void Escalier::draw(){
	
	int tempX = this->position->x;
	int tempY = this->position->y;
	int tempZ = this->position->z;

	int ecartX = 2;
	int ecartY = 1;
	int ecartZ = -10;

	int debut = 0;
	int fin = 0;
	
	if (this->position->y > this->extremite->y)
	{
		ecartY = -1;
	}
	if (this->position->x > this->extremite->x)
	{
		ecartX = -2;
	}
	
	while (tempY != this->extremite->y)
	{
		glBegin(GL_QUADS);		
		glColor3ub(168,163,165);

		glVertex3d(tempX,tempY,tempZ);
		glVertex3d(tempX,tempY,tempZ-10);
		glVertex3d(tempX,tempY+ecartY,tempZ-10);
		glVertex3d(tempX,tempY+ecartY,tempZ);
						
		glEnd() ;

		glBegin(GL_QUADS);		
		glColor3ub(255,0,0);

		glVertex3d(tempX,tempY+ecartY,tempZ);
		glVertex3d(tempX,tempY+ecartY,tempZ-10);
		glVertex3d(tempX+ecartX,tempY+ecartY,tempZ-10);
		glVertex3d(tempX+ecartX,tempY+ecartY,tempZ);

		glEnd() ;

		tempY = tempY + +ecartY;
		tempX = tempX + ecartX;
	}
		
}