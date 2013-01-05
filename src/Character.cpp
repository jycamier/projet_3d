#include "Character.h"

Character::Character(const Vector3D & position) : FreeFlyCamera(position)
{
	this->fou = false;
	this->etat = new EtatNormal(this);
}


void Character::animate(Uint32 timestep)
{
	this->etat->modifierComportement();
	FreeFlyCamera::animate(timestep);
}

Character::~Character()
{
	
}
