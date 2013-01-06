#ifndef CENTRALE_H_INCLUDED
#define CENTRALE_H_INCLUDED

#include "../../elements/Element_Interactif_Decor.h"
#include <vector>
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "../../Cube.h"

using namespace std;

class Centrale : public ElementInteractifDecor {
	
	private :
		
		Cube* cubeCentrale;
		Cube* cubeFeu;
		double longueur;
        double largeur;
        double hauteur;

		
	public:

		Centrale(double,double,double,double,double,double);
		~Centrale();
		void draw();
		void interaction();


};


#endif // CENTRALE_H_INCLUDED
