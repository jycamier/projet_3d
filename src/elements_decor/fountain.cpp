#include "fountain.h"
#include <vector> 
#include <iostream> 
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

using namespace std;

Fountain::Fountain(double x, double y, double z) : ElementDecor(x, y, z){
	width = y;
}

WaterCup* Fountain::provideWater() 
{	
	return new WaterCup(this->position->x,this->position->y,this->position->z);
}


void Fountain::draw() {
	vector<Point> base;
	base.push_back(Point(position->x-width/2, position->y, position->z-width/2));
	base.push_back(Point(position->x-width/2, position->y, position->z+width/2));
	base.push_back(Point(position->x+width/2, position->y, position->z+width/2));
	base.push_back(Point(position->x+width/2, position->y, position->z-width/2));
	
	// Base

	glBegin(GL_QUADS);
		glColor3ub(223,223,223);
		for(int i = 0; i < base.size();i++){
			glVertex3d(base[i].x, base[i].y, base[i].z);	
		}
	glEnd();

	for(int i = 0; i < base.size() - 1;i++){
		glBegin(GL_QUADS);
			glVertex3d(base[i].x, base[i].y, base[i].z);
			glVertex3d(base[i+1].x, base[i+1].y, base[i+1].z);
			glVertex3d(base[i+1].x, base[i+1].y-width, base[i+1].z);
			glVertex3d(base[i].x, base[i].y-width, base[i].z);
		glEnd();
	}
	
	glBegin(GL_QUADS);
		glVertex3d(base[0].x, base[0].y, base[0].z);
		glVertex3d(base[3].x, base[3].y, base[3].z);
		glVertex3d(base[3].x, base[3].y-width, base[3].z);
		glVertex3d(base[0].x, base[0].y-width, base[0].z);
	glEnd();


	// Tank

	glBegin(GL_POLYGON);
		for(int i = 0; i < base.size();i++){
			glVertex3d(base[i].x, base[i].y+width/2, base[i].z);
		}
	glEnd();	

	for(int i = 0; i < base.size() - 1;i++){
		glBegin(GL_TRIANGLES);
			glVertex3d(base[i].x, base[i].y+width/2, base[i].z);
			glVertex3d(base[i+1].x, base[i+1].y+width/2, base[i+1].z);
			glVertex3d(position->x, position->y, position->z);
		glEnd();	
	}

	for(int i = 0; i < base.size() - 1;i++){
		glBegin(GL_QUADS);
			glVertex3d(base[i].x, base[i].y+width/2, base[i].z);
			glVertex3d(base[i+1].x, base[i+1].y+width/2, base[i+1].z);
			glVertex3d(base[i+1].x, base[i+1].y+width, base[i+1].z);
			glVertex3d(base[i].x, base[i].y+width, base[i].z);
		glEnd();
	}
	
	glBegin(GL_QUADS);
		glVertex3d(base[0].x, base[0].y+width/2, base[0].z);
		glVertex3d(base[3].x, base[3].y+width/2, base[3].z);
		glVertex3d(base[3].x, base[3].y+width, base[3].z);
		glVertex3d(base[0].x, base[0].y+width, base[0].z);
	glEnd();

	
	// Robinet
}