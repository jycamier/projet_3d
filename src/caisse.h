#ifndef CAISSE_H_INCLUDED
#define CAISSE_H_INCLUDED

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

class Caisse {
    private :
        double x;
        double y;
        double z;
        int height;

    public :
        Caisse () ; // Non implémenté donc inutilisable
        Caisse (const Caisse &); // Constructeur de copie, non implémenté donc interdit
        Caisse (double, double, double,int);
        ~Caisse(); // Destructeur
        void draw(GLUquadricObj *, int);
        void changeTexture(int);
        void changeHeight(int);

};

#endif // CAISSE_H_INCLUDED
