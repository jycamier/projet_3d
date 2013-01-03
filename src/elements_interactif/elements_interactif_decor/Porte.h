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
		double calculerDistance(double,double);
		void openDoor();
		void closeDoor();
		vector<AABB3D> getHitboxes()const;
};


#endif // PORTE_H_INCLUDED
