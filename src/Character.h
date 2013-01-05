#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include "freeflycamera.h"
#include "state/EtatNormal.h"
#include "state/EtatIntermediaire.h"

class Character : public FreeFlyCamera {
    protected:
        
    	bool fou;
    	EtatCharacter* etat;


    public:

        Character(const Vector3D &);
        void animate(Uint32 timestep);
        ~Character();

        void setEtat(EtatCharacter* state){
        	delete(this->etat);
        	this->etat = state;
        }
};

#endif //CHARACTER_H_INCLUDED;
