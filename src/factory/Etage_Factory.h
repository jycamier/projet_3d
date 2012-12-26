#ifndef ETAGE_FACTORY_H_INCLUDED
#define ETAGE_FACTORY_H_INCLUDED

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "../etage.h"

class EtageFactory
{
	private :

	public :

		EtageFactory();
		Etage* createEtage();
		~EtageFactory();


};

#endif // ETAGE_FACTORY_H_INCLUDED