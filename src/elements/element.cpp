#include "element.h"

Element::Element() {	
}

Element::~Element() {	
}

void Element::UpdateHitbox(){
// méthode virtuel
}


double Element::calculerDistance(double a, double b){

	if (a < b){
		return b-a;
	}else if(b < a){
		return a-b;
	}

}
