#ifndef ETAGE_H_INCLUDED
#define ETAGE_H_INCLUDED

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
// #include <vector>
#include "caisse.h"
#include "elements_decor/Mur.h"
#include "elements/element_decor.h"
#include "elements/element.h"
#include "elements/Element_Interactif_Decor.h"
#include "elements_interactif/elements_interactif_decor/Elevator.h"

using namespace std;

class Etage {

protected:

	double longueur_etage;
	double hauteur_etage;
	double largeur_etage;
	double base;
	Elevator* elevator;

	// vector<ElementDecor*> decor;
	

	int texture_plafond;
	int texture_murs;
	int texture_sol;
	vector<Caisse*> lesCaisses;

public:

	vector<ElementDecor*> decor;
	vector<ElementInteractifDecor*> decorInteractif;
	vector<Mur*> elevatorDoors;

	Etage(); // Non implémenté donc inutilisable
	Etage(const Etage &); // Constructeur de copie, non implémenté donc interdit
	Etage(double, double, double, int, int, int, double);

	void draw();
	void drawSurface();
	void drawElementsDecor();
	void drawElevatorDoor();
	void openElevatorDoors();
	void closeElevatorDoors();
	void addElementDecor(ElementDecor*);
	void addElementDecorInteractif(ElementInteractifDecor*);
	void removeElementDecor(ElementDecor*);
	void clearElementsDecor();
	/**
	 * méthode de test pour Collision
	 * >>> ajoute une caisse au coordonnée (x, z)
	 */
	void AjouterCaisse(double x, double y, double z, double height);

	vector<Caisse*> getLesCaisses() const {
		return lesCaisses;
	}

	double getLargeurEtage() const {
		return largeur_etage;
	}

	double getLongueurEtage() const {
		return longueur_etage;
	}

};

#endif // ETAGE_H_INCLUDED
