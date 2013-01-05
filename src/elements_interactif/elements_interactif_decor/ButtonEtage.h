#ifndef BUTTON_ETAGE_H_INCLUDED
#define BUTTON_ETAGE_H_INCLUDED

#include "../../elements/Element_Interactif_Decor.h"
#include "../../factory/Etage_Factory.h"
#include <vector>
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

using namespace std;

class ButtonEtage: public Button {

private:

	EtageFactory* factory;
	int etage;

public:
	ButtonEtage(double, double, double, char, double, int, EtageFactory*, int);
	~ButtonEtage();
	void interaction();

};

#endif // BUTTON_H_INCLUDED
