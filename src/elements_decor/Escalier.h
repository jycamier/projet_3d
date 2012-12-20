#ifndef ESCALIER_H_INCLUDED
#define ESCALIER_H_INCLUDED
#include "../elements/element_decor.h"

using namespace std;

class Escalier : public ElementDecor {
	private:
		int hauteur;
	public:
		Escalier();
		Escalier(double,double,double, int);
		void draw();
		~Escalier();
};		

#endif //ESCALIER_H_INCLUDED
