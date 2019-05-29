#pragma once
#include "Fraction.h"
#include <vector>

class HNFmatrix
{
public:
    Fraction m_a;
    Fraction m_b;
    Fraction m_c;
    HNFmatrix(const Fraction& a, const Fraction& b, const Fraction& c) : m_a(a), m_b(b), m_c(c){}
    HNFmatrix(){}
    ~HNFmatrix();
    friend std::ostream &operator<<(std::ostream&, const HNFmatrix&);
};
std::ostream &operator<<(std::ostream& out, const HNFmatrix& c);

void multHNFmatrixOnVectorSuit(HNFmatrix& matrix, const Fraction& xy, std::vector<Fraction>& result);

