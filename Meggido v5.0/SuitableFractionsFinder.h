#pragma once
#include <vector>
#include "Fraction.h"

class SuitableFractionsFinder
{
    std::vector<int> m_colm0;
    std::vector<int> m_colm1;
    Fraction m_startFract;
    std::vector<Fraction> m_suitFractions;
public:
    SuitableFractionsFinder(const Fraction& frac);
    ~SuitableFractionsFinder();
    void find();
    void getSuitFractions(std::vector<Fraction> &suitFractions);
};

