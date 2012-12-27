#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include <vector>
#include "sdlglutils.h"
#include "caisse.h"
#include "etage.h"
#include "Personnage.h"
#include "elements_decor/Pilier.h"
#include "elements_decor/fountain.h"
#include "elements_decor/Mur.h"
#include "factory/Etage_Factory.h"
#include "elements_decor/Escalier.h"


// Taille de la fenêtre
#define LARGEUR 800
#define HAUTEUR 600
#define FRAMES_PER_SECOND 50

int main(int argc, char *argv[]) {
// Initialisation de SDL
	SDL_Init (SDL_INIT_VIDEO);

// Création de la surface d'affichage qui est en OpenGL

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

	glEnable (GL_TEXTURE_2D);

	
	//chargement des textures
	int ascenseur = loadTexture("textures/test.jpg");
	int mur2 = loadTexture("textures/wall.jpg");
	int pilier = loadTexture("textures/pilier1.jpg");
	int sol = loadTexture("textures/carrelage1.jpg");


	// TESTS ELEMENTS
	//test fontaine
	Fountain *fountain = new Fountain(10.0, 3.0, 10.0);

	Escalier *escalierDescendant = new Escalier(70,0,80,70,-20,0);
	Escalier *escalierMontant = new Escalier(37,0,80,70,20,0);

	//test murs
	vector<Point> points;

	points.push_back(Point (70,0,30));
	points.push_back(Point (70,0,10));
	points.push_back(Point (80,0,10));
	Mur *guichet1 = new Mur(80,0,30,points, 3,mur2);
	points.clear();

	points.push_back(Point (70,0,0));
	points.push_back(Point (70,0,-20));
	points.push_back(Point (80,0,-20));
	Mur *guichet2 = new Mur(80,0,0,points, 3,mur2);
	points.clear();
	// END

	//variables de déplacement de la caméra
	int angle = 35;
	int pas = 1;
	double x = 0;
	double z = 0;

	//Initialisation de la classe Personnage incarnant notre Personnage de jeu
	Personnage* personnage_jeu = new Personnage(0, 0, 0, 35);

	// paramètre de l'étage
	int longueur_etage = 80;
	int largeur_etage = 80;
	int hauteur_etage = 15;

	EtageFactory factory;

	Etage* rez_de_chaussee = factory.createEtage(); 

	Pilier * p1 = new Pilier(-20,0,-40,pilier);
	Pilier * p2 = new Pilier(20,0,-40,pilier);
	Pilier * p3 = new Pilier(-20,0,-20,pilier);
	Pilier * p4 = new Pilier(20,0,-20,pilier);
	Pilier * p5 = new Pilier(-20,0,0,pilier);
	Pilier * p6 = new Pilier(20,0,0,pilier);
	Pilier * p7 = new Pilier(-20,0,20,pilier);
	Pilier * p8 = new Pilier(20,0,20,pilier);

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


	int i = 0;
	bool col = false;

	while (continuer) {
		SDL_PollEvent(&event);
		// Selon le type d'evt, on choisi quoi faire
		switch (event.type) {
		case SDL_QUIT: // fin
			continuer = false;
			break;
		}

		/**
		 * TEST Collisions
		 */
		i = 0;
		col = false;
		while (col == false && i < rez_de_chaussee->getLesCaisses().size()) {
			col = rez_de_chaussee->getLesCaisses().at(i)->Collision(personnage_jeu->getX(), personnage_jeu->getY(),
					personnage_jeu->getZ()+1);
			i++;
		}

		// Gestion du clavier
		// Récupération du keystates
		Uint8 *keystates = SDL_GetKeyState(NULL);

		// Actions liées
		if (keystates[SDLK_RIGHT]) {
			personnage_jeu->tournerDroite();
		}
		if (keystates[SDLK_LEFT]) {
			personnage_jeu->tournerGauche();
		}
		if (keystates[SDLK_UP]) {
			if(!col){
				personnage_jeu->avancer();
			}
		}
		if (keystates[SDLK_DOWN]) {
			personnage_jeu->reculer();
		}

		//gestion images par secondes
		current_time = SDL_GetTicks();
		while (current_time - last_time < (1000 / FRAMES_PER_SECOND)) {
			// On se met en pause le temps voulu
			SDL_Delay(1000 / FRAMES_PER_SECOND - (current_time - last_time));
			current_time = SDL_GetTicks();
		}
		
		last_time = SDL_GetTicks();

		glEnable (GL_DEPTH_TEST);
		glClearColor(0.6, 0.6, 0.6, 1);
		// On efface la fenêtre
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glMatrixMode (GL_MODELVIEW);
		glLoadIdentity();

		//Mise à jour de la camera du personnage
		personnage_jeu->updateCamera();

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

		cave->draw(mur2);

		//piliers
		p1->draw(quad1, pilier);
		p2->draw(quad1, pilier);
		p3->draw(quad1, pilier);
		p4->draw(quad1, pilier);
		p5->draw(quad1, pilier);
		p6->draw(quad1, pilier);
		p7->draw(quad1, pilier);
		p8->draw(quad1, pilier);

		int i = 0;
		int a = 70;
		int b = 0;
		int c = 70;

		glBindTexture(GL_TEXTURE_2D, sol);
		glBegin(GL_QUADS);		
		glColor3ub(223,223,223);

		glVertex3d(80,0,80);
		glVertex3d(70,0,80);
		glVertex3d(70,0,55);
		glVertex3d(80,0,55);
					
		glEnd() ;

		glBegin(GL_QUADS);		
		glColor3ub(223,223,223);

		glVertex3d(70,0,70);
		glVertex3d(27,0,70);
		glVertex3d(27,0,55);
		glVertex3d(70,0,55);
					
		glEnd() ;

		glBegin(GL_QUADS);		
		glColor3ub(223,223,223);

		glVertex3d(37,0,80);
		glVertex3d(27,0,80);
		glVertex3d(27,0,70);
		glVertex3d(37,0,70);
					
		glEnd() ;
		
		
		fountain->draw();
		murTest->draw();
		murTest2->draw();
		murTest3->draw();
		murTest4->draw();
		murTest5->draw();
		murTest6->draw();
		

		while (b > -20)
		{
			glBegin(GL_QUADS);		
			glColor3ub(168,163,165);

			glVertex3d(a,b,c);
			glVertex3d(a,b,c+10);
			glVertex3d(a,b-1,c+10);
			glVertex3d(a,b-1,c);
					
			glEnd() ;

			glBegin(GL_QUADS);		
			glColor3ub(255,0,0);

			glVertex3d(a,b-1,c);
			glVertex3d(a,b-1,c+10);
			glVertex3d(a-2,b-1,c+10);
			glVertex3d(a-2,b-1,c);

			glEnd() ;
			i++;
			b = b - 1;
			a = a - 2;
		}

		i = 0;
		a = 37;
		b = 0;
		c = 80;

		while (b < 20) {
			glBegin(GL_QUADS);
			glColor3ub(168, 163, 165);

			glVertex3d(a, b, c);
			glVertex3d(a, b, c - 10);
			glVertex3d(a, b + 1, c - 10);
			glVertex3d(a, b + 1, c);

			glEnd();

			glBegin(GL_QUADS);
			glColor3ub(255, 0, 0);

			glVertex3d(a, b + 1, c);
			glVertex3d(a, b + 1, c - 10);
			glVertex3d(a + 2, b + 1, c - 10);
			glVertex3d(a + 2, b + 1, c);

			glEnd();
			i++;

			b = b + 1;
			a = a + 2;
		}


		// Affichage (en double buffering)
		glFlush();
		SDL_GL_SwapBuffers();

	}
	// Fin du programme
	SDL_Quit();
	return 0;
}
