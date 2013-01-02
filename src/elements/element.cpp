#include "element.h"

Element::Element() {	
}

Element::~Element() {	
}

void Element::UpdateHitbox(){
// méthode virtuel
}


double Element::calculerDistance(double a, double b){

	if (a < b){
		return b-a;
	}else if(b < a){
		return a-b;
	}

}

/**
 * Méthode permettant de déssiner les méthodes graphiquement
 */

void Element::drawHitboxes(){
#ifdef TEST_HITBOX
	for (int i = 0; i < _hitboxes.size() ; i++){
		glBegin (GL_LINE_LOOP);
		glColor3ub(0, 255, 255);
		glVertex3d(_hitboxes.at(i).x, _hitboxes.at(i).y, _hitboxes.at(i).z);
		glVertex3d(_hitboxes.at(i).x+_hitboxes.at(i).w, _hitboxes.at(i).y, _hitboxes.at(i).z);
		glVertex3d(_hitboxes.at(i).x+_hitboxes.at(i).w, _hitboxes.at(i).y+_hitboxes.at(i).h, _hitboxes.at(i).z);
		glVertex3d(_hitboxes.at(i).x, _hitboxes.at(i).y+_hitboxes.at(i).h, _hitboxes.at(i).z);
		glEnd();

		glBegin (GL_LINE_LOOP);
		glColor3ub(0, 255, 255);
		glVertex3d(_hitboxes.at(i).x, _hitboxes.at(i).y, _hitboxes.at(i).z+_hitboxes.at(i).d);
		glVertex3d(_hitboxes.at(i).x+_hitboxes.at(i).w, _hitboxes.at(i).y, _hitboxes.at(i).z+_hitboxes.at(i).d);
		glVertex3d(_hitboxes.at(i).x+_hitboxes.at(i).w, _hitboxes.at(i).y+_hitboxes.at(i).h, _hitboxes.at(i).z+_hitboxes.at(i).d);
		glVertex3d(_hitboxes.at(i).x, _hitboxes.at(i).y+_hitboxes.at(i).h, _hitboxes.at(i).z+_hitboxes.at(i).d);
		glEnd();
	}
#endif
}
void Element::createHitboxes(double x, double y, double z, double w, double h,
		double d) {

	if(!hitboxCreated){
		AABB3D hitb = { x, y, z, w, h, d };
		this->_hitboxes.push_back(hitb);
	}

	this->drawHitboxes();

}


