#ifndef ESCALIER_H_INCLUDED
#define ESCALIER_H_INCLUDED
#include "../elements/element_decor.h"
#include "../utils//point.h"

using namespace std;

class Escalier : public ElementDecor {
	private:
		Point* extremite;
	public:
		Escalier();
		Escalier(double,double,double,double,double,double);
		void draw();
		void drawHorizontalStairs();
		void drawVerticalStairs();
		~Escalier();
};		

#endif //ESCALIER_H_INCLUDED
