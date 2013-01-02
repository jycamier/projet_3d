#ifndef PNJ_H_INCLUDED
#define PNJ_H_INCLUDED

#include "../../elements/Element_Interactif_Decor.h"
#include <vector>
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
// #include <S>

using namespace std;

class Pnj : public ElementInteractifDecor {
	
	private :
		GLUquadricObj * quadriqueTete;
		GLUquadricObj * quadriqueTorse;
		GLUquadricObj * quadriqueBrasDroit;
		GLUquadricObj * quadriqueBrasGauche;
		GLUquadricObj * quadriqueJambeDroite;
		GLUquadricObj * quadriqueJambeGauche;
		int texture_happy;

		double orientation;

	public:
		Pnj(double,double,double,char);
		~Pnj();
		void draw();
};


#endif // PNJ_H_INCLUDED
