#ifndef VECTOR3D_H
#define VECTOR3D_H

/* Impl�mentation intuitive d'une classe Vector3D pour les lecteurs du cours
d'OpenGL,d�butants en C++. Il est �vident qu'une approche template est �
privil�gier pour favoriser la r�utilisabilit� et l'inlinisme. */

class Vector3D
{
public:
    double X;
    double Y;
    double Z;

    Vector3D();
    Vector3D(double x,double y,double z);
    Vector3D(const Vector3D & v);
    Vector3D(const Vector3D & from,const Vector3D & to);

    Vector3D & operator= (const Vector3D & v);

    Vector3D & operator+= (const Vector3D & v);
    Vector3D operator+ (const Vector3D & v) const;

    Vector3D & operator-= (const Vector3D & v);
    Vector3D operator- (const Vector3D & v) const;

    Vector3D & operator*= (const double a);
    Vector3D operator* (const double a)const;
    friend Vector3D operator* (const double a,const Vector3D & v);

    Vector3D & operator/= (const double a);
    Vector3D operator/ (const double a)const;

    Vector3D crossProduct(const Vector3D & v)const;
    double length()const;
    Vector3D & normalize();


};

#endif //VECTOR3D_H
