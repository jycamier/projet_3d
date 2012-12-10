#include "../utils/point.h"

class Element {
    protected:
        Point *position;
    public:
        Element();
        Element(double, double, double);
        void setPosition(double, double, double);
        ~Element();
};