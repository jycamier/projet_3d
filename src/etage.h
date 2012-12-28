#ifndef ETAGE_H_INCLUDED
#define ETAGE_H_INCLUDED

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <vector>
#include "caisse.h"
#include "elements/element_decor.h"

using namespace std;

class Etage {

protected:

	double longueur_etage;
	double hauteur_etage;
	double largeur_etage;
	double base;

	vector<ElementDecor*> decor;

	int texture_plafond;
	int texture_murs;
	int texture_sol;
	vector<Caisse*> lesCaisses;

public:
	Etage(); // Non implémenté donc inutilisable
	Etage(const Etage &); // Constructeur de copie, non implémenté donc interdit
	Etage(double, double, double, int, int, int, double);

	void draw(int);
	void drawSurface();
	void drawElementsDecor();
	void addElementDecor(ElementDecor*);
	void removeElementDecor(ElementDecor*);
	void clearElementsDecor();

	~Etage(); // Destructeur

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
