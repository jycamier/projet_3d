#include "Table.h"

Table::Table(double x, double y, double z, int text, double longu, double larg,double haut) : ElementDecor(x, y, z)
{
	quadriquePieds = gluNewQuadric();
	this->textureTable = text;
	this->epaisseurTable = 0.35;
	this->hauteur = haut;
	this->longueur = longu;
	this->largeur = larg;
}
Table::~Table(){

}

void Table::drawPlateau()
{
	//table
	glBindTexture(GL_TEXTURE_2D, textureTable);

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

	glTexCoord2d(20,10); glVertex3d(this->position->x ,this->position->y + hauteur - epaisseurTable,this->position->z);
	glTexCoord2d(10,10); glVertex3d(this->position->x,this->position->y + hauteur - epaisseurTable,this->position->z + largeur);
	glTexCoord2d(10,20); glVertex3d(this->position->x + longueur,this->position->y + hauteur - epaisseurTable,this->position->z + largeur);
	glTexCoord2d(20,20); glVertex3d(this->position->x + longueur,this->position->y + hauteur - epaisseurTable,this->position->z);

	glEnd() ;


	//fermeture 1
	glBegin(GL_QUADS);
	glColor3ub(0,0,255);

	glTexCoord2d(5,2); glVertex3d(this->position->x,this->position->y + hauteur - epaisseurTable,this->position->z);
	glTexCoord2d(2,2); glVertex3d(this->position->x,this->position->y + hauteur - epaisseurTable,this->position->z + largeur);
	glTexCoord2d(2,5); glVertex3d(this->position->x,this->position->y + hauteur,this->position->z + largeur);
	glTexCoord2d(5,5); glVertex3d(this->position->x,this->position->y + hauteur,this->position->z);
		
	glEnd() ;

	// fermeture 2
	glBegin(GL_QUADS);

	glTexCoord2d(5,2); glVertex3d(this->position->x + longueur,this->position->y + hauteur - epaisseurTable,this->position->z);
	glTexCoord2d(2,2); glVertex3d(this->position->x + longueur,this->position->y + hauteur - epaisseurTable,this->position->z + largeur);
	glTexCoord2d(2,5); glVertex3d(this->position->x + longueur,this->position->y + hauteur,this->position->z + largeur);
	glTexCoord2d(5,5); glVertex3d(this->position->x + longueur,this->position->y + hauteur,this->position->z);

	glEnd() ;


	// fermeture 3
	glBegin(GL_QUADS);

	glTexCoord2d(5,2); glVertex3d(this->position->x + longueur,this->position->y + hauteur - epaisseurTable,this->position->z);
	glTexCoord2d(2,2); glVertex3d(this->position->x,this->position->y + hauteur - epaisseurTable,this->position->z);
	glTexCoord2d(2,5); glVertex3d(this->position->x,this->position->y + hauteur,this->position->z);
	glTexCoord2d(5,5); glVertex3d(this->position->x + longueur,this->position->y + hauteur,this->position->z);
		
	glEnd() ;

	// // fermeture 4
	glBegin(GL_QUADS);

	glTexCoord2d(5,2); glVertex3d(this->position->x + longueur,this->position->y + hauteur - epaisseurTable,this->position->z + largeur);
	glTexCoord2d(2,2); glVertex3d(this->position->x,this->position->y + hauteur - epaisseurTable,this->position->z + largeur);
	glTexCoord2d(2,5); glVertex3d(this->position->x,this->position->y + hauteur,this->position->z + largeur);
	glTexCoord2d(5,5); glVertex3d(this->position->x + longueur,this->position->y + hauteur,this->position->z + largeur);
		
	glEnd() ;
}

void Table::drawPieds()
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

void Table::draw()
{
	this->drawPlateau();
	this->drawPieds();

	this->createHitboxes(position->x,position->y,position->z,longueur,this->hauteur + 5,this->largeur);

	//permet de ne pas créer le hitbox à l'infini
	hitboxCreated = true;
}
