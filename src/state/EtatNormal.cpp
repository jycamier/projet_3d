#include "EtatNormal.h"

EtatNormal::EtatNormal(FreeFlyCamera * charac) : EtatCharacter(charac)
{
}


void EtatNormal::modifierComportement()
{
	this->perso->_keyconf["strafe_left"] = SDLK_q;
	this->perso->_keyconf["strafe_right"] = SDLK_d;
	this->perso->_keyconf["forward"] = SDLK_z;
	this->perso->_keyconf["backward"] = SDLK_s;
	this->perso->_sensivity = 0.2;
}

EtatNormal::~EtatNormal()
{
	
}