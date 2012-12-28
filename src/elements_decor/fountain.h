#ifndef FOUNTAIN_H_INCLUDED
#define FOUNTAIN_H_INCLUDED
#include "../elements/element_decor.h"
#include "../elements_interactif/elements_inventory/water_cup.h"

class Fountain : public ElementDecor {
	private:
		int width;
	public:
		Fountain(double, double, double);
		WaterCup* provideWater();
		void draw();
		~Fountain();
};


#endif //FOUNTAIN_H_INCLUDED
