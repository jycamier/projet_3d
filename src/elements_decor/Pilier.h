#ifndef PILIER_H_INCLUDED
#define PILIER_H_INCLUDED

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "../elements/element_decor.h"

class Pilier : public ElementDecor {
    private :
        GLUquadricObj *quadrique;
        int texture;

    public :
        Pilier () ; // Non implémenté donc inutilisable
        Pilier (const Pilier &); // Constructeur de copie, non implémenté donc interdit
        Pilier (double, double, double, int);
        ~Pilier(); // Destructeur
        void draw();

};

#endif // PILIER_H_INCLUDED
