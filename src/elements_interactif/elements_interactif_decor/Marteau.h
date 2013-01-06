#ifndef MARTEAU_H_INCLUDED
#define MARTEAU_H_INCLUDED

#include "../../elements/Element_Interactif_Decor_Quete.h"
#include <vector>
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "../../Cube.h"

using namespace std;

class Marteau: public ElementInteractifDecorQuete {

private:

	Cube* cubeTete;
	Cube* cubeManche;

public:
	Marteau(double, double, double, int, int, string, Etage*);
	~Marteau();
	void draw();

};

#endif // MARTEAU_H_INCLUDED
