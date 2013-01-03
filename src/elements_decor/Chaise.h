#ifndef CHAISE_H_INCLUDED
#define CHAISE_H_INCLUDED

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "../elements/element_decor.h"

class Chaise : public ElementDecor {
    private :

        double longueur;
        double largeur;
        double hauteur;
        GLUquadricObj *quadriquePieds;
        GLUquadricObj *quadriqueDossier;
        int textureChaise;
        double epaisseurChaise;
        char orientation;
        

    public :
        Chaise () ; // Non implémenté donc inutilisable
        Chaise (const Chaise &); // Constructeur de copie, non implémenté donc interdit
        Chaise (double, double, double, int, double, double, double,char);
        ~Chaise(); // Destructeur
        void draw();
        void drawPlateau();
        void drawPieds();
        void drawDossier();

};

#endif // CHAISE_H_INCLUDED
