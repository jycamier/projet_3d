#include "fountain.h"
#include <vector> 
#include <iostream> 
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
using namespace std;

Fountain::Fountain(double x, double y, double z) : ElementDecor(x, y, z){
	width = 10;
}

void Fountain::draw() {
	
	vector<Point> base;
	base.push_back(Point(position->x-width/2, position->y-width/2, position->z));
	base.push_back(Point(position->x-width/2, position->y+width/2, position->z));
	base.push_back(Point(position->x+width/2, position->y+width/2, position->z));
	base.push_back(Point(position->x+width/2, position->y-width/2, position->z));

	glBegin(GL_QUADS);
	glColor3ub(223,223,223);
	for(int i = 0; i < base.size();i++){
		glVertex3d(base[i].x, base[i].y, base[i].z);	
	}
	glEnd() ;

	glBegin(GL_QUADS);
	glColor3ub(223,223,223);
	for(int i = 0; i < base.size();i++){
		glVertex3d(base[i].x, base[i].y+20, base[i].z);	
	}
	glEnd() ;
}