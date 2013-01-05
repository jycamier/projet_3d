#ifndef PNJ_H_INCLUDED
#define PNJ_H_INCLUDED

#include "../../elements/Element_Interactif_Decor.h"
#include <vector>
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include <string>

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
		int texture_jambes;
		int texture_torse;
		char* blabla;
		bool talk;

		double orientation;

	public:
		Pnj(double,double,double,char,char*);
		void interaction();
		void parler();
		~Pnj();
		void draw();
};


#endif // PNJ_H_INCLUDED
