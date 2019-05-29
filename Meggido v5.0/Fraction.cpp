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

bool Fraction::operator==(const Fraction& x)
{
    return m_numerator == x.m_numerator && m_denominator == x.m_denominator;
}

bool Fraction::operator>(const Fraction& x)
{
    Fraction tmp(m_numerator*x.m_denominator, x.m_denominator*m_denominator);
    Fraction tmpX(x.m_numerator*m_denominator, x.m_denominator*m_denominator);
    return tmp.m_numerator > tmpX.m_numerator;
}

bool Fraction::operator<(const Fraction& x)
{
    Fraction tmp(m_numerator*x.m_denominator, x.m_denominator*m_denominator);
    Fraction tmpX(x.m_numerator*m_denominator, x.m_denominator*m_denominator);
    return tmp.m_numerator < tmpX.m_numerator;
}

bool Fraction::operator!=(const Fraction& x)
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

Fraction Fraction::operator/(const Fraction& x)
{
    Fraction tmp(m_numerator*x.m_denominator, x.m_numerator*m_denominator);
    tmp.reduce();
    return tmp;
}

Fraction Fraction::operator/(const int& x)
{
    return Fraction();
}

Fraction Fraction::operator+(const Fraction& x)
{
    Fraction tmp(m_numerator*x.m_denominator + m_denominator * x.m_numerator, x.m_denominator*m_denominator);
    tmp.reduce();
    return tmp;
}

Fraction Fraction::operator*(const Fraction& x)
{
    Fraction tmp(m_numerator*x.m_numerator, x.m_denominator*m_denominator);
    tmp.reduce();
    return tmp;
}

Fraction Fraction::operator*(const int& x)
{
    Fraction tmp(m_numerator*x, m_denominator);
    tmp.reduce();
    return tmp;
}

Fraction Fraction::operator-(const Fraction& x)
{
    Fraction tmp(m_numerator*x.m_denominator - m_denominator * x.m_numerator, x.m_denominator*m_denominator);
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

std::ostream &operator<<(std::ostream& out, const Fraction& c)
{
    return out << c.m_numerator << "/" << c.m_denominator;
}

Fraction abs(const Fraction& fraction)
{
    return Fraction(abs(fraction.m_numerator), abs(fraction.m_denominator));
}

