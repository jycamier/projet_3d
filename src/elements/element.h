class Element {
    private:
        double x;
        double y;
        double z;
    public:
        Element();
        Element(double, double, double);
        void setPosition(double, double, double);
        ~Element();
};