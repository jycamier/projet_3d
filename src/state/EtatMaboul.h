#ifndef ETATMABOUL_H_INCLUDED
#define ETATMABOUL_H_INCLUDED
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include "EtatCharacter.h"

class EtatMaboul : public EtatCharacter {

    public:

        EtatMaboul(FreeFlyCamera*);
        void modifierComportement();
        ~EtatMaboul();
};

#endif //ETATMABOUL_H_INCLUDED;
