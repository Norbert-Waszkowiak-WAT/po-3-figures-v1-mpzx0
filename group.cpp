#include "group.h"
#include "line.h"

Group::Group() {};
Group::Group(const Group &other) : lines(other.lines), triangles(other.triangles), quadrilaterals(other.quadrilaterals) {};

bool Group::equals(const Group &other)
{
    if(lines.size() != other.lines.size() || triangles.size() != other.triangles.size() || quadrilaterals.size() != other.quadrilaterals.size())
        return false;

    for(size_t index = 0; index < lines.size(); index++)
    {
        if(!lines[index].equals(other.lines[index]))
            return false;
    }
    for(size_t index = 0; index < triangles.size(); index++)
    {
        if(!triangles[index].equals(other.triangles[index]))
            return false;
    }
    for(size_t index = 0; index < quadrilaterals.size(); index++)
    {
        if(!quadrilaterals[index].equals(other.quadrilaterals[index]))
            return false;
    }

    return true;
}

void Group::remove(const Line &t)
{
    for(size_t index = 0; index < lines.size(); index++)
    {
        if(lines[index].equals(t))
        {
            lines.erase(lines.begin() + index);
        }
    }
}
void Group::remove(const Triangle &t)
{
    for(size_t index = 0; index < triangles.size(); index++)
    {
        if(triangles[index].equals(t))
        {
            triangles.erase(triangles.begin() + index);
        }
    }
}
void Group::remove(const Quadrilateral &t)
{
    for(size_t index = 0; index < quadrilaterals.size(); index++)
    {
        if(quadrilaterals[index].equals(t))
        {
            quadrilaterals.erase(quadrilaterals.begin() + index);
        }
    }
}

void Group::add(const Line &t)
{
    lines.push_back(t);
}
void Group::add(const Triangle &t)
{
    triangles.push_back(t);
}
void Group::add(const Quadrilateral &t)
{
    quadrilaterals.push_back(t);
}

double Group::getSurface()
{
    double surface = 0;

    for(size_t index = 0; index < triangles.size(); index++)
        surface += triangles[index].getSurface();
    for(size_t index = 0; index < quadrilaterals.size(); index++)
        surface += quadrilaterals[index].getSurface();

    return surface;
}

void Group::flip()
{
    for(Line &line : lines)
        line.flip();

    for(Triangle &triangle : triangles)
        triangle.flip();

    for(Quadrilateral &quadrilateral : quadrilaterals)
        quadrilateral.flip();
}
void Group::move(double x, double y)
{
    for(Line &line : lines)
        line.move(x, y);

    for(Triangle &triangle : triangles)
        triangle.move(x, y);

    for(Quadrilateral &quadrilateral : quadrilaterals)
        quadrilateral.move(x, y);
}

std::string Group::toString()
{
    std::string output = "Group(";

    for(Line &line : lines)
        output += (line.toString() + ", ");

    return output + ")";
}