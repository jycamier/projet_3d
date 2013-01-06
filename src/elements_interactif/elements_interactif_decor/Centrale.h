#ifndef CENTRALE_H_INCLUDED
#define CENTRALE_H_INCLUDED

#include "../../elements/Element_Interactif_Decor_Quete.h"
#include <vector>
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "../../Cube.h"

using namespace std;

class Centrale : public ElementInteractifDecorQuete {
	
	private :
		
		Cube* cubeCentrale;
		Cube* cubeFeu;
		double longueur;
        double largeur;
        double hauteur;

		
	public:

		Centrale(double,double,double,double,double,double, int, int, string, Etage*);
		~Centrale();
		void draw();


};


#endif // CENTRALE_H_INCLUDED
