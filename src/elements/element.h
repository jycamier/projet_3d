#ifndef ELEMENT_H
#define ELEMENT_H

#include "../utils/point.h"
#include <vector>

using namespace std;

struct AABB3D {
	float x, y, z;
	float w, h, d;
};

class Element {
protected:
	AABB3D _hitbox;
	vector<AABB3D> _hitboxes;

	virtual void UpdateHitbox();
public:
	Element();
	virtual ~Element();
	const AABB3D& getHitbox() const {
		return _hitbox;
	}

	double calculerDistance(double a, double b);

	virtual vector<AABB3D> getHitboxes() const {
		return _hitboxes;
	}
};

#endif
