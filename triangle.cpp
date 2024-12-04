#include "triangle.h"

Triangle::Triangle(Point a, Point b, Point c) : a(a), b(b), c(c) {};
Triangle::Triangle(const Triangle &other) : a(other.a), b(other.b), c(other.c) {};

bool Triangle::equals(const Triangle &other)
{
    return a.equals(other.a) && b.equals(other.b) && c.equals(other.c);
}


void Triangle::flip()
{
    a.flip();
    b.flip();
    c.flip();
}

void Triangle::move(double x, double y)
{
    a.move(x, y);
    b.move(x, y);
    c.move(x, y);
}

double Triangle::getLength(Point &a, Point &b)
{
    double odca = a.getX() - b.getX();
    double odcb = a.getY() - b.getY();

    return sqrt(odca*odca+odcb*odcb);
}

double Triangle::getSurface()
{
    double odca = getLength(a, b);
    double odcb = getLength(b, c);
    double odcc = getLength(a, c);
    double p = 0.5 * (odca+odcb+odcc);
    return sqrt(p*(p-odca)*(p-odcb)*(p-odcc));
}

std::string Triangle::toString()
{
    return "Triangle(" + a.toString() + ", " + b.toString() + ", " + c.toString() + ")";
}