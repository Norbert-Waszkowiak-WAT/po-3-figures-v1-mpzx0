#include "quadrilateral.h"

Quadrilateral::Quadrilateral(Point a, Point b, Point c, Point d) : a(a), b(b), c(c), d(d) {};
Quadrilateral::Quadrilateral(const Quadrilateral &other) : a(other.a), b(other.b), c(other.c), d(other.d) {};

bool Quadrilateral::equals(const Quadrilateral &other)
{
    return a.equals(other.a) && b.equals(other.b) && c.equals(other.c) && d.equals(other.d);
}


void Quadrilateral::flip()
{
    a.flip();
    b.flip();
    c.flip();
    d.flip();
}

void Quadrilateral::move(double x, double y)
{
    a.move(x, y);
    b.move(x, y);
    c.move(x, y);
    d.move(x, y);
}

double Quadrilateral::getSurface()
{
    double output = 0;

    double all_x[] = { a.getX(), b.getX(), c.getX(), d.getX() };
    double all_y[] = { a.getY(), b.getY(), c.getY(), d.getY() };

    for(int i = 0; i < 4; i++)
    {
        double ip1 = i+1 >= 4 ? all_x[0] : all_x[i+1];
        double im1 = i-1 <= 0 ? all_x[3] : all_x[i-1];

        output += (all_y[i] * (im1 - ip1));
    }

    output = (output > 0) ? output : -output;
    output /= 2;
    return output;
}

std::string Quadrilateral::toString()
{
    return "Quadrilateral(" + a.toString() + ", " + b.toString() + ", " + c.toString() + ", " + d.toString() + ")";
}