#ifndef WATERCUP_H_INCLUDED
#define WATERCUP_H_INCLUDED

#include "../../elements/element_inventory.h"

class WaterCup : public ElementInventory {
	public:
		WaterCup();
		WaterCup(double,double,double);
		~WaterCup();
		void draw();
};


#endif // WATERCUP_H_INCLUDED