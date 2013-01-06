#include "PnjQuete.h"

PnjQuete::PnjQuete(double x, double y, double z, char direction, string discour, int nbrQte, int qteActive ,string discourNormal, Etage* current) :
				Pnj(x, y, z, direction, discour) {

	/**
	 * PRINCIPE :
	 * on déclare un vector de bool correspondant au nombre de
	 */
	vector<bool> q(nbrQte, false);
	this->quete = &q;
	this->quete->at(qteActive) = true;
	this->blablaStandard = discourNormal;
	this->queteActive = false;
	this->currentStare = current;

}

void PnjQuete::interaction()
{
	if(!this->queteActive){
		this->activerQuete();
	}
	this->parler();
}

/**
 * Active la quetes de l'étage
 */
void PnjQuete::activerQuete(){

//	for(int i = 0; i < currentStare->getQuete()->size();i++){
//		currentStare->getQuete()[i] = quete[i] || currentStare->getQuete()[i];
//	}
	this->blabla = this->blablaStandard;
	this->queteActive = true;
}


PnjQuete::~PnjQuete() {

}

