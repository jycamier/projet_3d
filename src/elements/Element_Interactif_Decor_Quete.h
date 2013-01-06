/*
 * ElementInteractifDecorQuete.h
 *
 *  Created on: 6 janv. 2013
 *      Author: jean-yves
 */

#ifndef ELEMENTINTERACTIFDECORQUETE_H_
#define ELEMENTINTERACTIFDECORQUETE_H_
#include "Element_Interactif_Decor.h"
#include "../etage.h"
#include <vector>
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include <string>

class ElementInteractifDecorQuete: public ElementInteractifDecor {
protected:
	vector<bool> quete;
	vector<bool> queteCondition;
	int nbrQuete;
	bool queteActive;
	bool talk;
	string blabla;
	Etage* currentStare;
	void activerQuete();

public:
	ElementInteractifDecorQuete(double, double, double, int, int, string,
			Etage*);
	virtual void draw();

	void interaction();
	void balancerBlabla();
	void setQueteConditionValue(int, bool);

	virtual ~ElementInteractifDecorQuete();
};

#endif /* ELEMENTINTERACTIFDECORQUETE_H_ */
