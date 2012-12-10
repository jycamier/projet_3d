#include "element.h"
class ElementDecor : public Element {
    protected:
        Point *position;
    public:
        ElementDecor(double, double, double);
        void setPosition(double, double, double);
        ~ElementDecor();
};