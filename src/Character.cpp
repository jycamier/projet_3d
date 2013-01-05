#include "Character.h"

Character::Character(const Vector3D & position) : FreeFlyCamera(position)
{
	this->fou = false;
}

void Character::changerDirection()
{
	_keyconf["forward"] = SDLK_s;
	_keyconf["backward"] = SDLK_z;
}

void Character::remettreDirection()
{
	_keyconf["forward"] = SDLK_z;
	_keyconf["backward"] = SDLK_s;
}


Character::~Character()
{
	
}