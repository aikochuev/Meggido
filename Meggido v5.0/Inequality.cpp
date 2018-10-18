#include "stdafx.h"
#include <math.h>
#include "Inequality.h"

Inequality::Inequality(const Inequality &X)
{
    a = X.a;
    b = X.b;
    c = X.c;
    z = X.z;
}

Inequality& Inequality::operator= (Inequality &X)
{
    if(this != &X)
    {
        a = X.a;
        b = X.b;
        c = X.c;
        z = X.z;
    }
    return (*this);
}
Inequality Inequality::operator/ (Inequality X)
{
    Inequality Y;
    if ((X.a != 0) && (X.b != 0) && (X.c != 0))
    {
        Y.a = a / X.a;
        Y.b = b / X.b;
        Y.c = c / X.c;
    }
    return Y;
}
Inequality Inequality::operator+ (Inequality X)
{
    Inequality Y;
    Y.a = a + X.a;
    Y.b = b + X.b;
    Y.c = c + X.c;
    Y.z = X.z;
    return Y;
}
Inequality Inequality::operator- (Inequality X)
{
    Inequality Y;
    Y.a = a - X.a;
    Y.b = b - X.b;
    Y.c = c - X.c;
    Y.z = X.z;
    return Y;
}


std::ostream& operator<<(std::ostream &out, const Inequality  &c)
{
    if (c.z)
    {
        if (c.b > 0)
            if (c.c > 0)
                out << c.a << "x + " << c.b << "y + " << c.c << " >= 0" << std::endl;
            else
                out << c.a << "x + " << c.b << "y - " << abs(c.c) << " >= 0" << std::endl;
        else
            if (c.c > 0)
                out << c.a << "x - " << abs(c.b) << "y + " << c.c << " >= 0" << std::endl;
            else
                out << c.a << "x - " << abs(c.b) << "y - " << abs(c.c) << " >= 0" << std::endl;
    }
    else
    {
        if (c.b > 0)
            if (c.c > 0)
                out << c.a << "x + " << c.b << "y + " << c.c << " <= 0" << std::endl;
            else
                out << c.a << "x + " << c.b << "y - " << abs(c.c) << " <= 0" << std::endl;
        else
            if (c.c > 0)
                out << c.a << "x - " << abs(c.b) << "y + " << c.c << " <= 0" << std::endl;
            else
                out << c.a << "x - " << abs(c.b) << "y - " << abs(c.c) << " <= 0" << std::endl;
    }
    return out;
}

std::ostream &operator<<(std::ostream &out, Qfunc  &c)
{
    if (c.b > 0)
        out << "min " << c.a << "x + " << c.b << "y " << std::endl;
    else
        out << "min " << c.a << "x - " << abs(c.b) << "y " << std::endl;
    return out;
}
std::ostream &operator<<(std::ostream &out, Point  &c)
{
    out << "Point = (" << c.x << "," << c.y << ") " << " Inequalities = [" << c.NumIneq1 << ";" << c.NumIneq2 << "] " << std::endl;
    return out;
}

std::ostream &operator<<(std::ostream &out, Lim  &c)
{
    out << "(u1 = " << c.u1 << "; u2 = " << c.u2 << ")" << std::endl;
    return out;
}

std::istream &operator >> (std::istream &in, Inequality  &c)
{
    in >> c.a >> c.b >> c.c >> c.z;
    return in;
}

bool Point::isEqual(const Point& y)
{
    if(this->NumIneq1 != y.NumIneq1)
        return false;
    if(this->NumIneq2 != y.NumIneq2)
        return false;
    if(std::fabs(this->x - y.x) > std::numeric_limits<double>::epsilon())
        return false;
    if(std::fabs(this->y - y.y) > std::numeric_limits<double>::epsilon())
        return false;
    return true;
}

bool Point::operator==(const Point& y)
{
    if(this->NumIneq1 != y.NumIneq1)
        return false;
    if(this->NumIneq2 != y.NumIneq2)
        return false;
    if(std::fabs(this->x - y.x) > std::numeric_limits<double>::epsilon())
        return false;
    if(std::fabs(this->y - y.y) > std::numeric_limits<double>::epsilon())
        return false;
    return true;
}

bool Point::operator!=(const Point& y)
{
    return !(*this == y);
}
