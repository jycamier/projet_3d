#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include "sdlglutils.h"
#include "barril.h"
#include "caisse.h"
#include "etage.h"


// Taille de la fenêtre
#define LARGEUR 800
#define HAUTEUR 600
#define FRAMES_PER_SECOND 50


int main(int argc, char *argv[])
{
// Initialisation de SDL
	SDL_Init(SDL_INIT_VIDEO);
// Création de la surface d'affichage qui est en OpenGL
// (changez le titre si besoin)
	SDL_WM_SetCaption("Un bel entrepot",NULL);
	SDL_Surface* ecran = SDL_SetVideoMode(LARGEUR, HAUTEUR, 32, SDL_OPENGL);
// Initialisation de l'affichage OpenGL
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity( );
	gluPerspective (70, (double)LARGEUR/HAUTEUR, 1, 100);
	SDL_Flip(ecran);
	// Boucle d'évènements
	bool continuer = true;
	SDL_Event event;
	SDL_EnableKeyRepeat(10,10); // Activation de la répétition de touches
	int hauteur_vue = 10;

	Uint32 last_time = SDL_GetTicks(); // heure actuelle, derniere mise à jour
	Uint32 current_time;

	glEnable(GL_TEXTURE_2D);
	int sol = loadTexture("textures/carrelage1.jpg");
	int coco2 = loadTexture("textures/barril1.jpg");
	int mur1 = loadTexture("textures/mur1.jpg");
	int coco4 = loadTexture("textures/crate2.jpg");
	int ascenseur = loadTexture("textures/test.jpg");
	int sol2 = loadTexture("textures/sol_cave.jpg");
	int mur2 = loadTexture("textures/wall.jpg");
	int plafond = loadTexture("textures/plafond1.jpg");
	int pilier = loadTexture("textures/pilier1.jpg");

	int angle = 35;
	int pas = 1;

	int longueur_etage = 60;
	int largeur_etage = 60;
	int hauteur_etage = 20;

	double x;
	double z;

	while (continuer)
	{
			SDL_PollEvent(&event);
		// Selon le type d'evt, on choisi quoi faire
			switch(event.type)
			{
				case SDL_QUIT: // fin
				continuer = false;
				break;
				case SDL_KEYDOWN:
					switch( event.key.keysym.sym)
					{
					case SDLK_RIGHT:
						angle++;
						break;
					case SDLK_LEFT:
						angle--;
						break;
					case SDLK_UP:
						// x = x + pas * sin((angle * 2 * M_PI)/180) ;
						// z = z + pas * cos ((angle * 2 * M_PI)/180);
						hauteur_vue++;
						break;
					case SDLK_DOWN:
						// x = x - pas * sin((angle * 2 * M_PI)/180) ;
						// z = z - pas * cos ((angle * 2 * M_PI)/180);
						hauteur_vue--;
						break;
					}
		}

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
		
		gluLookAt(10,hauteur_vue,10,50,0,60,0,1,0);
		glRotated(angle,0,1,0);
		glTranslated(x,1,z);
	
			
		GLUquadricObj *quad1 = gluNewQuadric();

		Etage *rez_de_chaussee = new Etage(longueur_etage,hauteur_etage,largeur_etage,plafond,sol,mur1,0);
		rez_de_chaussee->draw(ascenseur);

		Etage *cave = new Etage(longueur_etage,-1,largeur_etage,plafond,sol2,mur2,-20);
		cave->draw(mur2);

		//piliers
		Barril * p1 = new Barril(-20,0,-40);
		p1->draw(quad1,pilier);
		Barril * p2 = new Barril(20,0,-40);
		p2->draw(quad1,pilier);
		Barril * p3 = new Barril(-20,0,-20);
		p3->draw(quad1,pilier);
		Barril * p4 = new Barril(20,0,-20);
		p4->draw(quad1,pilier);
		Barril * p5 = new Barril(-20,0,0);
		p5->draw(quad1,pilier);
		Barril * p6 = new Barril(20,0,0);
		p6->draw(quad1,pilier);		
		Barril * p7 = new Barril(-20,0,20);
		p7->draw(quad1,pilier);
		Barril * p8 = new Barril(20,0,20);
		p8->draw(quad1,pilier);		

	 int i = 0;
	 int a = 60;
	 int b = 0;
	 int c = 50;

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




		// Affichage (en double buffering)
		glFlush();
		SDL_GL_SwapBuffers();

	}


	// Fin du programme
	SDL_Quit();
	return 0;
}
