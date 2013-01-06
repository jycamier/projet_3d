#include "Cube.h"


Cube::Cube(double x, double y, double z, double longu, double haut, double larg)
{
    this->position = new Point(x,y,z);
    this->longueur = longu;
    this->hauteur = haut;
    this->largeur = larg;

    this->texture_face1 = 0;
    this->texture_face2 = 0;
    this->texture_face3 = 0;
    this->texture_face4 = 0;
    this->texture_face5 = 0;
    this->texture_face6 = 0;
}

Cube::~Cube()
{

}

void Cube::draw()
{

    glBindTexture(GL_TEXTURE_2D, this->texture_face1);
    glBegin(GL_QUADS);

        glTexCoord2d(0, 1);glVertex3d(this->position->x,this->position->y,this->position->z);
        glTexCoord2d(1, 1);glVertex3d(this->position->x,this->position->y,this->position->z - largeur);
        glTexCoord2d(1, 0);glVertex3d(this->position->x - longueur,this->position->y,this->position->z - largeur);
        glTexCoord2d(0, 0);glVertex3d(this->position->x - longueur,this->position->y,this->position->z);
    
    glEnd();

    glBindTexture(GL_TEXTURE_2D, this->texture_face2);
    glBegin(GL_QUADS);

        glBindTexture(GL_TEXTURE_2D, this->texture_face2);
        glTexCoord2d(0, 1);glVertex3d(this->position->x,this->position->y - hauteur,this->position->z);
        glTexCoord2d(1, 1);glVertex3d(this->position->x,this->position->y - hauteur,this->position->z - largeur);
        glTexCoord2d(1, 0);glVertex3d(this->position->x,this->position->y,this->position->z - largeur);
        glTexCoord2d(0, 0);glVertex3d(this->position->x,this->position->y,this->position->z);
     
    glEnd();

    glBindTexture(GL_TEXTURE_2D, this->texture_face3);
    glBegin(GL_QUADS);

        glTexCoord2d(0, 1);glVertex3d(this->position->x - longueur,this->position->y - hauteur,this->position->z);
        glTexCoord2d(1, 1);glVertex3d(this->position->x - longueur,this->position->y - hauteur,this->position->z - largeur);
        glTexCoord2d(1, 0);glVertex3d(this->position->x,this->position->y - hauteur,this->position->z - largeur);
        glTexCoord2d(0, 0);glVertex3d(this->position->x,this->position->y - hauteur,this->position->z);
     
    glEnd();

    glBindTexture(GL_TEXTURE_2D, this->texture_face4);
    glBegin(GL_QUADS);

        glTexCoord2d(0, 1);glVertex3d(this->position->x - longueur,this->position->y,this->position->z);
        glTexCoord2d(1, 1);glVertex3d(this->position->x - longueur,this->position->y,this->position->z - largeur);
        glTexCoord2d(1, 0);glVertex3d(this->position->x - longueur,this->position->y - hauteur,this->position->z - largeur);
        glTexCoord2d(0, 0);glVertex3d(this->position->x - longueur,this->position->y - hauteur,this->position->z);
    
    glEnd();

    glBindTexture(GL_TEXTURE_2D, this->texture_face5);
    glBegin(GL_QUADS); 

        glTexCoord2d(0, 1);glVertex3d(this->position->x,this->position->y,this->position->z - largeur);
        glTexCoord2d(1, 1);glVertex3d(this->position->x,this->position->y - hauteur,this->position->z - largeur);
        glTexCoord2d(1, 0);glVertex3d(this->position->x - longueur,this->position->y - hauteur,this->position->z - largeur);
        glTexCoord2d(0, 0);glVertex3d(this->position->x - longueur,this->position->y,this->position->z - largeur);
    
    glEnd();

    glBindTexture(GL_TEXTURE_2D, this->texture_face6);
    glBegin(GL_QUADS); 

        glTexCoord2d(0, 1);glVertex3d(this->position->x,this->position->y - hauteur,this->position->z);
        glTexCoord2d(1, 1);glVertex3d(this->position->x,this->position->y,this->position->z);
        glTexCoord2d(1, 0);glVertex3d(this->position->x - longueur,this->position->y,this->position->z);
        glTexCoord2d(0, 0);glVertex3d(this->position->x - longueur,this->position->y - hauteur,this->position->z);
 
    glEnd();

}