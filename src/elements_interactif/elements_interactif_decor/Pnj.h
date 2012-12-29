#ifndef PNJ_H_INCLUDED
#define PNJ_H_INCLUDED

#include "../../elements/Element_Interactif_Decor.h"
#include <vector>
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

using namespace std;

class Pnj : public ElementInteractifDecor {
	
	private :
		GLUquadricObj * quadriqueTete;
		GLUquadricObj * quadriqueTorse;
		int texture_happy;

	public:
		Pnj(double,double,double);
		~Pnj();
		void draw();
};


#endif // PNJ_H_INCLUDED