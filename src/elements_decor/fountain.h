#include "../elements/element_decor.h"

class Fountain : ElementDecor {
	public:
		Fountain(double, double, double);
		~Fountain();
		void draw();
};