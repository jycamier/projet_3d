#include "Escalier.h"
#include <vector> 
#include <iostream> 
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
using namespace std;

Escalier::Escalier(double x, double y, double z, int height) : ElementDecor(x, y, z){
	this->hauteur = height;
}

void Escalier::draw(){
	
	int tempX = this->position->x;
	int tempY = this->position->y;
	int tempZ = this->position->z;
	
	while (tempY > -this->hauteur)
	{
		glBegin(GL_QUADS);		
		glColor3ub(168,163,165);

		glVertex3d(tempX,tempY,tempZ);
		glVertex3d(tempX,tempY,tempZ+10);
		glVertex3d(tempX,tempY-1,tempZ+10);
		glVertex3d(tempX,tempY-1,tempZ);
					
		glEnd() ;

		glBegin(GL_QUADS);		
		glColor3ub(255,0,0);

		glVertex3d(tempX,tempY-1,tempZ);
		glVertex3d(tempX,tempY-1,tempZ+10);
		glVertex3d(tempX-2,tempY-1,tempZ+10);
		glVertex3d(tempX-2,tempY-1,tempZ);

		glEnd() ;

		tempY = tempY - 1;
		tempX = tempX - 2;
	}

	// i = 0;
	// a =37;
	// b = 0;
	// c = 80;

	// while (b < 20)
	// {
	// 	glBegin(GL_QUADS);		
	// 	glColor3ub(168,163,165);

	// 	glVertex3d(a,b,c);
	// 	glVertex3d(a,b,c-10);
	// 	glVertex3d(a,b+1,c-10);
	// 	glVertex3d(a,b+1,c);
					
	// 	glEnd() ;

	// 	glBegin(GL_QUADS);		
	// 	glColor3ub(255,0,0);

	// 	glVertex3d(a,b+1,c);
	// 	glVertex3d(a,b+1,c-10);
	// 	glVertex3d(a+2,b+1,c-10);
	// 	glVertex3d(a+2,b+1,c);

	// 	glEnd() ;
	// 	i++;

	// 	b = b + 1;
	// 	a = a + 2;
	// }

}