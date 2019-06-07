#pragma once
#include "iostream"

int gcd(int a, int b);

class Fraction
{
public:
    int m_numerator;
    int m_denominator;

    Fraction() : m_numerator(0), m_denominator(1){}
    Fraction(int numerator, int denominator);
    ~Fraction() {}
    Fraction(const Fraction& x);

    bool operator==(const Fraction& x) const;
    bool operator>(const Fraction& x) const;
    bool operator<(const Fraction& x) const;
    bool operator==(const double& x) const;
    bool operator>(const double& x) const;
    bool operator<(const double& x) const;
    bool operator==(int& x) const;
    bool operator>(int& x) const;
    bool operator<(int& x) const;
    bool operator!=(const Fraction& x) const;
    void reduce();
    Fraction& operator=(const Fraction& x);
    Fraction operator/(const Fraction& x) const;
    Fraction operator/(const int& x) const;
    Fraction operator+(const Fraction& x) const;
    Fraction operator+(const int& x) const;
    Fraction operator*(const Fraction& x) const;
    Fraction operator*(const int& x) const;
    Fraction operator-(const Fraction& x) const;
    Fraction operator-(const int& x) const;
    friend std::ostream &operator<<(std::ostream&, const Fraction&);
    friend const Fraction operator-(const Fraction& f);
    
};
const Fraction operator-(const Fraction& f);
std::ostream &operator<<(std::ostream& out, const Fraction& c);
Fraction abs(const Fraction& fraction);
bool isNull(const double& x);
bool isNull(const Fraction& x);