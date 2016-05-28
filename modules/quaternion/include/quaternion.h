// Copyright 2016 Hramov Ilya

#ifndef MODULES_QUATERNION_INCLUDE_QUATERNION_H_
#define MODULES_QUATERNION_INCLUDE_QUATERNION_H_

#include <math.h>
#include <limits>

const double epsilon = std::numeric_limits<double>::epsilon();

class Quaternion {
 public:
    // Constructor
    Quaternion(
        const double &x = 0.0,
        const double &y = 0.0,
        const double &z = 0.0,
        const double &w = 0.0);

    // Setters getters
    void setX(const double &x);
    void setY(const double &y);
    void setZ(const double &z);
    void setW(const double &w);

    double getX() const;
    double getY() const;
    double getZ() const;
    double getW() const;

    // Operators
    Quaternion operator+(const Quaternion &operand) const;
    Quaternion operator-(const Quaternion &operand) const;
    Quaternion& operator+=(const Quaternion &operand);
    Quaternion& operator-=(const Quaternion &operand);
    Quaternion operator*(const Quaternion &operand) const;
    Quaternion& operator*=(const Quaternion &operand);
    Quaternion operator!() const;  // conjugate
    Quaternion operator~() const;  // inverse
    bool operator==(const Quaternion &operand) const;
    bool operator!=(const Quaternion &operand) const;
    // Math actions
    double magnitude() const;
    double qmagnitude() const;
    Quaternion normalized() const;
    Quaternion inversed() const;
    Quaternion conjugated() const;
    // Other
    static bool isZero(const Quaternion &operand);

    // Fields
    double x;
    double y;
    double z;
    double w;
};

#endif  // MODULES_QUATERNION_INCLUDE_QUATERNION_H_
