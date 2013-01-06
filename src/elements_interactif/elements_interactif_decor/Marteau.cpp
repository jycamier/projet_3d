#include <GL/gl.h>
#include <GL/glu.h>
#include "Marteau.h"
#include "../../sdlglutils.h"

Marteau::Marteau(double x, double y, double z) : ElementInteractifDecor(x, y, z)
{
    // this->texture_sucre = loadTexture("textures/sucre.jpg");
    this->cubeTete = new Cube(x,y,z,1,1,1);
    this->cubeManche = new Cube(x-0.5,y-0.5,z-0.2,0.3,0.35,3);


}


Marteau::~Marteau(){

}


void Marteau::draw()
{
    glColor3ub(153, 153, 153);
    this->cubeTete->draw();
    glColor3ub(102, 51, 0);
    this->cubeManche->draw();
    
    this->createHitboxes(this->position->x,
            this->position->y, this->position->z,5,5,-5);

    this->hitboxCreated = true;
}

void Marteau::interaction()
{

}
