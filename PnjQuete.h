#ifndef PNJ_H_INCLUDED
#define PNJ_H_INCLUDED

#include "../elements_interactif/elements_interactif_decor/Pnj.h"
#include "../etage.h"
#include <vector>
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include <string>

using namespace std;

class PnjQuete : public Pnj {
	
	protected :
		vector<bool>* quete;
		int nbrQuete;
		bool queteActive;
		string blablaStandard;
		Etage* currentStare;
		void activerQuete();

	public:
		PnjQuete(double,double,double,char,string,int,int,string,Etage*);
		void interaction();
		void parler();
		~PnjQuete();
		void draw();
};


#endif // PNJ_H_INCLUDED
