#pragma once
#include "HNFmatrix.h"

class WidthFinder
{
    HNFmatrix m_matrix;
    std::vector<Fraction> m_suitFractions;
    Fraction m_widthSuitFrac;
    Fraction m_width;
public:
    WidthFinder();
    WidthFinder(HNFmatrix& matrix, std::vector<Fraction>& suitFractions) : m_matrix(matrix), m_suitFractions(suitFractions){}
    ~WidthFinder();
    void find();
    Fraction width();
    Fraction widthSuitFrac();
};

