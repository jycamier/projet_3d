#ifndef ETATINTERMEDIAIRE_H_INCLUDED
#define ETATINTERMEDIAIRE_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include "EtatCharacter.h"

class EtatIntermediaire : public EtatCharacter {

    public:

        EtatIntermediaire(FreeFlyCamera*);
        void modifierComportement();
        ~EtatIntermediaire();
};

#endif //ETATINTERMEDIAIRE_H_INCLUDED;
