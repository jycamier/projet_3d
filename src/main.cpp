#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include <vector>
#include "sdlglutils.h"
#include "etage.h"
#include "factory/Etage_Factory.h"


// Taille de la fenêtre
#define LARGEUR 800
#define HAUTEUR 600
#define FRAMES_PER_SECOND 50


int main(int argc, char *argv[])
{
// Initialisation de SDL
	SDL_Init(SDL_INIT_VIDEO);

// Création de la surface d'affichage qui est en OpenGL

	SDL_WM_SetCaption("La maison qui rend fou",NULL);
	SDL_Surface* ecran = SDL_SetVideoMode(LARGEUR, HAUTEUR, 32, SDL_OPENGL);

// Initialisation de l'affichage OpenGL
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity( );
	gluPerspective (70, (double)LARGEUR/HAUTEUR, 1, 200);
	SDL_Flip(ecran);

	bool continuer = true;
	SDL_Event event;
	SDL_EnableKeyRepeat(10,10); // Activation de la répétition de touches
	int hauteur_vue = 10;

	//variables pour le calcul des images par secondes
	Uint32 last_time = SDL_GetTicks(); // derniere mise à jour
	Uint32 current_time;//heure actuelle,

	glEnable(GL_TEXTURE_2D);

	// TESTS ELEMENTS


	// END

	//variables de déplacement de la caméra
	int angle = 35;
	int pas = 1;
	double x = 0;
	double z = 0;
	
	// paramètre de l'étage
	int longueur_etage = 80;
	int largeur_etage = 80;
	int hauteur_etage = 15;

	EtageFactory factory;

	Etage* rez_de_chaussee = factory.createEtage(1); 

	while (continuer)
	{
		SDL_PollEvent(&event);
		// Selon le type d'evt, on choisi quoi faire
		switch(event.type)
		{
			case SDL_QUIT: // fin
			continuer = false;
			break;
		}

		// Gestion du clavier
		// Récupération du keystates
		Uint8 *keystates = SDL_GetKeyState( NULL );

		// Actions liées
		if (keystates[SDLK_a]) 
		{
			rez_de_chaussee->openElevatorDoors();
		}
		if (keystates[SDLK_e]) 
		{
			rez_de_chaussee->closeElevatorDoors();
		}

		if (keystates[SDLK_RIGHT]) {angle = angle + 3;}
		if (keystates[SDLK_LEFT]) {angle = angle - 3;}
		if (keystates[SDLK_UP]) 
		{
			x = x - pas * sin((angle * 2 * M_PI)/360) ;
			z = z + pas * cos ((angle * 2 * M_PI)/360);
		}
		if (keystates[SDLK_DOWN]) 
		{
			x = x + pas * sin((angle * 2 * M_PI)/360) ;
			z = z - pas * cos ((angle * 2 * M_PI)/360);
		}

		//gestion images par secondes
		current_time = SDL_GetTicks();
		while (current_time - last_time < (1000/FRAMES_PER_SECOND)) {
			// On se met en pause le temps voulu
			SDL_Delay(1000/FRAMES_PER_SECOND - (current_time - last_time));
			current_time = SDL_GetTicks();
		}
		
		last_time = SDL_GetTicks();

		glEnable(GL_DEPTH_TEST);
		glClearColor(0.6, 0.6, 0.6, 1);
		// On efface la fenêtre
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		
		glRotated(angle,0,1,0);
		gluLookAt(x,2,z,x,2,z+1,0,1,0);

		//repère
		///////////////////////////////////////////////////////////////
		//axe des z en jaune
		glBegin(GL_QUADS);
		glColor3ub(255,255,0);
		glVertex3d(10,0.5,0);
		glVertex3d(12,0.5,0);
		glVertex3d(12,0.5,20);
		glVertex3d(10,0.5,20);
		
		glEnd();

		//axe des x en violet
		glBegin(GL_QUADS);
		glColor3ub(255,0,255);
		glVertex3d(0,0.5,0);
		glVertex3d(10,0.5,0);
		glVertex3d(10,0.5,2);
		glVertex3d(0,0.5,2);
		glEnd();
		///////////////////////////////////////////////////////////////

	
		rez_de_chaussee->draw();

		// Affichage (en double buffering)
		glFlush();
		SDL_GL_SwapBuffers();

	}
	// Fin du programme
	SDL_Quit();
	return 0;
}
