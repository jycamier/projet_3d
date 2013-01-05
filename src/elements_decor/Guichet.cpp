#include "Guichet.h"
#include <vector> 
#include <iostream> 
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "../sdlglutils.h"

using namespace std;

Guichet::Guichet(double x, double y, double z, double longueur, double largeur,
		double hauteur) :
		ElementDecor(x, y, z) {
	this->heigth = hauteur;
	this->length = longueur;
	this->width = largeur;
	int espace = width + 8;


	// const unsigned char texte[100]  = "je suis guichetier";

	this->personnage = new Pnj(this->position->x - this->width / 2, 0,
			this->position->z - longueur / 2, 'E',"je suis guichetier");

	this->texture_mur = loadTexture("textures/mur_bureau.jpg");

	vector<Point> points;

	points.push_back(
			Point(this->position->x - length, this->position->y,
					this->position->z));
	points.push_back(
			Point(this->position->x - length, this->position->y,
					this->position->z - width / 2));
	this->walls.push_back(
			new Mur(this->position->x, this->position->y, this->position->z,
					points, this->heigth + 2, texture_mur));

	points.clear();

	points.push_back(
			Point(this->position->x - length, this->position->y,
					this->position->z - espace));
	points.push_back(
			Point(this->position->x - length, this->position->y,
					this->position->z - (espace - width / 2)));
	this->walls.push_back(
			new Mur(this->position->x, this->position->y,
					this->position->z - espace, points, this->heigth + 2,
					texture_mur));

	points.clear();

	points.push_back(
			Point(this->position->x - length, this->position->y - 5,
					this->position->z - width / 2));
	this->walls.push_back(
			new Mur(this->position->x - length, this->position->y - 5,
					this->position->z - (espace - width / 2), points,
					this->heigth, texture_mur));

	points.clear();

	points.push_back(
			Point(this->position->x - length, this->position->y + 10,
					this->position->z - width / 2));
	this->walls.push_back(
			new Mur(this->position->x - length, this->position->y + 10,
					this->position->z - (espace - width / 2), points, 2,
					texture_mur));

	this->bars.push_back(
			new Pilier(this->position->x - length, this->position->y,
					(this->position->z - width / 2) - 1, 0, 0.2, 10));
	this->bars.push_back(
			new Pilier(this->position->x - length, this->position->y,
					(this->position->z - width / 2) - 2, 0, 0.2, 10));
	this->bars.push_back(
			new Pilier(this->position->x - length, this->position->y,
					(this->position->z - width / 2) - 3, 0, 0.2, 10));
	this->bars.push_back(
			new Pilier(this->position->x - length, this->position->y,
					(this->position->z - width / 2) - 4, 0, 0.2, 10));
	this->bars.push_back(
			new Pilier(this->position->x - length, this->position->y,
					(this->position->z - width / 2) - 5, 0, 0.2, 10));
	this->bars.push_back(
			new Pilier(this->position->x - length, this->position->y,
					(this->position->z - width / 2) - 6, 0, 0.2, 10));
	this->bars.push_back(
			new Pilier(this->position->x - length, this->position->y,
					(this->position->z - width / 2) - 7, 0, 0.2, 10));

	//Création de la hitbox
		this->createHitboxes(this->position->x - length, this->position->y,
				this->position->z - espace - 0.5, length, heigth, espace+1);
		hitboxCreated = true;


}

void Guichet::draw() {
	int espace = width + 8;

	//Dessiner les murs
	for (int i = 0 ; i < this->walls.size(); i++) {
		this->walls[i]->draw();
	}


	for (int i = 0 ; i < this->bars.size() ; i++) {
		this->bars[i]->draw();
	}

	glBegin (GL_QUADS);
	glColor3ub(255, 0, 255);

	glTexCoord2d(20, 10);
	glVertex3d(this->position->x, this->heigth + 2, this->position->z - espace);
	glTexCoord2d(10, 10);
	glVertex3d(this->position->x - length, this->heigth + 2,
			this->position->z - espace);
	glTexCoord2d(10, 20);
	glVertex3d(this->position->x - length, this->heigth + 2, this->position->z);
	glTexCoord2d(20, 20);
	glVertex3d(this->position->x, this->heigth + 2, this->position->z);

	glEnd();
	glColor3ub(223, 223, 223);

	this->personnage->draw();

}

Guichet::~Guichet() {

}
