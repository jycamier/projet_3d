#ifndef ELEMENTINVENTORY_H_INCLUDED
#define ELEMENTINVENTORY_H_INCLUDED

#include "Element_Interactif.h"

class ElementInventory : public ElementInteractif {
    public:
        ElementInventory(double,double,double);
        ~ElementInventory();
};

#endif // ELEMENTINVENTORY_H_INCLUDED