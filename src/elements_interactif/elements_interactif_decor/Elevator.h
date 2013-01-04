#ifndef ELEVATOR_H_INCLUDED
#define ELEVATOR_H_INCLUDED

#include "../../elements/Element_Interactif_Decor.h"
#include <vector>
#include "../../elements_decor/Mur.h"
#include "Button.h"
#include "../../sdlglutils.h"

using namespace std;

class Elevator: public ElementInteractifDecor {

private:

	double lenght;
	double width;
	double height;
	vector<Mur*> walls;
	vector<Mur*> doors;
	vector<Button*> buttons;
	bool isClosed;

	//Textures bouton ascensseur
	int texture_bouton_1;
	int texture_bouton_2;
	int texture_bouton_3;
	int texture_bouton_4;
	int texture_bouton_5;
	int texture_bouton_6;

	void loadTextures();

public:
	Elevator(double, double, double, double, double, double);
	~Elevator();
	void createElevatorShaft();
	void createElevatorDoors();
	void open();
	void close();
	void draw();

	void interaction();
	vector<AABB3D> getHitboxes() const;

	vector<Button*> getButtons() const {
		return buttons;
	}
};

#endif // ELEVATOR_H_INCLUDED
