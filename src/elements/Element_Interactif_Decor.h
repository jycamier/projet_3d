#ifndef ELEMENTINTERACTIFDECOR_H_INCLUDED
#define ELEMENTINTERACTIFDECOR_H_INCLUDED

#include "Element_Interactif.h"

class ElementInteractifDecor : public ElementInteractif {
    public:
        ElementInteractifDecor(double,double,double);
        virtual void draw();
        ~ElementInteractifDecor();
};

#endif // ELEMENTINTERACTIFDECOR_H_INCLUDED