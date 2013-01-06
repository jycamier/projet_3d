#ifndef SUCRE_H_INCLUDED
#define SUCRE_H_INCLUDED

#include "../../elements/Element_Interactif_Decor_Quete.h"
#include <vector>
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "../../Cube.h"

using namespace std;

class Sucre: public ElementInteractifDecorQuete {

private:

	Cube* cube;
	int texture_sucre;

public:
	Sucre(double, double, double, int, int, string, Etage*);
	~Sucre();
	void draw();

};

#endif // SUCRE_H_INCLUDED
