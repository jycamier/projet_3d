/*
 * ElementInteractifDecorQuete.cpp
 *
 *  Created on: 6 janv. 2013
 *      Author: jean-yves
 */

#include "Element_Interactif_Decor_Quete.h"

ElementInteractifDecorQuete::ElementInteractifDecorQuete(double x, double y,
		double z, int nbrQte, int qteActive, string discourNormal,
		Etage* current) :
		ElementInteractifDecor(x, y, z) {
	// TODO Auto-generated constructor stub

	this->talk = false;
	/**
	 * PRINCIPE :
	 * on déclare un vector de bool correspondant au nombre de
	 */
	this->nbrQuete = nbrQte;
	for (int i = 0; i < nbrQuete; i++) {
		if (i == qteActive)
			quete.push_back(true);
		else
			quete.push_back(false);

		queteCondition.push_back(false);
	}
	this->blabla = discourNormal;
	this->queteActive = false;
	this->currentStare = current;

}

ElementInteractifDecorQuete::~ElementInteractifDecorQuete() {
	// TODO Auto-generated destructor stub
}

void ElementInteractifDecorQuete::draw() {

}

void ElementInteractifDecorQuete::interaction() {
	this->balancerBlabla();
	if (!this->queteActive) {
		this->activerQuete();
	}
}

void ElementInteractifDecorQuete::balancerBlabla() {

	if (this->talk) {
		this->talk = false;
	} else {
		this->talk = true;

	}
}

void ElementInteractifDecorQuete::activerQuete() {
	bool tmpCondition = true;
	int i = 0;

	/**
	 * Vérifier que les conditions de validité de la quête sont respecté.
	 */
	while (i < currentStare->getQuete().size()) {
		if (queteCondition.at(i)) {
			if (queteCondition.at(i) != currentStare->getQuete().at(i))
				tmpCondition = false;
		}
		i++;
	}

	/**
	 * Si respecté, valider la quete
	 */
	if (tmpCondition) {
		for (int i = 0; i < currentStare->getQuete().size(); i++) {
			currentStare->setQueteValue(i,
					quete.at(i) || currentStare->getQuete().at(i));
		}

		this->queteActive = true;
	}
}

void ElementInteractifDecorQuete::setQueteConditionValue(int i, bool val) {
	this->queteCondition.at(i) = val;
}
