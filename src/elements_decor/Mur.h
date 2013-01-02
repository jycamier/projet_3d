#ifndef MUR_H_INCLUDED
#define MUR_H_INCLUDED
#include "../elements/element_decor.h"

using namespace std;

class Mur : public ElementDecor {
	private:
		double epaisseur;
		double hauteur;
		int texture;

		vector<AABB3D> _hitboxes;

		bool hitboxCreated;

		void drawVerticalClosing(Point);
		void drawHorizontalClosing(Point);

	public:

		vector<Point> coordinates;

		Mur();
		Mur(double,double,double,vector <Point>, double, int);
		bool isHorizontal(Point , Point);
		bool isVertical(Point, Point);
		void draw();
		~Mur();

		void createHitboxes(double x, double y, double z, double w, double h, double d);

		void UpdateHitbox();

		vector<AABB3D> getHitboxes() const {
			return _hitboxes;
		}
};		

#endif //MUR_H_INCLUDED
