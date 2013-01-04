#include <GL/gl.h>
#include <GL/glu.h>
#include "Button.h"

Button::Button(double x, double y, double z, char direction, double diam, int text) : ElementInteractifDecor(x, y, z)
{
    
    this->quadriqueFace= gluNewQuadric();
    this->quadriqueEpaisseur= gluNewQuadric();
    this->quadriqueFesse= gluNewQuadric();
    this->texture_button = text;

    this->eltInteractifAssocie = NULL;

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

Button::Button(double x, double y, double z, char direction, double diam, int text,ElementInteractifDecor * eltAss) : ElementInteractifDecor(x, y, z)
{

    this->quadriqueFace= gluNewQuadric();
    this->quadriqueEpaisseur= gluNewQuadric();
    this->quadriqueFesse= gluNewQuadric();
    this->texture_button = text;

    this->eltInteractifAssocie = eltAss;

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
    glRotatef( -orientation, 0, 1, 0 );
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

    //création hitbox
    this->createHitboxes(this->position->x - 1 * sin(60 * M_PI / 180),
            this->position->y-1, this->position->z - 1,
            ((this->position->x + 1) - (this->position->x - 1))
                    * sin(60 * M_PI / 180), 2, 2);

    this->hitboxCreated = true;
}

void Button::interaction()
{
	if(this->eltInteractifAssocie != NULL)
		this->eltInteractifAssocie->interaction();
}
