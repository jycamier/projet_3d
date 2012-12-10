/*
 * Personnage.h
 *
 *  Created on: 10 déc. 2012
 *      Author: jean-yves
 */

#ifndef PERSONNAGE_H_
#define PERSONNAGE_H_

#include <math.h>

class Personnage {
protected:
	double x;
	double y;
	double z;
	int angle;
	int pas;

public:
	Personnage(double x, double y, double z, int angle);
	virtual ~Personnage();

	void avancer();
	void reculer();
	void tournerGauche();
	void tournerDroite();

	void updateCamera();

	int getAngle() const {
		return angle;
	}

	void setAngle(int angle) {
		this->angle = angle;
	}

	int getPas() const {
		return pas;
	}

	double getX() const {
		return x;
	}

	void setX(double x) {
		this->x = x;
	}

	double getY() const {
		return y;
	}

	void setY(double y) {
		this->y = y;
	}

	double getZ() const {
		return z;
	}

	void setZ(double z) {
		this->z = z;
	}
};

#endif /* PERSONNAGE_H_ */
