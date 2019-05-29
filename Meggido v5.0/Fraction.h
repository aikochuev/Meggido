#pragma once
#include "iostream"

int gcd(int a, int b);

class Fraction
{
public:
    int m_numerator = 0;
    int m_denominator = 0;

    Fraction() {}
    Fraction(int numerator, int denominator);
    ~Fraction() {}
    Fraction(const Fraction& x);

    bool operator==(const Fraction& x);
    bool operator>(const Fraction& x);
    bool operator<(const Fraction& x);
    bool operator!=(const Fraction& x);
    void reduce();
    Fraction& operator=(const Fraction& x);
    Fraction operator/(const Fraction& x);
    Fraction operator/(const int& x);
    Fraction operator+(const Fraction& x);
    Fraction operator*(const Fraction& x);
    Fraction operator*(const int& x);
    Fraction operator-(const Fraction& x);
    friend std::ostream &operator<<(std::ostream&, const Fraction&);
    
};
std::ostream &operator<<(std::ostream& out, const Fraction& c);
Fraction abs(const Fraction& fraction);