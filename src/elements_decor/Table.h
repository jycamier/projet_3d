#ifndef TABLE_H_INCLUDED
#define TABLE_H_INCLUDED

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "../elements/element_decor.h"

class Table : public ElementDecor {
    private :

        double longueur;
        double largeur;
        double hauteur;
        GLUquadricObj *quadriquePieds;
        int textureTable;
        double epaisseurTable;
        

    public :
        Table () ; // Non implémenté donc inutilisable
        Table (const Table &); // Constructeur de copie, non implémenté donc interdit
        Table (double, double, double, int, double, double, double);
        ~Table(); // Destructeur
        void draw();
        void drawPlateau();
        void drawPieds();

};

#endif // TABLE_H_INCLUDED
