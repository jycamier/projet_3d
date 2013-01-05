#ifndef ETAGE_FACTORY_H_INCLUDED
#define ETAGE_FACTORY_H_INCLUDED

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "../etage.h"
#include <iostream> 
#include <vector>

using namespace std;

class EtageFactory {
private:
	Etage* currentStare;
	vector<Etage*> etages;
	Etage* createEtage(int);

public:

	EtageFactory();
	~EtageFactory();
	void loadEtage(int);
	void draw();

	vector<Etage*> getEtages() const {
		return etages;
	}

	Etage* getCurrentStare() const {
		return currentStare;
	}
};

#endif // ETAGE_FACTORY_H_INCLUDED
