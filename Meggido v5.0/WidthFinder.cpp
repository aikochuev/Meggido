#include "stdafx.h"
#include "WidthFinder.h"


WidthFinder::WidthFinder()
{
}


WidthFinder::~WidthFinder()
{
}

void WidthFinder::find()
{
    std::vector<Fraction> result;
    int widthIndex;
    m_width = Fraction(INT_MAX, 1);
    Fraction maxFromResult(INT_MAX, 1);

    std::cout << "Find Width: " << std::endl;
    for(const auto& frac : m_suitFractions)
    {
        std::cout << m_matrix << std::endl << "mult " << std::endl << frac << std::endl;

        multHNFmatrixOnVectorSuit(m_matrix, frac, result);
        std::cout << "result: (" << result[0] << " " << result[1] << ")" << std::endl;

        maxFromResult = abs(result[0]) > abs(result[1]) ? result[0] : result[1];
        std::cout << "Local Width: " << maxFromResult << std::endl << std::endl;

        if(maxFromResult < m_width)
        {
            m_width = maxFromResult;
            m_widthSuitFrac = frac;
        }
    }
}

Fraction WidthFinder::width()
{
    return m_width;
}

Fraction WidthFinder::widthSuitFrac()
{
    return m_widthSuitFrac;
}
