#ifndef PORTE_H_INCLUDED
#define PORTE_H_INCLUDED

#include "../../elements/Element_Interactif_Decor.h"
#include <vector>
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "../../elements_decor/Mur.h"

using namespace std;

class Porte : public ElementInteractifDecor {
	
	private :
		int texture_porte;
		char orientation;
		double taillePorte;
		double height;
		Mur* door;
		bool open;

	public:
		Porte(double,double,double,char,double,double);
		~Porte();
		void draw();
		void interaction();
		void openDoor();
		void closeDoor();
};


#endif // PORTE_H_INCLUDED