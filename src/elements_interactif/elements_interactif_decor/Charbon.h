#ifndef CHARBON_H_INCLUDED
#define CHARBON_H_INCLUDED

#include "../../elements/Element_Interactif_Decor_Quete.h"
#include <vector>
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

using namespace std;

class Charbon: public ElementInteractifDecorQuete {

private:

	GLUquadricObj * quadriqueCharbon;
	int texture_charbon;

public:
	Charbon(double, double, double, int, int, string, Etage*);
	~Charbon();
	void draw();

};

#endif // CHARBON_H_INCLUDED
