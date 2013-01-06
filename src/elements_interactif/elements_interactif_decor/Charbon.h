#ifndef CHARBON_H_INCLUDED
#define CHARBON_H_INCLUDED

#include "../../elements/Element_Interactif_Decor.h"
#include <vector>
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

using namespace std;

class Charbon : public ElementInteractifDecor {
	
	private :

		GLUquadricObj * quadriqueCharbon;
		int texture_charbon;
		
	public:
		Charbon(double,double,double);
		~Charbon();
		void draw();
		void interaction();


};


#endif // CHARBON_H_INCLUDED
