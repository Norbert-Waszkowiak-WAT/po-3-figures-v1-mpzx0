#ifndef GROUP_H
#define GROUP_H

#include "line.h"
#include "triangle.h"
#include "quadrilateral.h"

#include <vector>

class Group
{
private:
    std::vector<Line> lines;
    std::vector<Triangle> triangles;
    std::vector<Quadrilateral> quadrilaterals;

public:
    Group();
    Group(const Group &other);

    bool equals(const Group &other);

    void remove(const Line &t);
    void remove(const Triangle &t);
    void remove(const Quadrilateral &t);

    void add(const Line &t);
    void add(const Triangle &t);
    void add(const Quadrilateral &t);

    double getSurface();

    void flip();
    void move(double x, double y);
    
    std::string toString();
};

#endif