#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED

#include "../../elements/Element_Interactif_Decor.h"
#include <vector>
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

using namespace std;

class Button : public ElementInteractifDecor {
	
	private :
		int texture_button;
		double longeur_epaisseur;
		double diametre;
		double orientation;
		GLUquadricObj * quadriqueFace;
		GLUquadricObj * quadriqueFesse;
		GLUquadricObj * quadriqueEpaisseur;
		
		//Le bouton permet de lancer des intéractions avec les élementsdu décors
		ElementInteractifDecor * eltInteractifAssocie;

	public:
		Button(double,double,double,char,double,int);
		Button(double,double,double,char,double,int,ElementInteractifDecor *);
		~Button();
		void draw();
		void interaction();

//	const ElementInteractifDecor*& getEltInteractifAssocie() const {
//		return eltInteractifAssocie;
//	}
//
//	void setEltInteractifAssocie(
//			const ElementInteractifDecor*& eltInteractifAssocie) {
//		this->eltInteractifAssocie = eltInteractifAssocie;
//	}
};


#endif // BUTTON_H_INCLUDED
