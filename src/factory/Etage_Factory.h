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
		vector<Etage*> etages;
		Etage* createEtage(int);

	public:

		EtageFactory();
		~EtageFactory();
		Etage* loadEtage(int);

		vector<Etage*> getEtages() const {
			return etages;
		}




};

#endif // ETAGE_FACTORY_H_INCLUDED
