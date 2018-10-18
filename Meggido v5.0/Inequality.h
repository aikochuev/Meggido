#pragma once
#include "iostream"
#include <cmath>
#include <limits>

struct Point
{
    double x = 0.;
    double y = 0.;
    /*double tl1 = 0.;
    double tr1 = 0.;
    double tl2 = 0.;
    double tr2 = 0.;*/
    int NumIneq1 = 0;
    int NumIneq2 = 0;
    bool isEqual(const Point& y);
    bool operator==(const Point& y);
    bool operator!=(const Point& y);
};


struct Qfunc
{
    double a = 0.; 
    double b = 0.;
    double c = 0.;
    friend std::ostream& operator << (std::ostream &, Qfunc &);
};

struct Lim
{
    double u1 = -DBL_MAX;
    double u2 = DBL_MAX;
};

class Inequality
{
public:
    double a = 0, b = 0, c = 0;
    bool z = false;
    Inequality() {}
    Inequality(double x, double y, double p, bool q) : a(x), b(y), c(p), z(q) {}
    ~Inequality() {}
    Inequality(const Inequality &X);

    Inequality& operator=(Inequality &X);
    Inequality operator/(Inequality X);
    Inequality operator+(Inequality X);
    Inequality operator-(Inequality X);
    friend std::ostream &operator<<(std::ostream &, const Inequality &);
    friend std::istream &operator>>(std::istream &, Inequality &);
};
std::ostream& operator<<(std::ostream &out, const Inequality  &c);
std::ostream &operator<<(std::ostream &out, Qfunc  &c);
std::ostream &operator<<(std::ostream &out, Point  &c);
std::ostream &operator<<(std::ostream &out, Lim  &c);
std::istream &operator>>(std::istream &in, Inequality  &c);