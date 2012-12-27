#include <GL/gl.h>
#include <GL/glu.h>
#include "Etage_Factory.h"
#include "../etage.h"
#include "../sdlglutils.h"

EtageFactory::EtageFactory()
{

}

Etage* EtageFactory::createEtage()
{
	int plafond = loadTexture("textures/plafond1.jpg");
	int sol = loadTexture("textures/carrelage1.jpg");
	int mur1 = loadTexture("textures/mur1.jpg");

	return new Etage(80,15,80,plafond,sol,mur1,0);
}

EtageFactory::~EtageFactory()
{

}

