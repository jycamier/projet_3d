#ifndef ETATNORMAL_H_INCLUDED
#define ETATNORMAL_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include "EtatCharacter.h"

class EtatNormal : public EtatCharacter {

    public:

        EtatNormal(FreeFlyCamera*);
        void modifierComportement();
        ~EtatNormal();
};

#endif //ETATNORMAL_H_INCLUDED;
