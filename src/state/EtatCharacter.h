#ifndef ETATCHARACTER_H_INCLUDED
#define ETATCHARACTER_H_INCLUDED
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include "../freeflycamera.h"


class EtatCharacter  {
    protected:
        
    	FreeFlyCamera* perso;

    public:

        EtatCharacter(FreeFlyCamera*);
        virtual void modifierComportement();
        ~EtatCharacter();
};

#endif //ETATCHARACTER_H_INCLUDED;
