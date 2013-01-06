#ifndef TABLEAU_H_INCLUDED
#define TABLEAU_H_INCLUDED

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "../Cube.h"
#include "../elements/element_decor.h"

using namespace std;

class Tableau : public ElementDecor {
    private :

        double longueur;
        double largeur;
        double hauteur;
        double epaisseur;
        int image_tableau;
        Cube* cube;
        char orientation;
        

    public :
        Tableau () ; // Non implémenté donc inutilisable
        Tableau (const Tableau &); // Constructeur de copie, non implémenté donc interdit
        Tableau (double, double,double,double, double,double,char,int);
        ~Tableau(); // Destructeur
        void draw();

};

#endif // TABLEAU_H_INCLUDED
