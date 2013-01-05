#include "Menu.h"
 
using namespace std;

Menu::Menu()
{
    this->texture = loadTexture("textures/fond.jpg");
}
 
Menu::~Menu()
{
}
 
void Menu::draw()
{
 // En 2D
    // glLoadIdentity();
    // glMatrixMode(GL_PROJECTION);
 
    // Definition de la fenetre
    // gluOrtho2D(0.0, (GLdouble)800, 0.0, (GLdouble)600);
 
    // Desactivation du test de prophondeur
    // glDisable(GL_DEPTH_TEST);
 
    // Vidage de l'image
    // glClear(GL_COLOR_BUFFER_BIT);
 
    // Dessin de fond du menu
    this->drawBackground();
 
    // Dessin des boutons
    this->drawButtons();
 
    // Affichage du dessin
    // glFlush();
    // SDL_GL_SwapBuffers();
}

void Menu::drawButtons()
{
}

void Menu::drawBackground()
{
	glBindTexture(GL_TEXTURE_2D,this->texture);
	glColor3ub(0,0,255);
    glBegin(GL_QUADS);
        // glTexCoord2d(0, 0); glVertex2f(0, 600);
        // glTexCoord2d(0, 1); glVertex2f(0, 0);
        // glTexCoord2d(1, 1); glVertex2f(800, 0);
        // glTexCoord2d(1, 0); glVertex2f(800, 600);
    glEnd();	
}