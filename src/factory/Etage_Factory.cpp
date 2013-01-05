#include <GL/gl.h>
#include <GL/glu.h>
#include "Etage_Factory.h"
#include "../etage.h"
#include "../sdlglutils.h"
#include "../elements_decor/Mur.h"
#include "../elements_decor/Pilier.h"
#include "../elements_decor/fountain.h"
#include "../elements_decor/Escalier.h"
#include "../elements_decor/Guichet.h"
#include "../elements_decor/Table.h"
#include "../elements_decor/Chaise.h"
#include "../elements_interactif/elements_interactif_decor/Pnj.h"
#include "../elements_interactif/elements_interactif_decor/Porte.h"
#include "../elements_interactif/elements_interactif_decor/ButtonEtage.h"

/**
 * Créer l'espace de stockage dans le vecteur pour 4 étages
 */
EtageFactory::EtageFactory() {

}

/**
 * Permet de Charger les étages et de les créer si ceux-ci ne le sont pas
 */
void EtageFactory::loadEtage(int etage) {

	Etage* e;

	if (this->etages.size() == etage) {
		e = this->createEtage(etage);
		this->etages.insert(this->etages.begin() + etage, e);
	} else {
		e = this->etages.at(etage);
	}

	this->currentStare = e;
}

/**
 * Créer des étages
 */
Etage* EtageFactory::createEtage(int etage) {
	int texture_plafond;
	int texture_sol;
	int texture_murs;
	int texture_happy;

	//creation de l'étage
	Etage* createdStare;

	switch (etage) {
	case 0: {
		texture_plafond = loadTexture("textures/plafond1.jpg");
		texture_sol = loadTexture("textures/floor.jpg");
		texture_murs = loadTexture("textures/wall.jpg");

		createdStare = new Etage(80, 15, 80, texture_plafond, texture_sol,
				texture_murs, 0);
		createdStare->addElementDecor(new Table(0, 0, 0, 0, 10, 7, 2));
	}
		break;

	case 1: {
		//chargement des textures
		int texture_pilier = loadTexture("textures/pilier1.jpg");
		int texture_guichet = loadTexture("textures/wall.jpg");
		texture_plafond = loadTexture("textures/plafond1.jpg");
		texture_sol = loadTexture("textures/carrelage1.jpg");
		texture_murs = loadTexture("textures/mur1.jpg");
		texture_happy = loadTexture("textures/smilet_happy.jpg");

		//creation de l'étage
		createdStare = new Etage(80, 15, 80, texture_plafond, texture_sol,
				texture_murs, 0);

		//ajout des élement de décor dans l'étage
		createdStare->addElementDecor(
				new Pilier(20, 0, -40, texture_pilier, 2, 15));
		createdStare->addElementDecor(
				new Pilier(-20, 0, -20, texture_pilier, 2, 15));
		createdStare->addElementDecor(
				new Pilier(20, 0, -20, texture_pilier, 2, 15));
		createdStare->addElementDecor(
				new Pilier(-20, 0, 0, texture_pilier, 2, 15));
		createdStare->addElementDecor(
				new Pilier(-20, 0, 0, texture_pilier, 2, 15));
		createdStare->addElementDecor(
				new Pilier(20, 0, 0, texture_pilier, 2, 15));
		createdStare->addElementDecor(
				new Pilier(-20, 0, 20, texture_pilier, 2, 15));
		createdStare->addElementDecor(
				new Pilier(20, 0, 20, texture_pilier, 2, 15));
		createdStare->addElementDecor(new Fountain(10.0, 3.0, 10.0));
		createdStare->addElementDecor(new Guichet(80, 0, 30, 20, 15, 10));
		createdStare->addElementDecor(new Guichet(80, 0, 10, 20, 15, 10));
		createdStare->addElementDecor(new Guichet(80, 0, -10, 20, 15, 10));
		createdStare->addElementDecor(new Escalier(70, 0, 80, 70, -20, 0));
		createdStare->addElementDecor(new Escalier(37, 0, 80, 70, 20, 0));

		createdStare->addElementDecorInteractif(new Pnj(50, 0, 0, 'N'));
		createdStare->addElementDecorInteractif(new Pnj(10, 0, -10, 'S'));
		createdStare->addElementDecorInteractif(new Pnj(35, 0, -50, 'E'));
		createdStare->addElementDecorInteractif(new Pnj(40, 0, -20, 'O'));
	}
		break;

	case 2: {
		//chargement des textures
		texture_plafond = loadTexture("textures/plafond1.jpg");
		texture_sol = loadTexture("textures/moquette.jpg");
		texture_murs = loadTexture("textures/mur1.jpg");
		int texture_murs_bureau = loadTexture("textures/mur1.jpg");

		//creation de l'étage
		createdStare = new Etage(80, 15, 80, texture_plafond, texture_sol,
				texture_murs, 0);

		//utilisé pour définir les coordonnées des murs ci-après
		vector<Point> points;

		points.push_back(Point(10, 0, 40));
		points.push_back(Point(10, 0, 0));
		Mur *mur1Salle1 = new Mur(80, 0, 40, points, 15, texture_murs_bureau);
		points.clear();

		points.push_back(Point(10, 0, -30));
		points.push_back(Point(80, 0, -30));
		Mur *mur2Salle1 = new Mur(10, 0, -10, points, 15, texture_murs_bureau);
		points.clear();

		points.push_back(Point(-10, 0, 40));
		points.push_back(Point(-10, 0, 0));
		Mur *mur1Salle2 = new Mur(-80, 0, 40, points, 15, texture_murs_bureau);
		points.clear();

		points.push_back(Point(-10, 0, -30));
		points.push_back(Point(-80, 0, -30));
		Mur *mur2Salle2 = new Mur(-10, 0, -10, points, 15, texture_murs_bureau);
		points.clear();

		createdStare->addElementDecor(mur1Salle1);
		createdStare->addElementDecor(mur1Salle2);
		createdStare->addElementDecor(mur2Salle1);
		createdStare->addElementDecor(mur2Salle2);
		createdStare->addElementDecor(new Table(50, 0, 20, 0, 10, 12, 5));
		createdStare->addElementDecor(new Chaise(52, 0, 19, 0, 5, 4, 3, 'S'));
		createdStare->addElementDecor(new Chaise(52, 0, 29, 0, 5, 4, 3, 'N'));
		createdStare->addElementDecor(new Chaise(49, 0, 26, 0, 5, 4, 3, 'E'));
		createdStare->addElementDecor(new Chaise(60, 0, 26, 0, 5, 4, 3, 'W'));

		createdStare->addElementDecorInteractif(new Pnj(-50, 0, -13, 'N'));
		createdStare->addElementDecorInteractif(new Pnj(50, 0, -10, 'E'));
		createdStare->addElementDecorInteractif(
				new Porte(10, 0, 0, 'x', 10, 15));
	}
		break;

	case 3: {

	}
		break;

	}

	/**
	 * CONSTRUCTION DES BOUTONS ELEVATOR
	 */
	int texture_bouton_1 = loadTexture("textures/stare_1.jpg");
	int texture_bouton_2 = loadTexture("textures/stare_2.jpg");
	int texture_bouton_3 = loadTexture("textures/stare_3.jpg");
	int texture_bouton_4 = loadTexture("textures/stare_4.jpg");
	int texture_bouton_5 = loadTexture("textures/stare_5.jpg");
	int texture_bouton_6 = loadTexture("textures/stare_6.jpg");

	Point* pts = createdStare->getElevator()->getPosition();

	createdStare->getElevator()->addButton(
			new ButtonEtage(pts->x - 1, 8, pts->z + 9, 'x', 0.5,
					texture_bouton_1, this, 0));
	createdStare->getElevator()->addButton(
			new ButtonEtage(pts->x - 1, 8, pts->z + 11, 'x', 0.5,
					texture_bouton_2, this, 1));
	createdStare->getElevator()->addButton(
			new ButtonEtage(pts->x - 1, 8, pts->z + 13, 'x', 0.5,
					texture_bouton_3, this, 2));
	createdStare->getElevator()->addButton(
			new ButtonEtage(pts->x - 1, 8, pts->z + 15, 'x', 0.5,
					texture_bouton_4, this, 3));
//	createdStare->getElevator()->addButton(new ButtonEtage(pts->x - 1, 4, pts->z + 9, 'x',
//			0.5, texture_bouton_5, this, 5));
//	createdStare->getElevator()->addButton(new ButtonEtage(pts->x - 1, 4, pts->z + 11, 'x',
//			0.5, texture_bouton_6, this, 6));

	createdStare->initElementInteractifDecor();

	return createdStare;

}

EtageFactory::~EtageFactory() {

}

/**
 * Méthode permettant de déssiner l'étage chargé
 */
void EtageFactory::draw() {
	this->currentStare->draw();
}

