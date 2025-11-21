#include "Point3D.h"
#include <cmath>

Point3D::Point3D() : x(0), y(0), z(0) {}

Point3D::Point3D(double x, double y, double z) : x(x), y(y), z(z) {}

double Point3D::getX() const { return x; }
double Point3D::getY() const { return y; }
double Point3D::getZ() const { return z; }

void Point3D::setX(double x) { this->x = x; }
void Point3D::setY(double y) { this->y = y; }
void Point3D::setZ(double z) { this->z = z; }

double Point3D::distanceTo(const Point3D &other) const
{
    return std::sqrt(
        (x - other.x) * (x - other.x) +
        (y - other.y) * (y - other.y) +
        (z - other.z) * (z - other.z));
}

void Point3D::translate(double dx, double dy, double dz)
{
    x += dx;
    y += dy;
    z += dz;
}

Point3D Point3D::operator+(const Point3D &other) const
{
    return Point3D(x + other.x, y + other.y, z + other.z);
}

Point3D Point3D::operator-(const Point3D &other) const
{
    return Point3D(x - other.x, y - other.y, z - other.z);
}

bool Point3D::operator==(const Point3D &other) const
{
    return x == other.x && y == other.y && z == other.z;
}

bool Point3D::operator!=(const Point3D &other) const
{
    return !(*this == other);
}

std::ostream &operator<<(std::ostream &os, const Point3D &point)
{
    os << "(" << point.x << ", " << point.y << ", " << point.z << ")";
    return os;
}
