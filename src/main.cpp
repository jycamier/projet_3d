#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include <vector>
#include <cstdlib>
#include "sdlglutils.h"
#include "etage.h"
#include "factory/Etage_Factory.h"
#include "elements_decor/Escalier.h"
#include "freeflycamera.h"
#include "elements_interactif/elements_interactif_decor/Button.h"



// Taille de la fenêtre
#define LARGEUR 800
#define HAUTEUR 600
#define FRAMES_PER_SECOND 50

FreeFlyCamera * camera;

void stop() {
	delete camera;
	SDL_Quit();
}

bool Collision(float x, float y, float z, AABB3D box) {
	if (x >= box.x && x < box.x + box.w && y >= box.y && y < box.y + box.h
			&& z >= box.z && z < box.z + box.d)
		return true;
	else
		return false;
}

bool CollisionX(float x, AABB3D box) {
	if (x >= box.x && x < box.x + box.w)
		return true;
	else
		return false;
}

bool CollisionZ(float z, AABB3D box) {
	if (z >= box.z && z < box.z + box.d)
		return true;
	else
		return false;
}

int main(int argc, char *argv[]) {

// Initialisation de SDL
	SDL_Init (SDL_INIT_VIDEO);

// Création de la surface d'affichage qui est en OpenGL

	atexit(stop);
	SDL_WM_SetCaption("La maison qui rend fou", NULL);

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

	Uint32 next_interaction = 0; // variable enregistrant le moment du dernier tir
	Uint32 now; // heure actuelle

	glEnable (GL_TEXTURE_2D);

	//Initialisation de la classe Personnage incarnant notre Personnage de jeu
	camera = new FreeFlyCamera(Vector3D(0, 8, 0));

	EtageFactory factory;
	Etage* rez_de_chaussee = factory.createEtage(1);

	/**
	 * Set de l'étage courrant dans la camera
	 */
	camera->setCurrentStare(rez_de_chaussee);

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
				case SDLK_t:
					now = SDL_GetTicks();
					if (next_interaction <= now) {
						next_interaction = now + 500;
						rez_de_chaussee->decorInteractif[2]->interaction();
						rez_de_chaussee->decorInteractif[3]->interaction();
					}			
					break;
				case SDLK_y:
					rez_de_chaussee->decorInteractif[3]->interaction();
					break;
				case SDLK_u:
					rez_de_chaussee->decorInteractif[4]->interaction();
					break;
				case SDLK_ESCAPE:
					exit(0);
					break;
				case SDLK_a:
					rez_de_chaussee->openElevatorDoors();
					break;
				case SDLK_e:
					rez_de_chaussee->closeElevatorDoors();
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

		/**
		 * GESTION DES COLLISIONS
		 */
		vector<AABB3D> hitb;
		bool CollisionTab[8] = {false,false};

		for (int i = 0; i < rez_de_chaussee->getElements().size(); i++) {
			hitb = rez_de_chaussee->getElements().at(i)->getHitboxes();

			for (int j = 0; j < hitb.size(); j++) {

				if (Collision(camera->getTarget().X, camera->getTarget().Y,
						camera->getTarget().Z, hitb.at(j))) {
					//Avancer
					CollisionTab[0] = CollisionX(camera->getTarget().X, hitb.at(j));
					CollisionTab[1] = CollisionZ(camera->getTarget().Z, hitb.at(j));
					//reculer
					CollisionTab[2] = CollisionX(camera->getPosition().X-camera->getForward().X, hitb.at(j));
					CollisionTab[3] = CollisionZ(camera->getPosition().Z-camera->getForward().Z, hitb.at(j));
					//aller à gauche
					CollisionTab[4] = CollisionX(camera->getPosition().X+camera->getLeft().X, hitb.at(j)) && CollisionTab[0];
					CollisionTab[5] = CollisionZ(camera->getPosition().Z+camera->getLeft().Z, hitb.at(j)) && CollisionTab[1];
					//aller à droite
					CollisionTab[6] = CollisionX(camera->getPosition().X-camera->getLeft().X, hitb.at(j))&& CollisionTab[0];
					CollisionTab[7] = CollisionZ(camera->getPosition().Z-camera->getLeft().Z, hitb.at(j))&& CollisionTab[1];
				}

			}

		}
		camera->setCollisionTab(CollisionTab);


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

		glBegin (GL_LINES);
		glColor3ub(255, 255, 0);
		glVertex3d(0, 0.5, 0);
		glVertex3d(80, 0.5, 0);

		glEnd();

		glBegin(GL_LINES);
		glColor3ub(255, 0, 255);
		glVertex3d(0, 0.5, 0);
		glVertex3d(0, 0.5, 80);

		glEnd();

		//axe des x en violet

		///////////////////////////////////////////////////////////////

		rez_de_chaussee->draw();

		// Affichage (en double buffering)
		glFlush();
		SDL_GL_SwapBuffers();

	}

	return 0;
}
