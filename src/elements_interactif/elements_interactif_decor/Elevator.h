#ifndef ELEVATOR_H_INCLUDED
#define ELEVATOR_H_INCLUDED

#include "../../elements/Element_Interactif_Decor.h"
#include <vector>
#include "../../elements_decor/Mur.h"
#include "Button.h"

using namespace std;

class Elevator : public ElementInteractifDecor {
	
	private :
		double lenght;
		double width;
		double height;
		vector<Mur*> walls;
		vector<Mur*> doors;
		vector<Button*> buttons;
		bool isClosed;
		int texture_porte;
		int texture_plancher;
		int texture_plafond;

	public:
		Elevator(double,double,double,double,double,double,int,int,int);
		~Elevator();
		void createElevatorShaft();
		void drawElevatorFloorAndCeiling();
		void createElevatorDoors();
		void open();
		void close();
		void draw();

		void interaction();
		vector<AABB3D> getHitboxes()const;
};


#endif // ELEVATOR_H_INCLUDED
