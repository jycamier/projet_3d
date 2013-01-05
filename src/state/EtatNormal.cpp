#include "EtatNormal.h"

EtatNormal::EtatNormal(FreeFlyCamera * charac) : EtatCharacter(charac)
{
}


void EtatNormal::modifierComportement()
{
	this->perso->_keyconf["forward"] = SDLK_z;
	this->perso->_keyconf["backward"] = SDLK_s;
}

EtatNormal::~EtatNormal()
{
	
}