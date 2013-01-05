#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
 
#include <string>
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "sdlglutils.h"

using namespace std;

class Menu
{
   private:
   	int texture;

    public:
        Menu();
        ~Menu();
        void draw();
        void drawBackground();
        void drawButtons();
 
 
};
 
#endif // MENU_H_INCLUDED