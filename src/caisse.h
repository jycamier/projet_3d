#ifndef CAISSE_H_INCLUDED
#define CAISSE_H_INCLUDED

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

struct AABB3D
{
  float x,y,z;
  float w,h,d;
};

class Caisse {
    protected :
        double x;
        double y;
        double z;
        int height;

        AABB3D hitbox;
        void UpdateHitbox();

    public :
        Caisse () ; // Non implémenté donc inutilisable
        Caisse (const Caisse &); // Constructeur de copie, non implémenté donc interdit
        Caisse (double, double, double,int);
        ~Caisse(); // Destructeur
        void draw(GLUquadricObj *);
        void changeTexture(int);
        void changeHeight(int);


        bool Collision(float x,float y,float z);

};

#endif // CAISSE_H_INCLUDED
