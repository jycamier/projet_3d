#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include <vector>
#include <cstdlib>
#include "sdlglutils.h"
#include "caisse.h"
#include "etage.h"
#include "elements_decor/Pilier.h"
#include "elements_decor/fountain.h"
#include "elements_decor/Mur.h"
#include "factory/Etage_Factory.h"
#include "elements_decor/Escalier.h"
#include "freeflycamera.h"

// Taille de la fenêtre
#define LARGEUR 800
#define HAUTEUR 600
#define FRAMES_PER_SECOND 50

FreeFlyCamera * camera;

void stop() {
	delete camera;
	SDL_Quit();
}

int main(int argc, char *argv[]) {

// Initialisation de SDL
	SDL_Init (SDL_INIT_VIDEO);

// Création de la surface d'affichage qui est en OpenGL

	atexit(stop);

	SDL_WM_SetCaption("Un bel entrepot", NULL);
	SDL_Surface* ecran = SDL_SetVideoMode(LARGEUR, HAUTEUR, 32, SDL_OPENGL);

// Initialisation de l'affichage OpenGL
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(70, (double) LARGEUR / HAUTEUR, 1, 200);
	SDL_Flip(ecran);

	bool continuer = true;
	SDL_Event event;
	SDL_EnableKeyRepeat(10, 10); // Activation de la répétition de touches
	int hauteur_vue = 10;

	//variables pour le calcul des images par secondes
	Uint32 last_time = SDL_GetTicks(); // derniere mise à jour
	Uint32 current_time; //heure actuelle,
	Uint32 elapsed_time; //heure actuelle,

	glEnable (GL_TEXTURE_2D);

	/**
	 * chargement des textures
	 */
	int ascenseur = loadTexture("textures/test.jpg");
	int mur2 = loadTexture("textures/wall.jpg");
	int pilier = loadTexture("textures/pilier1.jpg");
	int sol = loadTexture("textures/carrelage1.jpg");


	// TESTS ELEMENTS
	//test fontaine
	Fountain *fountain = new Fountain(10.0, 3.0, 10.0);

	Escalier *escalierDescendant = new Escalier(70, 0, 80, 70, -20, 0);
	Escalier *escalierMontant = new Escalier(37, 0, 80, 70, 20, 0);

	//test murs
	vector<Point> points;

	points.push_back(Point(70, 0, 30));
	points.push_back(Point(70, 0, 10));
	points.push_back(Point(80, 0, 10));
	Mur *guichet1 = new Mur(80, 0, 30, points, 3, mur2);
	points.clear();

	points.push_back(Point(70, 0, 0));
	points.push_back(Point(70, 0, -20));
	points.push_back(Point(80, 0, -20));
	Mur *guichet2 = new Mur(80, 0, 0, points, 3, mur2);
	points.clear();
	// END


	//Initialisation de la classe Personnage incarnant notre Personnage de jeu
	camera = new FreeFlyCamera(Vector3D(0, 4, 0));


	EtageFactory factory;
	Etage* rez_de_chaussee = factory.createEtage();

	/**
	 * Set de l'étage courrant dans la camera
	 */

	camera->setCurrentStare(rez_de_chaussee);

	Pilier * p1 = new Pilier(-20, 0, -40, pilier);
	Pilier * p2 = new Pilier(20, 0, -40, pilier);
	Pilier * p3 = new Pilier(-20, 0, -20, pilier);
	Pilier * p4 = new Pilier(20, 0, -20, pilier);
	Pilier * p5 = new Pilier(-20, 0, 0, pilier);
	Pilier * p6 = new Pilier(20, 0, 0, pilier);
	Pilier * p7 = new Pilier(-20, 0, 20, pilier);
	Pilier * p8 = new Pilier(20, 0, 20, pilier);

	rez_de_chaussee->addElementDecor(p1);
	rez_de_chaussee->addElementDecor(p2);
	rez_de_chaussee->addElementDecor(p3);
	rez_de_chaussee->addElementDecor(p4);
	rez_de_chaussee->addElementDecor(p5);
	rez_de_chaussee->addElementDecor(p6);
	rez_de_chaussee->addElementDecor(p7);
	rez_de_chaussee->addElementDecor(p8);
	rez_de_chaussee->addElementDecor(fountain);
	rez_de_chaussee->addElementDecor(guichet1);
	rez_de_chaussee->addElementDecor(guichet2);
	rez_de_chaussee->addElementDecor(escalierDescendant);
	rez_de_chaussee->addElementDecor(escalierMontant);
	//TEST
	rez_de_chaussee->AjouterCaisse(5, 0, 5, 5);

	int i = 0;
	bool col = false;

	while (continuer) {
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				exit(0);
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym) {
				case SDLK_p:
					takeScreenshot("test.bmp");
					break;
				case SDLK_ESCAPE:
					exit(0);
					break;
				default: //on a utilisé la touche P et la touche ECHAP, le reste (en keydown) est donné à la caméra
					camera->OnKeyboard(event.key);
				}
				break;
			case SDL_KEYUP: //on n'utilise pas de keyup, on donne donc tout à la caméra
				camera->OnKeyboard(event.key);
				break;
			case SDL_MOUSEMOTION: //la souris est bougée, ça n'intéresse que la caméra
				camera->OnMouseMotion(event.motion);
				break;
			case SDL_MOUSEBUTTONUP:
			case SDL_MOUSEBUTTONDOWN: //tous les évenements boutons (up ou down) sont donnés à la caméra
				camera->OnMouseButton(event.button);
				break;
			}
		}


		//gestion images par secondes
		current_time = SDL_GetTicks();
		elapsed_time = current_time - last_time;
		while (current_time - last_time < (1000 / FRAMES_PER_SECOND)) {
			// On se met en pause le temps voulu
			SDL_Delay(1000 / FRAMES_PER_SECOND - (current_time - last_time));
			current_time = SDL_GetTicks();
			elapsed_time = current_time - last_time;
		}

		last_time = SDL_GetTicks();

		//Update de la position dela camera
		camera->animate(elapsed_time);

		glEnable (GL_DEPTH_TEST);
		glClearColor(0.6, 0.6, 0.6, 1);
		// On efface la fenêtre
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glMatrixMode (GL_MODELVIEW);
		glLoadIdentity();

		//remplace un appel manuel à gluLookAt
		camera->look();

		//repère
		///////////////////////////////////////////////////////////////
		//axe des z en jaune
		glBegin (GL_QUADS);
		glColor3ub(255, 255, 0);
		glVertex3d(10, 0.5, 0);
		glVertex3d(12, 0.5, 0);
		glVertex3d(12, 0.5, 20);
		glVertex3d(10, 0.5, 20);

		glEnd();

		//axe des x en violet
		glBegin(GL_QUADS);
		glColor3ub(255, 0, 255);
		glVertex3d(0, 0.5, 0);
		glVertex3d(10, 0.5, 0);
		glVertex3d(10, 0.5, 2);
		glVertex3d(0, 0.5, 2);
		glEnd();


		///////////////////////////////////////////////////////////////

		rez_de_chaussee->draw(ascenseur);

		// Affichage (en double buffering)
		glFlush();
		SDL_GL_SwapBuffers();

	}

	return 0;
}
