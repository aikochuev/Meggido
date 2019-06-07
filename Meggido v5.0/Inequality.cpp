#include "stdafx.h"
#include <math.h>
#include "Inequality.h"

template<typename T> CInequality<T>::CInequality(const CInequality<T> &X)
{
    a = X.a;
    b = X.b;
    c = X.c;
}

CInequality<double>::CInequality(const CInequality<double>& X)
{
    a = X.a;
    b = X.b;
    c = X.c;
}

CInequality<Fraction>::CInequality(const CInequality<Fraction>& X)
{
    a = X.a;
    b = X.b;
    c = X.c;
}

template<typename T> CInequality<T>& CInequality<T>::operator=(CInequality<T>& X)
{
    if(this != &X)
    {
        a = X.a;
        b = X.b;
        c = X.c;
    }
    return (*this);
}

CInequality<Fraction>& CInequality<Fraction>::operator=(CInequality<Fraction>& X)
{
    if(this != &X)
    {
        a = X.a;
        b = X.b;
        c = X.c;
    }
    return (*this);
}

template<typename T> CInequality<T> CInequality<T>::operator/ (CInequality<T> X)
{
    CInequality<T> Y;
    if ((X.a != 0) && (X.b != 0) && (X.c != 0))
    {
        Y.a = a / X.a;
        Y.b = b / X.b;
        Y.c = c / X.c;
    }
    return Y;
}

template<typename T> CInequality<T> CInequality<T>::operator+ (CInequality<T> X)
{
    CInequality<T> Y;
    Y.a = a + X.a;
    Y.b = b + X.b;
    Y.c = c + X.c;
    return Y;
}

template<typename T> CInequality<T> CInequality<T>::operator- (CInequality<T> X)
{
    CInequality<T> Y;
    Y.a = a - X.a;
    Y.b = b - X.b;
    Y.c = c - X.c;
    return Y;
}


template<typename T> std::ostream& operator<<(std::ostream &out, const CInequality<T>  &c)
{
    if(c.b > 0)
        if(c.c > 0)
            out << c.a << "x + " << c.b << "y + " << c.c << " <= 0" << std::endl;
        else
            out << c.a << "x + " << c.b << "y - " << abs(c.c) << " <= 0" << std::endl;
    else
        if(c.c > 0)
            out << c.a << "x - " << abs(c.b) << "y + " << c.c << " <= 0" << std::endl;
        else
            out << c.a << "x - " << abs(c.b) << "y - " << abs(c.c) << " <= 0" << std::endl;
    return out;
}

std::ostream& operator<<(std::ostream &out, const CInequality<double>  &c)
{
    if(c.b > 0)
        if(c.c > 0)
            out << c.a << "x + " << c.b << "y + " << c.c << " <= 0" << std::endl;
        else
            out << c.a << "x + " << c.b << "y - " << abs(c.c) << " <= 0" << std::endl;
    else
        if(c.c > 0)
            out << c.a << "x - " << abs(c.b) << "y + " << c.c << " <= 0" << std::endl;
        else
            out << c.a << "x - " << abs(c.b) << "y - " << abs(c.c) << " <= 0" << std::endl;
    return out;
}

std::ostream& operator<<(std::ostream &out, const CInequality<Fraction> &c)
{
    if(c.b > 0)
        if(c.c > 0)
            out << c.a << "x + " << c.b << "y + " << c.c << " <= 0" << std::endl;
        else
            out << c.a << "x + " << c.b << "y - " << abs(c.c) << " <= 0" << std::endl;
    else
        if(c.c > 0)
            out << c.a << "x - " << abs(c.b) << "y + " << c.c << " <= 0" << std::endl;
        else
            out << c.a << "x - " << abs(c.b) << "y - " << abs(c.c) << " <= 0" << std::endl;
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

template<typename T> std::istream &operator >> (std::istream &in, CInequality<T>  &c)
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
