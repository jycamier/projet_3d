#include "Elevator.h"
#include "../../utils/point.h"
#include "../../sdlglutils.h"

using namespace std;

Elevator::Elevator(double x, double y, double z, double longueur,
		double largeur, double hauteur) :
		ElementInteractifDecor(x, y, z) {
	this->lenght = longueur;
	this->width = largeur;
	this->height = hauteur;
	this->createElevatorShaft();
	this->createElevatorDoors();
	isClosed = true;

	// int texture_happy = loadTexture("textures/smilet_happy.jpg");
	this->loadTextures();

	this->buttons.push_back(
			new Button(this->position->x - 1, 8, this->position->z + 9, 'x',
					0.5, texture_bouton_1));
	this->buttons.push_back(
			new Button(this->position->x - 1, 8, this->position->z + 11, 'x',
					0.5, texture_bouton_2));
	this->buttons.push_back(
			new Button(this->position->x - 1, 6, this->position->z + 9, 'x',
					0.5, texture_bouton_2));
	this->buttons.push_back(
			new Button(this->position->x - 1, 6, this->position->z + 11, 'x',
					0.5, texture_bouton_4));
	this->buttons.push_back(
			new Button(this->position->x - 1, 4, this->position->z + 9, 'x',
					0.5, texture_bouton_5));
	this->buttons.push_back(
			new Button(this->position->x - 1, 4, this->position->z + 11, 'x',
					0.5, texture_bouton_6));
}

Elevator::~Elevator() {

}

void Elevator::createElevatorShaft() {
	vector<Point> points;
	points.push_back(
			Point(this->position->x, this->position->y,
					this->position->z + width));
	points.push_back(
			Point(this->position->x - lenght, this->position->y,
					this->position->z + width));
	points.push_back(
			Point(this->position->x - lenght, this->position->y,
					this->position->z));
	this->walls.push_back(
			new Mur(this->position->x, this->position->y, this->position->z,
					points, this->height, 0));
}

void Elevator::createElevatorDoors() {
	vector<Point> points;
	points.push_back(
			Point(this->position->x - lenght / 2, this->position->y,
					this->position->z + 1));
	this->doors.push_back(
			new Mur(this->position->x, this->position->y, this->position->z + 1,
					points, this->height, 0, true));
	points.clear();

	points.push_back(
			Point(this->position->x - lenght, this->position->y,
					this->position->z + 1));
	this->doors.push_back(
			new Mur(this->position->x - lenght / 2, this->position->y,
					this->position->z + 1, points, this->height, 0, true));
	points.clear();
}

void Elevator::draw() {
	int i = 0;

	while (i < this->walls.size()) {
		this->walls[i]->draw();
		i++;
	}
	i = 0;

	glColor3ub(0, 0, 255);
	while (i < this->doors.size()) {
		this->doors[i]->draw();
		i++;
	}

	i = 0;
	while (i < this->buttons.size()) {
		this->buttons[i]->draw();
		i++;
	}
}

void Elevator::open() {
	int i = 0;
	if (isClosed) {
		while (i < lenght / 2) {
			this->doors[0]->coordinates[0].x = this->doors[0]->coordinates[0].x
					+ 1;
			this->doors[0]->coordinates[1].x = this->doors[0]->coordinates[1].x
					+ 1;
			this->doors[1]->coordinates[0].x = this->doors[1]->coordinates[0].x
					- 1;
			this->doors[1]->coordinates[1].x = this->doors[1]->coordinates[1].x
					- 1;
			i++;
		}
		isClosed = false;
	}

}

void Elevator::close() {
	int i = 0;
	if (!isClosed) {
		while (i < lenght / 2) {
			this->doors[0]->coordinates[0].x = this->doors[0]->coordinates[0].x
					- 1;
			this->doors[0]->coordinates[1].x = this->doors[0]->coordinates[1].x
					- 1;
			this->doors[1]->coordinates[0].x = this->doors[1]->coordinates[0].x
					+ 1;
			this->doors[1]->coordinates[1].x = this->doors[1]->coordinates[1].x
					+ 1;
			i++;
		}
		isClosed = true;
	}

}

vector<AABB3D> Elevator::getHitboxes() const {

	vector<AABB3D> hitb;

	for (int i = 0; i < this->doors[0]->getHitboxes().size(); i++) {
		hitb.push_back(this->doors[0]->getHitboxes().at(i));
		hitb.push_back(this->doors[1]->getHitboxes().at(i));
	}

	return hitb;

}

/**
 * Méthode permettant d'intéragir avec la porte
 */
void Elevator::interaction() {
	if (isClosed) {
		this->open();
	} else {
		this->close();
	}
}

void Elevator::loadTextures(){
	texture_bouton_1 = loadTexture("textures/stare_1.jpg");
	texture_bouton_2 = loadTexture("textures/stare_2.jpg");
	texture_bouton_3 = loadTexture("textures/stare_3.jpg");
	texture_bouton_4 = loadTexture("textures/stare_4.jpg");
	texture_bouton_5 = loadTexture("textures/stare_5.jpg");
	texture_bouton_6 = loadTexture("textures/stare_6.jpg");
}
