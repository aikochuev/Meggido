#pragma once
#include "iostream"

struct Point
{
    double x = 0, y = 0, tl1 = 0, tr1 = 0, tl2 = 0, tr2 = 0, NumIneq1 = 0, NumIneq2 = 0;
};


struct Qfunc
{
    double a = 0, b = 0, c = 0;
    friend std::ostream& operator << (std::ostream &, Qfunc &);
};

struct Lim
{
    double u1 = -INFINITY;
    double u2 = +INFINITY;
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

    Inequality& operator= (Inequality &X);
    Inequality operator/ (Inequality X);
    Inequality operator+ (Inequality X);
    Inequality operator- (Inequality X);
    friend std::ostream &operator << (std::ostream &, const Inequality &);
    friend std::istream &operator >> (std::istream &, Inequality &);
};
std::ostream& operator<<(std::ostream &out, const Inequality  &c);
std::ostream &operator<<(std::ostream &out, Qfunc  &c);
std::ostream &operator<<(std::ostream &out, Point  &c);
std::ostream &operator<<(std::ostream &out, Lim  &c);
std::istream &operator >> (std::istream &in, Inequality  &c);