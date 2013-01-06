#include <GL/gl.h>
#include <GL/glu.h>
#include "Centrale.h"
#include "../../sdlglutils.h"


Centrale::Centrale(double x, double y, double z, double longu, double larg, double haut) : ElementInteractifDecor(x, y, z)
{
    this->hauteur = longu;
    this->longueur = haut;
    this->largeur = larg;

    this->cubeCentrale = new Cube(x,y,z,longu,haut,larg);
    this->cubeFeu = new Cube(x+1,y,z-2,longu,haut-2,larg-4);
        
}


Centrale::~Centrale(){

}


void Centrale::draw()
{
        glColor3ub(255,0,0);
    this->cubeCentrale->draw();
        glColor3ub(0,0,0);
    this->cubeFeu->draw();
    
  
    glColor3ub(223,223,223);
    
    this->createHitboxes(this->position->x,
            this->position->y, this->position->z,10,10,10);

    this->hitboxCreated = true;
}

void Centrale::interaction()
{

}
