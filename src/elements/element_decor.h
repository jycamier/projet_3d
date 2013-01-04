#ifndef ELEMENTDECOR_H_INCLUDED
#define ELEMENTDECOR_H_INCLUDED

#include "element.h"
class ElementDecor : public Element {
    public:
        ElementDecor(double, double, double);
        void setPosition(double, double, double);
        virtual void draw();
        ~ElementDecor();

};

#endif //ELEMENTDECOR_H_INCLUDED
