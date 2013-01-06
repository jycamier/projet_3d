/*
 * PnjQuete.cpp
 *
 *  Created on: 6 janv. 2013
 *      Author: jean-yves
 */

#include "PnjQuete.h"

PnjQuete::PnjQuete(double x, double y, double z, char direction, string discour,
		int nbrQte, int qteActive, string discourNormal, Etage* current) :
		Pnj(x, y, z, direction, discour) {
	// TODO Auto-generated constructor stub

	/**
	 * PRINCIPE :
	 * on déclare un vector de bool correspondant au nombre de
	 */
	this->nbrQuete = nbrQte;
	for(int i = 0; i < nbrQuete;i++){
		if(i==qteActive)
			quete.push_back(true);
		else
			quete.push_back(false);

		queteCondition.push_back(false);
	}
	this->blablaStandard = discourNormal;
	this->queteActive = false;
	this->currentStare = current;

}

void PnjQuete::interaction()
{
	this->parler();
	if(!this->queteActive){
		this->activerQuete();
	}
}

/**
 * Active la quetes de l'étage
 */
void PnjQuete::activerQuete(){

	bool tmpCondition = true;
	int i = 0;

	/**
	 * Vérifier que les conditions de validité de la quête sont respecté.
	 */
	while(i < currentStare->getQuete().size()){
		if(queteCondition.at(i)){
			if(queteCondition.at(i) != currentStare->getQuete().at(i))
						tmpCondition = false;
		}
		i++;
	}

	/**
	 * Si respecté, valider la quete
	 */
	if(tmpCondition){
		for(int i = 0; i < currentStare->getQuete().size();i++){
				currentStare->setQueteValue(i,quete.at(i) || currentStare->getQuete().at(i));
		}

		this->queteActive = true;
	}

}

void PnjQuete::parler()
{
	if (this->talk)
	{
		this->talk = false;
		this->blabla = this->blablaStandard;
	}
	else
	{
		this->talk = true;

	}
}

void PnjQuete::setQueteConditionValue(int i, bool val){
	this->queteCondition.at(i) = val;
}

PnjQuete::~PnjQuete() {
	// TODO Auto-generated destructor stub
}

