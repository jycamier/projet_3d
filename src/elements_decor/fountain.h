#include "../elements/element_decor.h"
#include "../elements_inventory/water_cup.h"

class Fountain : public ElementDecor {
	private:
		int width;
	public:
		Fountain(double, double, double);
		WaterCup* provideWater();
		void draw();
		~Fountain();
};