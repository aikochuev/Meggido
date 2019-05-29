#include "stdafx.h"
#include "SuitableFractionsFinder.h"


SuitableFractionsFinder::SuitableFractionsFinder(const Fraction& frac)
{
    m_startFract = frac;

    m_colm0.push_back(frac.m_numerator);
    m_colm1.push_back(frac.m_denominator);

    m_colm0.push_back(1);
    m_colm1.push_back(0);

    m_colm0.push_back(0);
    m_colm1.push_back(1);
}


SuitableFractionsFinder::~SuitableFractionsFinder()
{
}

void SuitableFractionsFinder::find()
{
    std::cout << "Find Suitable Fractions: " << std::endl;
    while(m_colm0[0] != 0 && m_colm1[0] != 0)
    {
        if(m_colm0[0] > m_colm1[0])
            swap(m_colm0, m_colm1);

        int gcdLocal = gcd(m_colm0[0], m_colm1[0]);
        if(m_colm0[0] == 1)
            gcdLocal = m_colm1[0];

        m_colm1[0] -= gcdLocal * m_colm0[0];
        m_colm1[1] -= gcdLocal * m_colm0[1];
        m_colm1[2] -= gcdLocal * m_colm0[2];

        if(m_colm1[1] != 0 && m_colm1[2] != 0)
        {
            Fraction suit(abs(m_colm1[2]), abs(m_colm1[1]));
            if(abs(m_startFract) != suit)
                m_suitFractions.push_back(suit);
        }

        for(int i = 0; i < 3; i++)
            std::cout << m_colm0[i] << m_colm1[i] << std::endl;
        std::cout << std::endl;
    }
}

void SuitableFractionsFinder::getSuitFractions(std::vector<Fraction>& suitFractions)
{
    suitFractions = m_suitFractions;
}
