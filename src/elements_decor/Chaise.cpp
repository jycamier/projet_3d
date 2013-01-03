#include "Chaise.h"

Chaise::Chaise(double x, double y, double z, int text, double longu, double larg,double haut,char direction) : ElementDecor(x, y, z)
{
	quadriquePieds = gluNewQuadric();
	quadriqueDossier = gluNewQuadric();
	this->textureChaise = text;
	this->epaisseurChaise = 0.35;
	this->hauteur = haut;
	this->longueur = longu;
	this->largeur = larg;

	if (direction == 'N') {
		this->orientation = 0;
	} else if (direction == 'S') {
		this->orientation = -180;
	} else if (direction == 'E') {
		this->orientation = 90;
	} else if (direction == 'O') {
		this->orientation = -90;
	}
		
}
Chaise::~Chaise(){

}

void Chaise::drawPlateau()
{
	//table
	glBindTexture(GL_TEXTURE_2D, textureChaise);

	glBegin(GL_QUADS);		
	glColor3ub(255,0,0);

	glTexCoord2d(20,10); glVertex3d(this->position->x ,this->position->y + hauteur,this->position->z);
	glTexCoord2d(10,10); glVertex3d(this->position->x,this->position->y + hauteur,this->position->z + largeur);
	glTexCoord2d(10,20); glVertex3d(this->position->x + longueur,this->position->y + hauteur,this->position->z + largeur);
	glTexCoord2d(20,20); glVertex3d(this->position->x + longueur,this->position->y + hauteur,this->position->z);

	glEnd() ;

	//epaisseur
	glBegin(GL_QUADS);		
	glColor3ub(0,255,0);

	glTexCoord2d(20,10); glVertex3d(this->position->x ,this->position->y + hauteur - epaisseurChaise,this->position->z);
	glTexCoord2d(10,10); glVertex3d(this->position->x,this->position->y + hauteur - epaisseurChaise,this->position->z + largeur);
	glTexCoord2d(10,20); glVertex3d(this->position->x + longueur,this->position->y + hauteur - epaisseurChaise,this->position->z + largeur);
	glTexCoord2d(20,20); glVertex3d(this->position->x + longueur,this->position->y + hauteur - epaisseurChaise,this->position->z);

	glEnd() ;


	//fermeture 1
	glBegin(GL_QUADS);
	glColor3ub(0,0,255);

	glTexCoord2d(5,2); glVertex3d(this->position->x,this->position->y + hauteur - epaisseurChaise,this->position->z);
	glTexCoord2d(2,2); glVertex3d(this->position->x,this->position->y + hauteur - epaisseurChaise,this->position->z + largeur);
	glTexCoord2d(2,5); glVertex3d(this->position->x,this->position->y + hauteur,this->position->z + largeur);
	glTexCoord2d(5,5); glVertex3d(this->position->x,this->position->y + hauteur,this->position->z);
		
	glEnd() ;

	// fermeture 2
	glBegin(GL_QUADS);

	glTexCoord2d(5,2); glVertex3d(this->position->x + longueur,this->position->y + hauteur - epaisseurChaise,this->position->z);
	glTexCoord2d(2,2); glVertex3d(this->position->x + longueur,this->position->y + hauteur - epaisseurChaise,this->position->z + largeur);
	glTexCoord2d(2,5); glVertex3d(this->position->x + longueur,this->position->y + hauteur,this->position->z + largeur);
	glTexCoord2d(5,5); glVertex3d(this->position->x + longueur,this->position->y + hauteur,this->position->z);

	glEnd() ;


	// fermeture 3
	glBegin(GL_QUADS);

	glTexCoord2d(5,2); glVertex3d(this->position->x + longueur,this->position->y + hauteur - epaisseurChaise,this->position->z);
	glTexCoord2d(2,2); glVertex3d(this->position->x,this->position->y + hauteur - epaisseurChaise,this->position->z);
	glTexCoord2d(2,5); glVertex3d(this->position->x,this->position->y + hauteur,this->position->z);
	glTexCoord2d(5,5); glVertex3d(this->position->x + longueur,this->position->y + hauteur,this->position->z);
		
	glEnd() ;

	// // fermeture 4
	glBegin(GL_QUADS);

	glTexCoord2d(5,2); glVertex3d(this->position->x + longueur,this->position->y + hauteur - epaisseurChaise,this->position->z + largeur);
	glTexCoord2d(2,2); glVertex3d(this->position->x,this->position->y + hauteur - epaisseurChaise,this->position->z + largeur);
	glTexCoord2d(2,5); glVertex3d(this->position->x,this->position->y + hauteur,this->position->z + largeur);
	glTexCoord2d(5,5); glVertex3d(this->position->x + longueur,this->position->y + hauteur,this->position->z + largeur);
		
	glEnd() ;
}

void Chaise::drawPieds()
{
	glPushMatrix();
	glTranslated(position->x + longueur - 0.5,position->y,position->z + largeur - 0.5); // choix de l’emplacement cylindre
	glRotatef( -90, 1, 0, 0 );
	gluCylinder(quadriquePieds,0.3,0.3,this->position->y + hauteur,20,20);
	glPopMatrix();

	glPushMatrix();
	glTranslated(position->x  + 0.5,position->y,position->z  + largeur - 0.5); // choix de l’emplacement cylindre
	glRotatef( -90, 1, 0, 0 );
	gluCylinder(quadriquePieds,0.3,0.3,this->position->y + hauteur,20,20);
	glPopMatrix();

	glPushMatrix();
	glTranslated(position->x +longueur - 0.5,position->y,position->z + 0.5); // choix de l’emplacement cylindre
	glRotatef( -90, 1, 0, 0 );
	gluCylinder(quadriquePieds,0.3,0.3,this->position->y + hauteur,20,20);
	glPopMatrix();

	glPushMatrix();
	glTranslated(position->x + 0.5,position->y,position->z + 0.5); // choix de l’emplacement cylindre
	glRotatef( -90, 1, 0, 0 );
	gluCylinder(quadriquePieds,0.3,0.3,this->position->y + hauteur,20,20);
	glPopMatrix();

}

void Chaise::drawDossier()
{	
	double baseDossier = this->position->y + hauteur;

	glPushMatrix();
	glTranslated(position->x,baseDossier,position->z); // choix de l’emplacement cylindre
	glRotatef( -90, 1, 0, 0 );
	gluCylinder(quadriquePieds,0.2,0.2,baseDossier + hauteur/2,20,20);
	glPopMatrix();

	glPushMatrix();
	glTranslated(position->x + longueur,baseDossier,position->z); // choix de l’emplacement cylindre
	glRotatef( -90, 1, 0, 0 );
	gluCylinder(quadriquePieds,0.2,0.2,baseDossier + hauteur/2,20,20);
	glPopMatrix();
}

void Chaise::draw()
{

	this->drawPlateau();
	this->drawPieds();
	this->drawDossier();

	this->createHitboxes(position->x,position->y,position->z,longueur,this->hauteur + 5,this->largeur);

	//permet de ne pas créer le hitbox à l'infini
	hitboxCreated = true;
}
