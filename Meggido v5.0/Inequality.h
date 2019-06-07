#pragma once
#include "iostream"
#include <cmath>
#include <limits>
#include "Fraction.h"

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

template<typename T> class CInequality
{
public:
    T a, b, c;
    CInequality() {}
    CInequality(T x, T y, T p) : a(x), b(y), c(p) {}
    ~CInequality() {}
    CInequality(const CInequality<T> &X);

    CInequality<T>& operator=(CInequality<T> &X);
    CInequality<T> operator/(CInequality<T> X);
    CInequality<T> operator+(CInequality<T> X);
    CInequality<T> operator-(CInequality<T> X);
    friend std::ostream &operator<<(std::ostream &, const CInequality<T> &);
    friend std::istream &operator>>(std::istream &, CInequality<T> &);
};
typedef CInequality<double> Inequality;
typedef CInequality<Fraction> InequalityFrac;

template<typename T> std::ostream& operator<<(std::ostream &out, const CInequality<T>  &c);
std::ostream &operator<<(std::ostream &out, Qfunc  &c);
std::ostream &operator<<(std::ostream &out, Point  &c);
std::ostream &operator<<(std::ostream &out, Lim  &c);
template<typename T> std::istream &operator>>(std::istream &in, CInequality<T>  &c);