#include "../elements/element_decor.h"

class Fountain : public ElementDecor {
	private:
		int width;
	public:
		Fountain(double, double, double);
		~Fountain();
		void draw();
};