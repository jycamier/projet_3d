#ifndef ETAGE_H_INCLUDED
#define ETAGE_H_INCLUDED

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <vector>
#include "caisse.h"

using namespace std;

class Etage {

    private :

        int longueur_etage;
        int hauteur_etage;
        int largeur_etage;
        int base;
        int texture_plafond;
        int texture_murs;
        int texture_sol;
        vector<Caisse*> lesCaisses;

    public :
        Etage () ; // Non implémenté donc inutilisable
        Etage (const Etage &); // Constructeur de copie, non implémenté donc interdit
        Etage (int, int, int, int, int, int, int);
        void draw(int);
        ~Etage(); // Destructeur

        /**
         * méthode de test pour Collision
         * >>> ajoute une caisse au coordonnée (x, z)
         */
        void AjouterCaisse(double x, double y, double z, double height);

		vector<Caisse*> getLesCaisses() const {
			return lesCaisses;
		}
};

#endif // ETAGE_H_INCLUDED
