#ifndef CUBE_H_INCLUDED
#define CUBE_H_INCLUDED

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <vector>
#include "utils/point.h"
#include "sdlglutils.h"

using namespace std;

class Cube{
    private :

        double longueur;
        double largeur;
        double hauteur;
        Point* position;
        

    public :

    	int texture_face1;
        int texture_face2;
        int texture_face3;
        int texture_face4;
        int texture_face5;
        int texture_face6;

        Cube () ; // Non implémenté donc inutilisable
        Cube (const Cube &); // Constructeur de copie, non implémenté donc interdit
        Cube (double, double,double,double, double,double);
        ~Cube(); // Destructeur
        void draw();

};

#endif // CUBE_H_INCLUDED
