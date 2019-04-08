#pragma once
#include "Inequality.h"
#include <vector>
#include <omp.h>
#include <xmllite.h>
#include <math.h>
#include <algorithm>
#include <functional>
#include <iterator>
#include <stdlib.h>
#include <string>

namespace meggido
{
    class CMeggido
    {
    public:
        CMeggido(const Qfunc& Q, const std::vector<Inequality>& aInequality) : m_Q(Q), m_aInequality(aInequality) {}
        virtual const Point& algo();

    protected:
        virtual void Norm();
        virtual const Point& getResult();

    protected:
        Point PointInterseption(std::vector<int>& Index, int i, int j);
        Point Mediana(std::vector<Point>& A, int q);
        void Divided();
        void FindsLimX();
        void Transformation(std::vector<int>& Index);
        double FuncPlus(double x);
        double FuncMinus(double x);
        void DeleteIneqPlus();
        void DeleteIneqMinus();
        void InterPointDel();
        
        void printInequality(Qfunc& Q);
        void printInequality(Qfunc& Q, std::vector<int>& Index);
        void printIndexInequality(std::vector<int>& Index);
        
    protected:
        Qfunc m_Q;
        Lim m_U;
        std::vector<Inequality> m_aInequality;
        std::vector<int> m_IPlus;
        std::vector<int> m_IMinus;
        std::vector<int> m_IPlusNotDel;
        std::vector<int> m_IMinusNotDel;
        std::vector<int> m_IZero;
        const int m_printMaxN = 15;
        Point m_result;
    };
    class CMeggidoX : public virtual CMeggido
    {
    public:
        CMeggidoX(const Qfunc& Q, const std::vector<Inequality>& aInequality) : CMeggido(Q, aInequality) {}
        virtual void Norm();

    };
    class CMeggidoMax : public  virtual CMeggido
    {
    public:
        CMeggidoMax(const Qfunc& Q, const std::vector<Inequality>& aInequality) : CMeggido(Q, aInequality) {}
        virtual const Point& getResult();
    };

    class CMeggidoMaxX : public CMeggidoMax, public CMeggidoX
    {
    public:
        CMeggidoMaxX(const Qfunc& Q, const std::vector<Inequality>& aInequality) : CMeggidoMax(Q, aInequality), CMeggidoX(Q, aInequality), CMeggido(Q, aInequality) {}
    };

    typedef CMeggidoMax CMeggidoMaxY;
    typedef CMeggidoX CMeggidoMinX;
    typedef CMeggido CMeggidoMinY;

    void randIneq(Qfunc& Q, std::vector<Inequality>& aInequality);
    //void printPoint(std::vector<Point>& A);
}