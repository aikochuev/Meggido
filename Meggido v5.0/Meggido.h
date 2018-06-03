#pragma once
#include "Inequality.h"
#include <vector>
#include <omp.h>

//??
#include <math.h>
#include <algorithm>
#include <functional>
#include <iterator>

namespace meggido
{
    class CMeggido
    {
        Qfunc m_Q;
        Lim m_U;
        std::vector<Inequality> m_aInequality;
        std::vector<int> m_IPlus;
        std::vector<int> m_IMinus;
        std::vector<int> m_IZero;
        const int m_printMaxN = 15;
    public:
        CMeggido(const Qfunc& Q, const std::vector<Inequality>& aInequality) : m_Q(Q), m_aInequality(aInequality) {}
        Point PointInterseption(std::vector<int>& Index, int i, int j);
        Point Mediana(std::vector<Point>& A, int q);
        void Norm(Qfunc& Q);
        void Divided();
        std::vector<int> FindsLimX();
        void Transformation(std::vector<int>& Index);
        double FuncPlus(double x);
        double FuncMinus(double x);
        void DeleteParallelIneqPlus();
        void DeleteParallelIneqMinus();
        void InterPointDel();
        void DeleteIneq();
        void algo();
        void printInequality(Qfunc& Q);
        void printInequality(Qfunc& Q, std::vector<int>& Index);
        void printIndexInequality(std::vector<int>& Index);
    };
    void randIneq(Qfunc& Q, std::vector<Inequality>& aInequality);
    void saveTestData(Qfunc& Q, std::vector<Inequality>& aInequality);
    //void printPoint(std::vector<Point>& A);
}