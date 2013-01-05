#include "EtatMaboul.h"

EtatMaboul::EtatMaboul(FreeFlyCamera * charac) : EtatCharacter(charac)
{
}


void EtatMaboul::modifierComportement()
{
	this->perso->_keyconf["forward"] = SDLK_s;
	this->perso->_keyconf["backward"] = SDLK_z;
	this->perso->_keyconf["strafe_left"] = SDLK_d;
	this->perso->_keyconf["strafe_right"] = SDLK_LSHIFT;
	this->perso->_keyconf["boost"] = SDLK_q;
	this->perso->_sensivity = 5;
}

EtatMaboul::~EtatMaboul()
{
	
}