#ifndef ELEMENTINTERACTIF_H_INCLUDED
#define ELEMENTINTERACTIF_H_INCLUDED

#include "element.h"
class ElementInteractif : public Element {
    protected:
        Point *position;
    public:
        ElementInteractif(double, double, double);
        void setPosition(double, double, double);
        virtual void draw();
        ~ElementInteractif();
};

#endif //ELEMENTINTERACTIF_H_INCLUDED
