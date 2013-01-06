#include <GL/gl.h>
#include <GL/glu.h>
#include "Charbon.h"
#include "../../sdlglutils.h"

Charbon::Charbon(double x, double y, double z) : ElementInteractifDecor(x, y, z)
{
    this->quadriqueCharbon= gluNewQuadric();
    this->texture_charbon = loadTexture("textures/charbon.jpg");;
}


Charbon::~Charbon(){

}


void Charbon::draw()
{
    glPushMatrix();

    gluQuadricTexture(quadriqueCharbon,GL_TRUE);
    glBindTexture(GL_TEXTURE_2D, this->texture_charbon);
    gluQuadricDrawStyle(quadriqueCharbon, GLU_FILL);

    glTranslated(position->x,position->y,position->z); // choix de l’emplacement cylindre
    gluSphere(quadriqueCharbon,1,25,25);
    glPopMatrix();

    
    this->createHitboxes(this->position->x,
            this->position->y, this->position->z,1,2,2);

    this->hitboxCreated = true;
}

void Charbon::interaction()
{

}
