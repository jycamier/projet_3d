#include <GL/gl.h>
#include <GL/glu.h>
#include "Button.h"

Button::Button(double x, double y, double z, char direction, double diam, int text) : ElementInteractifDecor(x, y, z)
{
    
    this->quadriqueFace= gluNewQuadric();
    this->quadriqueEpaisseur= gluNewQuadric();
    this->quadriqueFesse= gluNewQuadric();
    this->texture_button = text;

    if (direction == 'x')
    {
        this->orientation = 90;
    }
    else
    {
        this->orientation = 0;
    }

    this->diametre = diam;
    this->longeur_epaisseur = 0.5;

}

Button::~Button(){

}


void Button::draw()
{

    int ecart = 0;
    glColor3ub(223,223,223);        
    glPushMatrix();

    gluQuadricTexture(quadriqueFace,GL_TRUE);
    glBindTexture(GL_TEXTURE_2D, this->texture_button);
    gluQuadricDrawStyle(quadriqueFace, GLU_FILL);

    glTranslated(position->x,position->y,position->z); // choix de l’emplacement cylindre
    glRotatef( orientation, 0, 1, 0 );
    gluDisk(quadriqueFace,0, this->diametre, 20, 20);
       
    glPopMatrix();

    glPushMatrix();

    gluQuadricTexture(quadriqueFesse,GL_TRUE);
    glBindTexture(GL_TEXTURE_2D, 0);
    gluQuadricDrawStyle(quadriqueFesse, GLU_FILL);

    if (this->orientation == 90)
    {
        glTranslated(position->x + longeur_epaisseur,position->y ,position->z); // choix de l’emplacement cylindre
    }
    else
    {
        glTranslated(position->x,position->y ,position->z + longeur_epaisseur); // choix de l’emplacement cylindre   
    }

        
    glRotatef( orientation, 0, 1, 0 );
    gluDisk(quadriqueFesse,0, this->diametre, 20, 20);
        
    glPopMatrix();

    glPushMatrix();
       
    glTranslated(position->x,position->y,position->z); // choix de l’emplacement cylindre
    glRotatef( orientation, 0, 1, 0 );
    gluCylinder(quadriqueEpaisseur,this->diametre,this->diametre,longeur_epaisseur,20,20);
        
    glPopMatrix();
}


void Button::interaction()
{

}