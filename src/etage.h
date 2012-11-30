#ifndef ETAGE_H_INCLUDED
#define ETAGE_H_INCLUDED

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

class Etage {

    private :

        int longueur_etage;
        int hauteur_etage;
        int largeur_etage;
        int texture_plafond;
        int texture_murs;
        int texture_sol;       

    public :
        Etage () ; // Non implémenté donc inutilisable
        Etage (const Etage &); // Constructeur de copie, non implémenté donc interdit
        Etage (int, int, int, int, int, int);
        void draw(int);
        ~Etage(); // Destructeur
};

#endif // ETAGE_H_INCLUDED