#include <GL/gl.h>
#include <GL/glu.h>
#include "Sucre.h"
#include "../../sdlglutils.h"

Sucre::Sucre(double x, double y, double z) : ElementInteractifDecor(x, y, z)
{
    this->texture_sucre = loadTexture("textures/sucre.jpg");
    this->cube = new Cube(x,y,z,0.55,0.35,0.75);

    this->cube->texture_face1 = this->texture_sucre;
    this->cube->texture_face2 = this->texture_sucre;
    this->cube->texture_face3 = this->texture_sucre;
    this->cube->texture_face4 = this->texture_sucre;
    this->cube->texture_face5 = this->texture_sucre;
    this->cube->texture_face6 = this->texture_sucre;

}


Sucre::~Sucre(){

}


void Sucre::draw()
{
    this->cube->draw();
    
    this->createHitboxes(this->position->x,
            this->position->y, this->position->z,5,5,5);

    this->hitboxCreated = true;
}

void Sucre::interaction()
{

}
