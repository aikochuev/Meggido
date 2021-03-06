#include "stdafx.h"
#include "Fraction.h"

Fraction::Fraction(int numerator, int denominator)
{
    m_numerator = numerator;
    m_denominator = abs(denominator);
    if(denominator < 0)
        m_numerator *= -1;
}

Fraction::Fraction(const Fraction& x)
{
    m_numerator = x.m_numerator;
    m_denominator = abs(x.m_denominator);
    if(x.m_denominator < 0)
        m_numerator *= -1;
}

bool Fraction::operator==(const Fraction& x) const
{
    return m_numerator == x.m_numerator && m_denominator == x.m_denominator;
}

bool Fraction::operator>(const Fraction& x) const
{
    return m_numerator * x.m_denominator > x.m_numerator*m_denominator;
}

bool Fraction::operator<(const Fraction& x) const
{
    return m_numerator * x.m_denominator < x.m_numerator*m_denominator;
}

bool Fraction::operator==(const double& x) const
{
    return abs(m_numerator / m_denominator - x) < eps;
}

bool Fraction::operator>(const double& x) const
{
    return m_numerator / m_denominator > x;
}

bool Fraction::operator<(const double& x) const
{
    return m_numerator / m_denominator < x;
}

bool Fraction::operator==(int& x) const
{
    return abs(m_numerator / m_denominator - x) < eps;
}

bool Fraction::operator>(int& x) const
{
    return m_numerator / m_denominator > x;
}

bool Fraction::operator<(int& x) const
{
    return m_numerator / m_denominator < x;
}

bool Fraction::operator!=(const Fraction& x) const
{
    return !(*this == x);
}

void Fraction::reduce()
{
    int gcdF = gcd(m_numerator, m_denominator);
    m_numerator /= gcdF;
    m_denominator /= gcdF;
}

Fraction& Fraction::operator=(const Fraction& x)
{
    if(this != &x)
    {
        m_numerator = x.m_numerator;
        m_denominator = x.m_denominator;
    }
    return (*this);
}

Fraction Fraction::operator/(const Fraction& x) const
{
    Fraction tmp(m_numerator*x.m_denominator, x.m_numerator*m_denominator);
    tmp.reduce();
    return tmp;
}

Fraction Fraction::operator/(const int& x) const
{
    return Fraction();
}

Fraction Fraction::operator+(const Fraction& x) const
{
    Fraction tmp(m_numerator*x.m_denominator + m_denominator * x.m_numerator, x.m_denominator*m_denominator);
    tmp.reduce();
    return tmp;
}

Fraction Fraction::operator+(const int& x) const
{
    Fraction tmp(m_numerator + m_denominator * x, m_denominator);
    tmp.reduce();
    return tmp;
}

Fraction Fraction::operator*(const Fraction& x) const
{
    Fraction tmp(m_numerator*x.m_numerator, x.m_denominator*m_denominator);
    tmp.reduce();
    return tmp;
}

Fraction Fraction::operator*(const int& x) const
{
    Fraction tmp(m_numerator*x, m_denominator);
    tmp.reduce();
    return tmp;
}

Fraction Fraction::operator-(const Fraction& x) const
{
    Fraction tmp(m_numerator*x.m_denominator - m_denominator * x.m_numerator, x.m_denominator*m_denominator);
    tmp.reduce();
    return tmp;
}

Fraction Fraction::operator-(const int& x) const
{
    Fraction tmp(m_numerator - m_denominator *x, m_denominator);
    tmp.reduce();
    return tmp;
}

int gcd(int a, int b)
{
    if(b == 0)
        return a;
    else
        return gcd(b, a%b);
}

const Fraction operator-(const Fraction& f)
{
    return Fraction(-f.m_numerator, f.m_denominator);
}

std::ostream &operator<<(std::ostream& out, const Fraction& c)
{
    return out << c.m_numerator << "/" << c.m_denominator;
}

Fraction abs(const Fraction& fraction)
{
    return Fraction(abs(fraction.m_numerator), abs(fraction.m_denominator));
}

bool isNull(const double& x)
{
    return abs(x) < eps;
}

bool isNull(const Fraction& x)
{
    return abs(x) < eps;
}
