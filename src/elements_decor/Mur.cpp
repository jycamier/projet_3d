#include "Mur.h"
#include <vector> 
#include <iostream> 
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

using namespace std;

Mur::Mur(double x, double y, double z, vector<Point> coords, double height,
		int text) :
		ElementDecor(x, y, z) {

	int i = 0;
	this->epaisseur = 0.5;
	this->hauteur = height;
	this->texture = text;
	this->coordinates.push_back(Point(x, y, z));
	this->hitboxCreated = false;

	while (i < coords.size()) {
		this->coordinates.push_back(coords[i]);
		i++;
	}
}

Mur::~Mur() {

}

void Mur::draw() {

	int i = 0;
	// glColor3ub(168,163,165);
	//coordonnées du point à l'indice i
	double x1;
	double y1;
	double z1;

	//coordonnées du point à l'indice i+1
	double x2;
	double y2;
	double z2;

	double epaisseur_mur;

	while (i < this->coordinates.size()) {
		epaisseur_mur = this->epaisseur;

		if (i < this->coordinates.size() - 1) {

			x1 = this->coordinates[i].x;
			y1 = this->coordinates[i].y;
			z1 = this->coordinates[i].z;

			x2 = this->coordinates[i + 1].x;
			y2 = this->coordinates[i + 1].y;
			z2 = this->coordinates[i + 1].z;

			if (this->isHorizontal(this->coordinates[i],
					this->coordinates[i + 1])) {

				if (i == 0) {
					this->drawHorizontalClosing(this->coordinates[i]);
				} else {
					if (this->coordinates[i - 1].z < z1) {
						z1 = z1 - epaisseur_mur;
					} else {
						z1 = z1 + epaisseur_mur;
					}

					if (x2 < x1) {
						x1 = x1 + epaisseur_mur;
					} else {
						x1 = x1 - epaisseur_mur;
					}
				}
				glBindTexture(GL_TEXTURE_2D, this->texture);
				glBegin (GL_QUADS);

				glTexCoord2d(5, 2);
				glVertex3d(x1, y1, z1 + epaisseur_mur);
				glTexCoord2d(2, 2);
				glVertex3d(x2, y1, z2 + epaisseur_mur);
				glTexCoord2d(2, 5);
				glVertex3d(x2, y1 + this->hauteur, z2 + epaisseur_mur);
				glTexCoord2d(5, 5);
				glVertex3d(x1, y1 + this->hauteur, z1 + epaisseur_mur);

				glEnd();

				glBindTexture(GL_TEXTURE_2D, this->texture);
				glBegin(GL_QUADS);

				glTexCoord2d(5, 2);
				glVertex3d(x1, y1, z1 - epaisseur_mur);
				glTexCoord2d(2, 2);
				glVertex3d(x2, y1, z2 - epaisseur_mur);
				glTexCoord2d(2, 5);
				glVertex3d(x2, y1 + this->hauteur, z2 - epaisseur_mur);
				glTexCoord2d(5, 5);
				glVertex3d(x1, y1 + this->hauteur, z1 - epaisseur_mur);

				glEnd();

				//Création de la hitbox
				this->createHitboxes((x1<x2)?x1:x2, y1, z1 - epaisseur_mur - 1,
						this->calculerDistance(x1, x2), this->hauteur,
						(epaisseur_mur + 1) * 2);

			} else if (this->isVertical(this->coordinates[i],
					this->coordinates[i + 1])) {
				if (i == 0) {
					this->drawVerticalClosing(this->coordinates[i]);
				} else {
					if (this->coordinates[i - 1].x < x1) {
						x1 = x1 - epaisseur_mur;
					} else {
						x1 = x1 + epaisseur_mur;
					}

					if (z2 < z1) {
						z1 = z1 + epaisseur_mur;
					} else {
						z1 = z1 - epaisseur_mur;
					}

				}
				glBindTexture(GL_TEXTURE_2D, this->texture);
				glBegin (GL_QUADS);

				glTexCoord2d(5, 2);
				glVertex3d(x1 + epaisseur_mur, y1, z1);
				glTexCoord2d(2, 2);
				glVertex3d(x2 + epaisseur_mur, y1, z2);
				glTexCoord2d(2, 5);
				glVertex3d(x2 + epaisseur_mur, y1 + this->hauteur, z2);
				glTexCoord2d(5, 5);
				glVertex3d(x1 + epaisseur_mur, y1 + this->hauteur, z1);

				glEnd();

				glBindTexture(GL_TEXTURE_2D, this->texture);
				glBegin(GL_QUADS);

				glTexCoord2d(5, 2);
				glVertex3d(x1 - epaisseur_mur, y1, z1);
				glTexCoord2d(2, 2);
				glVertex3d(x2 - epaisseur_mur, y1, z2);
				glTexCoord2d(2, 5);
				glVertex3d(x2 - epaisseur_mur, y1 + this->hauteur, z2);
				glTexCoord2d(5, 5);
				glVertex3d(x1 - epaisseur_mur, y1 + this->hauteur, z1);

				glEnd();

				//Création de la hitbox
				this->createHitboxes(x1 - epaisseur_mur - 1, y1, (z1<z2)?z1:z2,
						(epaisseur_mur + 1) * 2, this->hauteur,
						this->calculerDistance(z1, z2));


			}
		} else {
			if (this->isVertical(this->coordinates[i],
					this->coordinates[i - 1])) {
				this->drawVerticalClosing(this->coordinates[i]);
			} else {
				this->drawHorizontalClosing(this->coordinates[i]);
			}
		}

		i++;

	}
}

bool Mur::isHorizontal(Point p1, Point p2) {
	if (p1.x != p2.x) {
		return true;
	}
	return false;
}

bool Mur::isVertical(Point p1, Point p2) {
	if (p1.z != p2.z) {
		return true;
	}
	return false;
}

/**
 * dessine la fermeture située entre 2 épaisseurs
 */
void Mur::drawVerticalClosing(Point p) {
	glBindTexture(GL_TEXTURE_2D, this->texture);
	glBegin (GL_QUADS);

	glTexCoord2d(5, 2);
	glVertex3d(p.x - this->epaisseur, p.y, p.z);
	glTexCoord2d(2, 2);
	glVertex3d(p.x + this->epaisseur, p.y, p.z);
	glTexCoord2d(2, 5);
	glVertex3d(p.x + this->epaisseur, p.y + this->hauteur, p.z);
	glTexCoord2d(5, 5);
	glVertex3d(p.x - this->epaisseur, p.y + this->hauteur, p.z);

	glEnd();
}

/**
 * dessine la fermeture située entre 2 épaisseurs
 */
void Mur::drawHorizontalClosing(Point p) {
	glBindTexture(GL_TEXTURE_2D, this->texture);
	glBegin (GL_QUADS);

	glTexCoord2d(5, 2);
	glVertex3d(p.x, p.y, p.z - this->epaisseur);
	glTexCoord2d(2, 2);
	glVertex3d(p.x, p.y, p.z + this->epaisseur);
	glTexCoord2d(2, 5);
	glVertex3d(p.x, p.y + this->hauteur, p.z + this->epaisseur);
	glTexCoord2d(5, 5);
	glVertex3d(p.x, p.y + this->hauteur, p.z - this->epaisseur);

	glEnd();
}

/**
 * Met à jour la hitbox de l'objet.
 * La fonction sera donc ensuite appelé soit dans le constructeur, soit dans le draw : celà dépend du type d'élement
 * (Si l'élément peut bouger ou pas)
 */
void Mur::UpdateHitbox(){
// méthode virtuel
}

void Mur::createHitboxes(double x, double y, double z, double w, double h,
		double d) {

	AABB3D hitb = { x, y, z, w, h, d };
	this->_hitboxes.push_back(hitb);

	/*
	 * Test hitbox
	 */

	glBegin (GL_LINE_LOOP);
	glColor3ub(0, 255, 255);
	glVertex3d(x, y, z);
	glVertex3d(x+w, y, z);
	glVertex3d(x+w, y+h, z);
	glVertex3d(x, y+h, z);
	glEnd();

	glBegin (GL_LINE_LOOP);
	glColor3ub(0, 255, 255);
	glVertex3d(x, y, z+d);
	glVertex3d(x+w, y, z+d);
	glVertex3d(x+w, y+h, z+d);
	glVertex3d(x, y+h, z+d);
	glEnd();

}
