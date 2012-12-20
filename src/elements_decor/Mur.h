#ifndef MUR_H_INCLUDED
#define MUR_H_INCLUDED
#include "../elements/element_decor.h"
#include <vector>

using namespace std;

class Mur : public ElementDecor {
	private:
		double epaisseur;
		int hauteur;
		void drawVerticalClosing(Point);
		void drawHorizontalClosing(Point);
	public:

		vector<Point> coordinates;

		Mur();
		Mur(double,double,double,vector <Point>, double);
		bool isHorizontal(Point , Point);
		bool isVertical(Point, Point);
		void draw();
		~Mur();
};		

#endif //MUR_H_INCLUDED
