#ifndef PILIER_H_INCLUDED
#define PILIER_H_INCLUDED

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

class Pilier {
    private :
        double x;
        double y;
        double z;
        GLUquadricObj *quadrique;

    public :
        Pilier () ; // Non implémenté donc inutilisable
        Pilier (const Pilier &); // Constructeur de copie, non implémenté donc interdit
        Pilier (double, double, double);
        ~Pilier(); // Destructeur
        void draw(int);

};

#endif // PILIER_H_INCLUDED
