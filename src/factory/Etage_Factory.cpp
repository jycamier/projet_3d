#include <GL/gl.h>
#include <GL/glu.h>
#include "Etage_Factory.h"
#include "../etage.h"
#include "../sdlglutils.h"
#include "../elements_decor/Mur.h"
#include "../elements_decor/Tableau.h"
#include "../elements_decor/Pilier.h"
#include "../elements_decor/fountain.h"
#include "../elements_decor/Escalier.h"
#include "../elements_decor/Guichet.h"
#include "../elements_decor/Table.h"
#include "../elements_decor/Chaise.h"
#include "../elements_interactif/elements_interactif_decor/Pnj.h"
#include "../elements_interactif/elements_interactif_decor/Porte.h"
#include "../elements_interactif/elements_interactif_decor/ButtonEtage.h"
#include "../elements_interactif/elements_interactif_decor/Charbon.h"
#include "../elements_interactif/elements_interactif_decor/Sucre.h"
#include "../elements_interactif/elements_interactif_decor/Marteau.h"
#include "../elements_interactif/elements_interactif_decor/Centrale.h"
#include "../quete/PnjQuete.h"

/**
 * Créer l'espace de stockage dans le vecteur pour 4 étages
 */
EtageFactory::EtageFactory() {

}

/**
 * Permet de Charger les étages et de les créer si ceux-ci ne le sont pas
 */
void EtageFactory::loadEtage(int etage) {

	if (this->etages.size() == 0 || (this->etages.size() == etage && this->verifiedAcheivementQuest())) {
		this->currentStare = this->createEtage(etage);
		this->etages.insert(this->etages.begin() + etage, this->currentStare);
	} else if(this->etages.size() > etage){
		this->currentStare = this->etages.at(etage);
	} 

	if(!this->verifiedAcheivementQuest()){
		printf("VOUS NE POUVEZ PAS ACCEDER A L'ETAGE SUIVANT\n");
	}

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
	//Nombre de quetes par étage
	int nbrQte;

	switch (etage) {
	case 0: {
		nbrQte = 1;

		//chargement des textures
		int texture_pilier = loadTexture("textures/pilier1.jpg");
		int texture_guichet = loadTexture("textures/wall.jpg");
		texture_plafond = loadTexture("textures/plafond1.jpg");
		texture_sol = loadTexture("textures/carrelage1.jpg");
		texture_murs = loadTexture("textures/mur1.jpg");
		texture_happy = loadTexture("textures/smilet_happy.jpg");
		int texture_tableau1 = loadTexture("textures/umadbro.jpg");
		int texture_tableau2 = loadTexture("textures/trollface.jpg");

		//creation de l'étage
		createdStare = new Etage(80, 15, 80, texture_plafond, texture_sol,
				texture_murs, 0, nbrQte);

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
		createdStare->addElementDecor(new Tableau(-79.5, 7, 0,1,-5,-10,'N',texture_tableau1));
		createdStare->addElementDecor(new Tableau(-79.5, 7, -40,1,-5,-10,'N',texture_tableau2));
		createdStare->addElementDecor(new Tableau(-79.5, 7, -20,1,-5,-10,'N',texture_tableau1));
		createdStare->addElementDecor(new Tableau(-79.5, 7, -60,1,-5,-10,'N',texture_tableau2));

		createdStare->addElementDecorInteractif(new Pnj(50,0,0,'N',"Non merci, j'ai pas franchement le temps de discuter"));
		createdStare->addElementDecorInteractif(new Pnj(10,0,-10,'S',"Le port ? C'est en bas de la ville"));
		createdStare->addElementDecorInteractif(new Pnj(35,0,-50,'E',"Si vous pouviez me grater le dos, just en bas à gauche..."));

		/**
		 * ELEMENTS DE QUETES
		 */
		createdStare->addElementDecorInteractif(
				new PnjQuete(40, 0, -20, 'O',
						"Tenez mon bon monsieur, voici la clef de l'ascenseur.",
						nbrQte, 0,
						"Avez-vous remplis votre formulaire administratif ?",
						createdStare));

	}
		break;

	case 1: {
		nbrQte = 2;

		texture_plafond = loadTexture("textures/plafond1.jpg");
		texture_sol = loadTexture("textures/floor.jpg");
		texture_murs = loadTexture("textures/wall.jpg");
	

		createdStare = new Etage(80, 15, 80, texture_plafond, texture_sol,
				texture_murs, 0, nbrQte);

		createdStare->addElementDecor(new Table(0, 0, 0, 0, 10, 10, 5));

		/**
		 * ELEMENTS DE QUETES
		 */
		createdStare->addElementDecorInteractif(new Marteau(8,6,4));
		createdStare->addElementDecorInteractif(new Charbon(1,6,9,nbrQte, 0,
				"Vous venez de ramasser du charbon",
				createdStare));
		createdStare->addElementDecorInteractif(new Centrale(75,0,-50,-5,-6,-5));
	}
		break;

	case 2: {
		nbrQte = 3;

		//chargement des textures
		texture_plafond = loadTexture("textures/plafond1.jpg");
		texture_sol = loadTexture("textures/moquette.jpg");
		texture_murs = loadTexture("textures/mur1.jpg");
		int texture_murs_bureau = loadTexture("textures/mur1.jpg");

		//creation de l'étage
		createdStare = new Etage(80, 15, 80, texture_plafond, texture_sol,
				texture_murs, 0,nbrQte);

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
		createdStare->addElementDecor(new Table(-8, 0, -70, 0, 10, 12, 5));
		createdStare->addElementDecor(new Chaise(52, 0, 19, 0, 5, 4, 3, 'S'));
		createdStare->addElementDecor(new Chaise(52, 0, 29, 0, 5, 4, 3, 'N'));
		createdStare->addElementDecor(new Chaise(49, 0, 26, 0, 5, 4, 3, 'E'));
		createdStare->addElementDecor(new Chaise(60, 0, 26, 0, 5, 4, 3, 'W'));

		createdStare->addElementDecorInteractif(new Pnj(-50,0,-13,'N',"5"));
		createdStare->addElementDecorInteractif(new Pnj(50,0,-10,'E',"6"));
		createdStare->addElementDecorInteractif(new Porte(10,0,0,'x',10,15));
		createdStare->addElementDecorInteractif(new Porte(-10,0,0,'x',10,15));
		//createdStare->addElementDecorInteractif(new Sucre(0,5.5,-60));

		/**
		 * ELEMENTS DE QUETES
		 */
		createdStare->addElementDecorInteractif(
				new PnjQuete(-50,0,-13,'N',
						"Tenez mon bon monsieur, voici du Pain.",
						nbrQte, 0,
						"Avez-vous remplis votre formulaire administratif ?",
						createdStare));
		createdStare->addElementDecorInteractif(
				new PnjQuete(50,0,-10,'E',
						"Tenez mon bon monsieur, voici du Boursin.",
						nbrQte, 1,
						"Avez-vous remplis votre formulaire administratif ?",
						createdStare));
		createdStare->addElementDecorInteractif(
				new PnjQuete(55,0,-10,'E',
						"Tenez mon bon monsieur, voici du Flan.",
						nbrQte, 2,
						"Avez-vous remplis votre formulaire administratif ?",
						createdStare));
	}
	break;

	case 3: {

		nbrQte = 6;

		texture_plafond = loadTexture("textures/plafond1.jpg");
		texture_sol = loadTexture("textures/sol_dernier_etage.jpg");
		texture_murs = loadTexture("textures/mur_dernier_etage.jpg");

		createdStare = new Etage(80, 15, 80, texture_plafond, texture_sol,texture_murs, 0,nbrQte);
		createdStare->addElementDecor(new Chaise(22, 0, -30, 0, 5, 4, 3, 'W'));
		createdStare->addElementDecor(new Chaise(22, 0, -20, 0, 5, 4, 3, 'W'));
		createdStare->addElementDecor(new Chaise(22, 0, -10, 0, 5, 4, 3, 'W'));
		createdStare->addElementDecor(new Chaise(32, 0, -30, 0, 5, 4, 3, 'W'));
		createdStare->addElementDecor(new Chaise(32, 0, -20, 0, 5, 4, 3, 'W'));
		createdStare->addElementDecor(new Chaise(32, 0, -10, 0, 5, 4, 3, 'W'));
		createdStare->addElementDecor(new Chaise(42, 0, -30, 0, 5, 4, 3, 'W'));
		createdStare->addElementDecor(new Chaise(42, 0, -20, 0, 5, 4, 3, 'W'));
		createdStare->addElementDecor(new Chaise(42, 0, -10, 0, 5, 4, 3, 'W'));
		createdStare->addElementDecor(new Chaise(52, 0, -30, 0, 5, 4, 3, 'W'));
		createdStare->addElementDecor(new Chaise(52, 0, -20, 0, 5, 4, 3, 'W'));
		createdStare->addElementDecor(new Chaise(52, 0, -10, 0, 5, 4, 3, 'W'));

		createdStare->addElementDecor(new Chaise(22, 0, 30, 0, 5, 4, 3, 'W'));
		createdStare->addElementDecor(new Chaise(22, 0, 20, 0, 5, 4, 3, 'W'));
		createdStare->addElementDecor(new Chaise(22, 0, 10, 0, 5, 4, 3, 'W'));
		createdStare->addElementDecor(new Chaise(32, 0, 30, 0, 5, 4, 3, 'W'));
		createdStare->addElementDecor(new Chaise(32, 0, 20, 0, 5, 4, 3, 'W'));
		createdStare->addElementDecor(new Chaise(32, 0, 10, 0, 5, 4, 3, 'W'));
		createdStare->addElementDecor(new Chaise(42, 0, 30, 0, 5, 4, 3, 'W'));
		createdStare->addElementDecor(new Chaise(42, 0, 20, 0, 5, 4, 3, 'W'));
		createdStare->addElementDecor(new Chaise(42, 0, 10, 0, 5, 4, 3, 'W'));
		createdStare->addElementDecor(new Chaise(52, 0, 30, 0, 5, 4, 3, 'W'));
		createdStare->addElementDecor(new Chaise(52, 0, 20, 0, 5, 4, 3, 'W'));
		createdStare->addElementDecor(new Chaise(52, 0, 10, 0, 5, 4, 3, 'W'));

		createdStare->addElementDecor(new Chaise(-22, 0,10, 0, 5, 4, 3, 'E'));
		createdStare->addElementDecor(new Chaise(-22, 0,20, 0, 5, 4, 3, 'E'));
		createdStare->addElementDecor(new Chaise(-22, 0,30, 0, 5, 4, 3, 'E'));
		createdStare->addElementDecor(new Chaise(-32, 0,10, 0, 5, 4, 3, 'E'));
		createdStare->addElementDecor(new Chaise(-32, 0,20, 0, 5, 4, 3, 'E'));
		createdStare->addElementDecor(new Chaise(-32, 0,30, 0, 5, 4, 3, 'E'));
		createdStare->addElementDecor(new Chaise(-42, 0,10, 0, 5, 4, 3, 'E'));
		createdStare->addElementDecor(new Chaise(-42, 0,20, 0, 5, 4, 3, 'E'));
		createdStare->addElementDecor(new Chaise(-42, 0,30, 0, 5, 4, 3, 'E'));
		createdStare->addElementDecor(new Chaise(-52, 0,10, 0, 5, 4, 3, 'E'));
		createdStare->addElementDecor(new Chaise(-52, 0,20, 0, 5, 4, 3, 'E'));
		createdStare->addElementDecor(new Chaise(-52, 0,30, 0, 5, 4, 3, 'E'));

		createdStare->addElementDecor(new Chaise(22, 0,10, 0, 5, 4, 3, 'E'));
		createdStare->addElementDecor(new Chaise(22, 0,20, 0, 5, 4, 3, 'E'));
		createdStare->addElementDecor(new Chaise(22, 0,30, 0, 5, 4, 3, 'E'));
		createdStare->addElementDecor(new Chaise(32, 0,10, 0, 5, 4, 3, 'E'));
		createdStare->addElementDecor(new Chaise(32, 0,20, 0, 5, 4, 3, 'E'));
		createdStare->addElementDecor(new Chaise(32, 0,30, 0, 5, 4, 3, 'E'));
		createdStare->addElementDecor(new Chaise(42, 0,10, 0, 5, 4, 3, 'E'));
		createdStare->addElementDecor(new Chaise(42, 0,20, 0, 5, 4, 3, 'E'));
		createdStare->addElementDecor(new Chaise(42, 0,30, 0, 5, 4, 3, 'E'));
		createdStare->addElementDecor(new Chaise(52, 0,10, 0, 5, 4, 3, 'E'));
		createdStare->addElementDecor(new Chaise(52, 0,20, 0, 5, 4, 3, 'E'));
		createdStare->addElementDecor(new Chaise(52, 0,30, 0, 5, 4, 3, 'E'));
		createdStare->addElementDecorInteractif(new Pnj(0,0,-70,'N',"Je suis le roi, apportez moi un café et je vous donnerais le laisser passer!!!"));
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
					texture_bouton_1, this, 1));
	createdStare->getElevator()->addButton(
			new ButtonEtage(pts->x - 1, 8, pts->z + 11, 'x', 0.5,
					texture_bouton_2, this, 0));
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

/**
 * Vérifie que toutes les quetes ont été faite avant de passer  l'étage supérieur
 */
bool EtageFactory::verifiedAcheivementQuest(){

	bool isVerified = true;
	int i = 0;

	while(i < currentStare->getQuete().size() && isVerified){
		isVerified = currentStare->getQuete().at(i);
		i++;
	}

	return isVerified;
}

