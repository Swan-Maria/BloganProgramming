#pragma once

class Polar {};

class Cartesian
{
private:
    double x;
    double y;

public:
    Cartesian(double x = 0, double y = 0) : x(x), y(y) {}

    const double& X() const { return x; }
    double& X() { return x; }

    const double& Y() const { return y; }
    double& Y() { return y; }

    operator Polar() const;
};