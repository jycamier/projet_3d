#include "Mur.h"
#include <vector> 
#include <iostream> 
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "../sdlglutils.h"

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
	this->isUpdatable = false;
}

Mur::Mur(double x, double y, double z, vector<Point> coords, double height,
		int text, bool isUPT) : ElementDecor(x, y, z){
	//Mur(x, y, z, coords, height, text);
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
	this->isUpdatable = isUPT;

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
	GLfloat sol_amb[] = {0.5,0.5,0.5, 1.0};
	GLfloat sol_diff[] = {1.0,1.0,1.0, 1.0};
	GLfloat sol_brill[] = {128};

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
					glNormal3f(0,0,1);

	// glMaterialfv(GL_FRONT, GL_AMBIENT, sol_amb);
	// glMaterialfv(GL_FRONT,GL_DIFFUSE, sol_diff);
	// glMaterialfv(GL_FRONT,GL_SHININESS, sol_brill);
	
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
					glNormal3f(0,0,1);

	// glMaterialfv(GL_FRONT, GL_AMBIENT, sol_amb);
	// glMaterialfv(GL_FRONT,GL_DIFFUSE, sol_diff);
	// glMaterialfv(GL_FRONT,GL_SHININESS, sol_brill);


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
				this->UpdateHitbox((x1 < x2) ? x1 : x2, y1,
						z1 - epaisseur_mur - 1, this->calculerDistance(x1, x2),
						this->hauteur, (epaisseur_mur + 1) * 2);

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
					glNormal3f(0,0,1);

	// glMaterialfv(GL_FRONT, GL_AMBIENT, sol_amb);
	// glMaterialfv(GL_FRONT,GL_DIFFUSE, sol_diff);
	// glMaterialfv(GL_FRONT,GL_SHININESS, sol_brill);


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
					glNormal3f(0,0,1);

	// glMaterialfv(GL_FRONT, GL_AMBIENT, sol_amb);
	// glMaterialfv(GL_FRONT,GL_DIFFUSE, sol_diff);
	// glMaterialfv(GL_FRONT,GL_SHININESS, sol_brill);


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
				this->UpdateHitbox(x1 - epaisseur_mur - 1, y1,
						(z1 < z2) ? z1 : z2, (epaisseur_mur + 1) * 2,
						this->hauteur, this->calculerDistance(z1, z2));

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
	//permet de ne pas créer le hitbox à l'infinie
	hitboxCreated = true;
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
void Mur::UpdateHitbox(double x, double y, double z, double w, double h,
		double d) {
	if(hitboxCreated && isUpdatable){
		this->_hitboxes.clear();
		hitboxCreated = false;
	}

	this->createHitboxes(x, y, z, w, h, d);
}

