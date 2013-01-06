#ifndef SUCRE_H_INCLUDED
#define SUCRE_H_INCLUDED

#include "../../elements/Element_Interactif_Decor.h"
#include <vector>
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "../../Cube.h"

using namespace std;

class Sucre : public ElementInteractifDecor {
	
	private :

		Cube* cube;
		int texture_sucre;
		
	public:
		Sucre(double,double,double);
		~Sucre();
		void draw();
		void interaction();


};


#endif // SUCRE_H_INCLUDED
