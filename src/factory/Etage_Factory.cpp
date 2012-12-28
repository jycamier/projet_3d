#include <GL/gl.h>
#include <GL/glu.h>
#include "Etage_Factory.h"
#include "../etage.h"
#include "../sdlglutils.h"
#include "../elements_decor/Mur.h"
#include "../elements_decor/Pilier.h"
#include "../elements_decor/fountain.h"
#include "../elements_decor/Escalier.h"

EtageFactory::EtageFactory()
{

}

Etage* EtageFactory::createEtage(int etage)
{
	int texture_plafond;
	int texture_sol;
	int texture_murs;

	switch(etage)
	{
		case -1 : 
		{
			texture_plafond = loadTexture("textures/plafond1.jpg");
			texture_sol = loadTexture("textures/floor.jpg");
			texture_murs = loadTexture("textures/wall.jpg");

			//creation de l'étage
			Etage* cave = new Etage(80,15,80,texture_plafond,texture_sol,texture_murs,0);

			return cave;

		}
		break;

		case 0 : 
		{
			//chargement des textures
			int texture_pilier = loadTexture("textures/pilier1.jpg");
			int texture_guichet = loadTexture("textures/wall.jpg");
			texture_plafond = loadTexture("textures/plafond1.jpg");
			texture_sol = loadTexture("textures/carrelage1.jpg");
			texture_murs = loadTexture("textures/mur1.jpg");

			//creation de l'étage
			Etage* rez_de_chaussee = new Etage(80,15,80,texture_plafond,texture_sol,texture_murs,0);
			
			//utilisé pour définir les coordonnées des murs ci-après
			vector<Point> points;

			points.push_back(Point (70,0,30));
			points.push_back(Point (70,0,10));
			points.push_back(Point (80,0,10));
			Mur *guichet1 = new Mur(80,0,30,points, 3,texture_guichet);
			points.clear();

			points.push_back(Point (70,0,0));
			points.push_back(Point (70,0,-20));
			points.push_back(Point (80,0,-20));
			Mur *guichet2 = new Mur(80,0,0,points, 3,texture_guichet);
			points.clear();

			
			//ajout des élement de décor dans l'étage
			rez_de_chaussee->addElementDecor(new Pilier(20,0,-40,texture_pilier));
			rez_de_chaussee->addElementDecor(new Pilier(-20,0,-20,texture_pilier));
			rez_de_chaussee->addElementDecor(new Pilier(20,0,-20,texture_pilier));
			rez_de_chaussee->addElementDecor(new Pilier(-20,0,0,texture_pilier));
			rez_de_chaussee->addElementDecor(new Pilier(-20,0,0,texture_pilier));
			rez_de_chaussee->addElementDecor(new Pilier(20,0,0,texture_pilier));
			rez_de_chaussee->addElementDecor(new Pilier(-20,0,20,texture_pilier));
			rez_de_chaussee->addElementDecor(new Pilier(20,0,20,texture_pilier));
			rez_de_chaussee->addElementDecor(new Fountain(10.0, 3.0, 10.0));
			rez_de_chaussee->addElementDecor(guichet1);
			rez_de_chaussee->addElementDecor(guichet2);
			rez_de_chaussee->addElementDecor(new Escalier(70,0,80,70,-20,0));
			rez_de_chaussee->addElementDecor(new Escalier(37,0,80,70,20,0));

			return rez_de_chaussee;
		}

		break;

		case 1 :
		{
			//chargement des textures
			texture_plafond = loadTexture("textures/plafond1.jpg");
			texture_sol = loadTexture("textures/moquette.jpg");
			texture_murs = loadTexture("textures/mur1.jpg");
			int texture_murs_bureau = loadTexture("textures/mur1.jpg");

			//creation de l'étage
			Etage* etage1 = new Etage(80,15,80,texture_plafond,texture_sol,texture_murs,0);
			
			//utilisé pour définir les coordonnées des murs ci-après
			vector<Point> points;

			points.push_back(Point (10,0,40));
			points.push_back(Point (10,0,0));
			Mur *mur1Salle1 = new Mur(80,0,40,points, 15,texture_murs_bureau);
			points.clear();

			points.push_back(Point (10,0,-30));
			points.push_back(Point (80,0,-30));
			Mur *mur2Salle1 = new Mur(10,0,-7,points, 15,texture_murs_bureau);
			points.clear();

			points.push_back(Point (-10,0,40));
			points.push_back(Point (-10,0,0));
			Mur *mur1Salle2 = new Mur(-80,0,40,points, 15,texture_murs_bureau);
			points.clear();

			points.push_back(Point (-10,0,-30));
			points.push_back(Point (-80,0,-30));
			Mur *mur2Salle2 = new Mur(-10,0,-7,points, 15,texture_murs_bureau);
			points.clear();

			etage1->addElementDecor(mur1Salle1);
			etage1->addElementDecor(mur1Salle2);
			etage1->addElementDecor(mur2Salle1);
			etage1->addElementDecor(mur2Salle2);

			return etage1;

		} 
		break;

		case 2 : 
		{

		}
		break;

		case 3 : 
		{

		}
		break;

		case 4 : 
		{

		}
		break;

		default :
		{

		}
		break;
	}

}
	

	

EtageFactory::~EtageFactory()
{

}

