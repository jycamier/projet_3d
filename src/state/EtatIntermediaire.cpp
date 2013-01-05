#include "EtatIntermediaire.h"

EtatIntermediaire::EtatIntermediaire(FreeFlyCamera * charac) : EtatCharacter(charac)
{
}


void EtatIntermediaire::modifierComportement()
{
	this->perso->_keyconf["forward"] = SDLK_s;
	this->perso->_keyconf["backward"] = SDLK_z;
}

EtatIntermediaire::~EtatIntermediaire()
{
	
}