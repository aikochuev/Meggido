#include "stdafx.h"
#include "HNFmatrix.h"

HNFmatrix::~HNFmatrix()
{
}

std::ostream& operator<<(std::ostream& out, const HNFmatrix& c)
{
    out << c.m_a << " " << c.m_b << std::endl;
    out << 0 << " " << c.m_c;
    return out;
}

void multHNFmatrixOnVectorSuit(HNFmatrix& matrix, const Fraction& xy, std::vector<Fraction>& result)
{
    result.clear();
    result.push_back(Fraction(matrix.m_a*(-1 * xy.m_numerator) + matrix.m_b*xy.m_denominator));
    result.push_back(Fraction(matrix.m_c*xy.m_denominator));
}
