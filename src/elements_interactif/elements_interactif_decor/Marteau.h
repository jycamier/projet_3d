#ifndef MARTEAU_H_INCLUDED
#define MARTEAU_H_INCLUDED

#include "../../elements/Element_Interactif_Decor.h"
#include <vector>
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "../../Cube.h"

using namespace std;

class Marteau : public ElementInteractifDecor {
	
	private :

		Cube* cubeTete;
		Cube* cubeManche;
		
	public:
		Marteau(double,double,double);
		~Marteau();
		void draw();
		void interaction();


};


#endif // MARTEAU_H_INCLUDED
