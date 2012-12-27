#ifndef ETAGE_H_INCLUDED
#define ETAGE_H_INCLUDED

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <vector>
#include "elements/element_decor.h"

using namespace std;

class Etage {

    private :

        double longueur_etage;
        double hauteur_etage;
        double largeur_etage;
        double base;

        vector<ElementDecor*> decor; 

        int texture_plafond;
        int texture_murs;
        int texture_sol;       

    public :
        Etage () ; // Non implémenté donc inutilisable
        Etage (const Etage &); // Constructeur de copie, non implémenté donc interdit
        Etage (double, double, double, int, int, int, double);

        void draw();
        void drawSurface();
        void drawElementsDecor();
        void addElementDecor(ElementDecor*);
        void removeElementDecor(ElementDecor*);
        void clearElementsDecor();

        ~Etage(); // Destructeur
};

#endif // ETAGE_H_INCLUDED