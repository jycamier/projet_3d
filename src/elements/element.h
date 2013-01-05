#ifndef ELEMENT_H
#define ELEMENT_H

//#define TEST_HITBOX

#include "../utils/point.h"
#include <vector>
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>

using namespace std;

struct AABB3D {
	float x, y, z;
	float w, h, d;
};

class Element {
protected:
	vector<AABB3D> _hitboxes;
  	Point *position;
	virtual void UpdateHitbox();
	bool hitboxCreated;
public:
	Element();
	virtual ~Element();

	double calculerDistance(double a, double b);

	virtual vector<AABB3D> getHitboxes() const {
		return _hitboxes;
	}

	void createHitboxes(AABB3D* hb);
	void createHitboxes(double x, double y, double z, double w, double h,
			double d);

	/**
	 * méthode de TEST
	 */
	void drawHitboxes();

	Point* getPosition() const {
		return position;
	}
};

#endif
