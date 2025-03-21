#pragma once

class Cartesian;

class Polar
{
private:
    double radius;
    double angle;

public:
    Polar(double radius = 0, double angle = 0) : radius(radius), angle(angle) {}

    const double& Radius() const { return radius; }
    double& Radius() { return radius; }

    const double& Angle() const { return angle; }
    double& Angle() { return angle; }

    operator Cartesian() const;
};