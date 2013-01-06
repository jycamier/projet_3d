/*
 * PnjQuete.h
 *
 *  Created on: 6 janv. 2013
 *      Author: jean-yves
 */

#ifndef PNJQUETE_H_
#define PNJQUETE_H_
#include "../elements_interactif/elements_interactif_decor/Pnj.h"
#include "../etage.h"
#include <vector>
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include <string>

class PnjQuete: public Pnj {
protected:
	vector<bool> quete;
	vector<bool> queteCondition;
	int nbrQuete;
	bool queteActive;
	string blablaStandard;
	Etage* currentStare;
	void activerQuete();

public:
	PnjQuete(double, double, double, char, string, int, int, string, Etage*);
	void interaction();
	void parler();
	virtual ~PnjQuete();
	void setQueteConditionValue(int, bool);
};

#endif /* PNJQUETE_H_ */
