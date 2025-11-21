#ifndef Point3D_H
#define Point3D_H

#include <iostream>
#include <string>

using namespace std;

class Point3d
{
protected:
    float x, y, z;

public:
    Point3d();
    Point3d(float, float, float);
    double getX() const { return x; }
    double getY() const { return y; }
    double getZ() const { return z; }
    void setX(double newX) { x = newX; }
    void setY(double newY) { y = newY; }
    void setZ(double newZ) { z = newZ; }
    void displace(float, float, float);
    float distance(const Point3d &) const;
    bool operator==(const Point3d &) const;
    bool operator!=(const Point3d &) const;
    Point3d operator*(float) const;
    friend Point3d operator*(float, const Point3d &);
    Point3d operator/(float) const;
    friend ostream &operator<<(ostream &strm, const Point3d &);
    friend istream &operator>>(istream &strm, Point3d &);
};

#endif
