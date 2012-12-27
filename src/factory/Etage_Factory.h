#ifndef ETAGE_FACTORY_H_INCLUDED
#define ETAGE_FACTORY_H_INCLUDED

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "../etage.h"
#include <iostream> 

using namespace std;

class EtageFactory
{
	private :

	public :

		EtageFactory();
		Etage* createEtage(int);
		~EtageFactory();

};

#endif // ETAGE_FACTORY_H_INCLUDED