#include "Tableau.h"

Tableau::Tableau(double x, double y, double z, double longu, double larg, double haut, char direction, int textu) : ElementDecor(x, y, z)
{
	this->image_tableau = 0;
	this->epaisseur = 0.35;
	this->hauteur = longu;
	this->longueur = haut;
	this->largeur = larg;
	this->orientation = direction;

	this->cube = new Cube(x,y,z,longu,haut,larg);
	this->cube->texture_face6 = textu;
	this->cube->texture_face4 = textu;
	this->cube->texture_face3 = textu;
	this->cube->texture_face5 = textu;
	this->cube->texture_face1 = textu;
	this->cube->texture_face2 = textu;
		
}
Tableau::~Tableau(){

}



void Tableau::draw()
{

	this->cube->draw();
	this->createHitboxes(position->x,position->y,position->z,longueur,this->hauteur + 5,this->largeur);

	//permet de ne pas créer le hitbox à l'infini
	hitboxCreated = true;
}
