#include "stdafx.h"
#include <ctime>
#include "Test.h"
#include "Meggido.h"
#include "Fraction.h"
#include "SuitableFractionsFinder.h"
#include "WidthFinder.h"

int main(int argc, char* argv[])
{
    Fraction a(1, 2);
    Fraction b(3, 4);
    std::cout << a << b;
    Fraction sum(a + b);
    Fraction sub(a - b);
    Fraction mult(a * b);
    Fraction div(a / b);
    std::cout << sum;
    std::cout << sub;
    std::cout << mult;
    std::cout << div;

    HNFmatrix matrix(Fraction(8, 7), Fraction(5, 7), Fraction(1, 1));
    std::cout << "HNF Matrix:" << std::endl;
    std::cout << matrix << std::endl;
    std::cout << std::endl;

    SuitableFractionsFinder suitableFractionsFinder(matrix.m_b / matrix.m_a);
    suitableFractionsFinder.find();
    std::vector<Fraction> suitFractions;
    suitableFractionsFinder.getSuitFractions(suitFractions);
    std::cout << "Suitable Fractions:" << std::endl;
    for(const auto& frac : suitFractions)
        std::cout << frac << std::endl;
    std::cout << std::endl;

    WidthFinder widthFinder(matrix, suitFractions);
    widthFinder.find();
    std::cout << "Width: " << widthFinder.width() << std::endl;
    std::cout << "Width Suitable Fraction: " << widthFinder.widthSuitFrac() << std::endl;

    std::vector<InequalityFrac> aInequality;
    aInequality.push_back(InequalityFrac(Fraction(1, 1), Fraction(0, 1), Fraction(0, 1)));
    aInequality.push_back(InequalityFrac(Fraction(0, 1), Fraction(1, 1), Fraction(0, 1)));

    aInequality.push_back(InequalityFrac(Fraction(-1, 1), Fraction(1, 1), Fraction(10, 1)));
    aInequality.push_back(InequalityFrac(Fraction(-2, 1), Fraction(1, 1), Fraction(11, 1)));
    aInequality.push_back(InequalityFrac(Fraction(-3, 1), Fraction(1, 1), Fraction(12, 1)));
    aInequality.push_back(InequalityFrac(Fraction(-4, 1), Fraction(1, 1), Fraction(13, 1)));
    aInequality.push_back(InequalityFrac(Fraction(-5, 1), Fraction(1, 1), Fraction(14, 1)));
    aInequality.push_back(InequalityFrac(Fraction(-6, 1), Fraction(1, 1), Fraction(15, 1)));
    aInequality.push_back(InequalityFrac(Fraction(-7, 1), Fraction(1, 1), Fraction(16, 1)));
    aInequality.push_back(InequalityFrac(Fraction(-8, 1), Fraction(1, 1), Fraction(17, 1)));
    aInequality.push_back(InequalityFrac(Fraction(-9, 1), Fraction(1, 1), Fraction(18, 1)));

    
    /*aInequality[1].a = -1; aInequality[1].b = 0; aInequality[1].c = 3;
    aInequality[2].a = -1; aInequality[2].b = 1; aInequality[2].c = -5;
    aInequality[3].a = -0.33; aInequality[3].b = 1; aInequality[3].c = -2;
    aInequality[4].a = -0.33; aInequality[4].b = -1; aInequality[4].c = -2;
    aInequality[5].a = -1; aInequality[5].b = -1; aInequality[5].c = -5;
    aInequality[6].a = 0.33; aInequality[6].b = 1; aInequality[6].c = -2;
    aInequality[7].a = 1; aInequality[7].b = 1; aInequality[7].c = -5;
    aInequality[8].a = 1; aInequality[8].b = -1; aInequality[8].c = -5;
    aInequality[9].a = 0.33; aInequality[9].b = -1; aInequality[9].c = -2;*/

    for(const auto& inq : aInequality)
        std::cout << inq;
    


    /*std::vector<std::vector<Fraction>> matrV;
    std::vector<int> firstRow;
    firstRow.push_back(10);
    firstRow.push_back(6);
    std::vector<int> secondRow;
    secondRow.push_back(7);
    secondRow.push_back(4);
    matrV.push_back(firstRow);
    matrV.push_back(secondRow);*/


    /*std::vector<std::vector<int>> matrV;
    std::vector<int> firstRow;
    firstRow.push_back(10);
    firstRow.push_back(6);
    std::vector<int> secondRow;
    secondRow.push_back(7);
    secondRow.push_back(4);
    matrV.push_back(firstRow);
    matrV.push_back(secondRow);

    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            std::cout << matrV[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << gcd(5, 15) << std::endl;
    std::cout << gcd(10, 20) << std::endl;
    std::cout << gcd(49, 7) << std::endl;
    
    while(matrV[1][0] != 0)
    {
        if(matrV[0][0] > matrV[1][0])
            swap(matrV[0], matrV[1]);

        int gcdLocal = gcd(matrV[0][0], matrV[1][0]);
        matrV[1][0] -= gcdLocal * matrV[0][0];
        matrV[1][1] -= gcdLocal * matrV[0][1];

        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < 2; j++)
            {
                std::cout << matrV[i][j];
            }
            std::cout << std::endl;
        }
    }

    if(matrV[1][1] < 0)
        matrV[1][1] *= -1;

    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            std::cout << matrV[i][j];
        }
        std::cout << std::endl;
    }
    if(matrV[0][0] > matrV[0][1] 
        && matrV[0][1] >= 0
        && matrV[1][1] > 0
        && matrV[1][0] == 0)
        std::cout <<"correct HNF"<< std::endl;
    else
        std::cout << "incorrect HNF" << std::endl;
    */

    /*std::srand(time(NULL));
    setlocale(LC_ALL, "Russian");
    std::vector<Inequality> aInequality;
    Qfunc Q;
    std::string fullpart;
    if(argc > 1)
    { 
        test::Test test(argv[1]);
        test.runTest();
    }
    else
    {
        /*int n = 0;
        do
        {
            std::cout << "n = ";
            std::cin >> n;
            std::cout << std::endl;
        } while(n > 10000001);
        if(n != 0)
        {
            aInequality.resize(n);
            aInequality[0].a = 1; aInequality[0].b = 0; aInequality[0].c = 3;
            aInequality[1].a = -1; aInequality[1].b = 0; aInequality[1].c = 3;
            aInequality[2].a = -1; aInequality[2].b = 1; aInequality[2].c = -5;
            aInequality[3].a = -0.33; aInequality[3].b = 1; aInequality[3].c = -2;
            aInequality[4].a = -0.33; aInequality[4].b = -1; aInequality[4].c = -2;
            aInequality[5].a = -1; aInequality[5].b = -1; aInequality[5].c = -5;
            aInequality[6].a = 0.33; aInequality[6].b = 1; aInequality[6].c = -2;
            aInequality[7].a = 1; aInequality[7].b = 1; aInequality[7].c = -5;
            aInequality[8].a = 1; aInequality[8].b = -1; aInequality[8].c = -5;
            aInequality[9].a = 0.33; aInequality[9].b = -1; aInequality[9].c = -2;
            Q.a = 4; Q.b = 5; Q.c = 0;
            //meggido::randIneq(Q, aInequality);
            //std::cout << "¬ведите путь им€ файла" << std::endl;
            fullpart.append("C:\\Users\\kochu\\Documents\\Meggido\\Tests\\test");
            fullpart.append(std::to_string(n));
            std::cout << "—брос данных дл€ теста" << std::endl;
            test::Test::saveTestData(fullpart, Q, aInequality);
        }
    }*/
    system("pause");
    return 0;
}
