#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include "freeflycamera.h"

class Character : public FreeFlyCamera {
    protected:
        
    	bool fou;

    public:

        Character(const Vector3D &);
        void changerDirection();
        void remettreDirection();
        ~Character();
};

#endif //CHARACTER_H_INCLUDED;
