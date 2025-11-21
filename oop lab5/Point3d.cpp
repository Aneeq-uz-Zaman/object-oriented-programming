#include "Point3d.h"
#include <cmath>

using namespace std;

Point3d::Point3d() : x(0), y(0), z(0) {}

Point3d::Point3d(float x, float y, float z) : x(x), y(y), z(z) {}

void Point3d::displace(float dx, float dy, float dz)
{
    x += dx;
    y += dy;
    z += dz;
}

float Point3d::distance(const Point3d &other) const
{
    return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2) + pow(z - other.z, 2));
}

bool Point3d::operator==(const Point3d &other) const
{
    return x == other.x && y == other.y && z == other.z;
}

bool Point3d::operator!=(const Point3d &other) const
{
    return !(*this == other);
}

Point3d Point3d::operator*(float scale) const
{
    return Point3d(x * scale, y * scale, z * scale);
}

Point3d operator*(float scale, const Point3d &point)
{
    return Point3d(point.x * scale, point.y * scale, point.z * scale);
}

Point3d Point3d::operator/(float scale) const
{
    if (scale == 0)
    {
        throw invalid_argument("Error: Division by zero is not allowed.");
    }
    return Point3d(x / scale, y / scale, z / scale);
}

ostream &operator<<(ostream &strm, const Point3d &point)
{
    return strm << "(" << point.x << ", " << point.y << ", " << point.z << ")";
}

istream &operator>>(istream &strm, Point3d &point)
{
    cout << "Enter x, y, z: ";
    strm >> point.x >> point.y >> point.z;
    if (!strm)
    {
        throw invalid_argument("Error: Invalid input for Point3d.");
    }
    return strm;
}
class Plane2d
{
protected:
    double a, b, c, d;

public:
    Plane2d(double a, double b, double c, double d) : a(a), b(b), c(c), d(d) {}

    bool is_on_plane(const Point3d &point) const
    {
        return (a * point.getX() + b * point.getY() + c * point.getZ() + d) == 0;
    }

    bool operator==(const Plane2d &other) const
    {
        return (a / other.a == b / other.b) && (b / other.b == c / other.c) && (c / other.c == d / other.d);
    }

    bool isPara(const Plane2d &other) const
    {
        return (a / other.a == b / other.b) && (b / other.b == c / other.c);
    }

    double dPoint(const Point3d &point) const
    {
        return (a * point.getX() + b * point.getY() + c * point.getZ() + d) / sqrt(a * a + b * b + c * c);
    }
};

int main()
{
    Plane2d plane1(2, -3, 5, 6);
    Plane2d plane2(4, -6, 10, 12);
    Point3d point(1, 2, 3);

    if (plane1.is_on_plane(point))
    {
        cout << "Point lies on plane: Yes" << endl;
    }
    else
    {
        cout << "Point lies on plane: No" << endl;
    }

    if (plane1 == plane2)
    {
        cout << "Planes are equa Yes" << endl;
    }
    else
    {
        cout << "Planes are equal No" << endl;
    }

    if (plane1.isPara(plane2))
    {
        cout << "Planes are parallel Yes" << endl;
    }
    else
    {
        cout << "Planes are parallel No" << endl;
    }

    cout << "Distance from point to plane " << plane1.dPoint(point) << endl;

    return 0;
}
