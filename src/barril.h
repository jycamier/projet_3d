#ifndef BARRIL_H_INCLUDED
#define BARRIL_H_INCLUDED

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

class Barril {
    private :
        double x;
        double y;
        double z;

    public :
        Barril () ; // Non implémenté donc inutilisable
        Barril (const Barril &); // Constructeur de copie, non implémenté donc interdit
        Barril (double, double, double);
        ~Barril(); // Destructeur
        void draw(GLUquadricObj *, int);

};

#endif // BARRIL_H_INCLUDED
