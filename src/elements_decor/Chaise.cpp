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
	this->orientation = direction;
		
}
Chaise::~Chaise(){

}

void Chaise::drawPlateau()
{
	//plateau
	glBindTexture(GL_TEXTURE_2D, textureChaise);

	glBegin(GL_QUADS);		
	glColor3ub(0,51,0);

	glTexCoord2d(20,10); glVertex3d(this->position->x ,this->position->y + hauteur,this->position->z);
	glTexCoord2d(10,10); glVertex3d(this->position->x,this->position->y + hauteur,this->position->z + largeur);
	glTexCoord2d(10,20); glVertex3d(this->position->x + longueur,this->position->y + hauteur,this->position->z + largeur);
	glTexCoord2d(20,20); glVertex3d(this->position->x + longueur,this->position->y + hauteur,this->position->z);

	glEnd() ;

	//epaisseur
	glBegin(GL_QUADS);		
	glColor3ub(0,51,0);

	glTexCoord2d(20,10); glVertex3d(this->position->x ,this->position->y + hauteur - epaisseurChaise,this->position->z);
	glTexCoord2d(10,10); glVertex3d(this->position->x,this->position->y + hauteur - epaisseurChaise,this->position->z + largeur);
	glTexCoord2d(10,20); glVertex3d(this->position->x + longueur,this->position->y + hauteur - epaisseurChaise,this->position->z + largeur);
	glTexCoord2d(20,20); glVertex3d(this->position->x + longueur,this->position->y + hauteur - epaisseurChaise,this->position->z);

	glEnd() ;


	//fermeture 1
	glBegin(GL_QUADS);
	glColor3ub(255,0,255);

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
	glColor3ub(51,51,51);
	glPushMatrix();
	glTranslated(position->x + longueur - 0.5,position->y,position->z + largeur - 0.5); // choix de l’emplacement cylindre
	glRotatef( -90, 1, 0, 0 );
	gluCylinder(quadriquePieds,0.3,0.3,this->position->y + hauteur,20,20);
	glPopMatrix();

	glColor3ub(51,51,51);
	glPushMatrix();
	glTranslated(position->x  + 0.5,position->y,position->z  + largeur - 0.5); // choix de l’emplacement cylindre
	glRotatef( -90, 1, 0, 0 );
	gluCylinder(quadriquePieds,0.3,0.3,this->position->y + hauteur,20,20);
	glPopMatrix();

	glColor3ub(51,51,51);
	glPushMatrix();
	glTranslated(position->x +longueur - 0.5,position->y,position->z + 0.5); // choix de l’emplacement cylindre
	glRotatef( -90, 1, 0, 0 );
	gluCylinder(quadriquePieds,0.3,0.3,this->position->y + hauteur,20,20);
	glPopMatrix();

	glColor3ub(51,51,51);
	glPushMatrix();
	glTranslated(position->x + 0.5,position->y,position->z + 0.5); // choix de l’emplacement cylindre
	glRotatef( -90, 1, 0, 0 );
	gluCylinder(quadriquePieds,0.3,0.3,this->position->y + hauteur,20,20);
	glPopMatrix();

}

void Chaise::drawDossier()
{	
	double baseDossier = this->position->y + hauteur;
	double xDossierBarreau1 = 0;
	double zDossierBarreau1 = 0;
	double xDossierBarreau2 = 0;
	double zDossierBarreau2 = 0;


	if (this->orientation == 'S')
	{	
		xDossierBarreau1 = position->x;
		zDossierBarreau1 = position->z;

		xDossierBarreau2 = position->x + longueur;
		zDossierBarreau2 = position->z;

	}
	else if (this->orientation == 'N')
	{

		xDossierBarreau1 = position->x + longueur;
		zDossierBarreau1 = position->z + largeur;

		xDossierBarreau2 = position->x;
		zDossierBarreau2 = position->z  + largeur;

	}
	else if(this->orientation == 'E')
	{
		xDossierBarreau1 = position->x;
		zDossierBarreau1 = position->z;

		xDossierBarreau2 = position->x ;
		zDossierBarreau2 = position->z  + largeur;
	}
	else
	{
		xDossierBarreau1 = position->x + longueur;
		zDossierBarreau1 = position->z;

		xDossierBarreau2 = position->x + longueur;
		zDossierBarreau2 = position->z + largeur;
	}

		glPushMatrix();
		glTranslated(xDossierBarreau1,baseDossier,zDossierBarreau1); // choix de l’emplacement cylindre
		glRotatef( -90, 1, 0, 0 );
		gluCylinder(quadriquePieds,0.2,0.2,baseDossier + hauteur/2,20,20);
		glPopMatrix();

		glPushMatrix();
		glTranslated(xDossierBarreau2 ,baseDossier,zDossierBarreau2); // choix de l’emplacement cylindre
		glRotatef( -90, 1, 0, 0 );
		gluCylinder(quadriquePieds,0.2,0.2,baseDossier + hauteur/2,20,20);
		glPopMatrix();

		// glPushMatrix();
		// glTranslated(xDossierBarreau1 ,baseDossier + hauteur/2,zDossierBarreau1); // choix de l’emplacement cylindre
		// // glRotatef( -90, 1, 0, 0 );
		// gluCylinder(quadriquePieds,0.2,0.2,baseDossier + hauteur/2,20,20);
		// glPopMatrix();

		// glPushMatrix();
		// glTranslated(xDossierBarreau1 ,(baseDossier + hauteur/2)+1,zDossierBarreau1); // choix de l’emplacement cylindre
		// // glRotatef( -90, 1, 0, 0 );
		// gluCylinder(quadriquePieds,0.2,0.2,baseDossier + hauteur/2,20,20);
		// glPopMatrix();		

		glPushMatrix();
		glTranslated(xDossierBarreau2 ,baseDossier + hauteur/2,zDossierBarreau1); // choix de l’emplacement cylindre
		// glRotatef( -90, 1, 0, 0 );
		gluCylinder(quadriquePieds,0.2,0.2,baseDossier + hauteur/2,20,20);
		glPopMatrix();

		glPushMatrix();
		glTranslated(xDossierBarreau2 ,(baseDossier + hauteur/2)+1,zDossierBarreau1); // choix de l’emplacement cylindre
		// glRotatef( -90, 1, 0, 0 );
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
