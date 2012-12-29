#ifndef GUICHET_H_INCLUDED
#define GUICHET_H_INCLUDED
#include "../elements/element_decor.h"
#include "Mur.h"
#include "Pilier.h"
#include <vector>

class Guichet : public ElementDecor {
	private:
		double heigth;
		double length;
		double width;
	public:

		vector<Mur*> walls;
		vector<Pilier*> bars;

		Guichet();
		Guichet(double, double, double,double,double,double);
		void draw();
		~Guichet();
};


#endif //GUICHET_H_INCLUDED
