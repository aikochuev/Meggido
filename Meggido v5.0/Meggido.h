#pragma once
#include "Inequality.h"
#include <vector>
#include <omp.h>
#include <xmllite.h>
#include <math.h>
#include <algorithm>
#include <functional>
#include <fstream>
#include <iterator>
#include <stdlib.h>
#include <string>

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
        Point m_result;
        std::string m_filename;
    public:
        CMeggido(std::string filename, const Qfunc& Q, const std::vector<Inequality>& aInequality) :m_filename(filename), m_Q(Q), m_aInequality(aInequality) {}
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
        void doExam();
        void saveExamData();
        void saveResultData();
        Point readExamData();
    };
    void randIneq(Qfunc& Q, std::vector<Inequality>& aInequality);
    void saveTestData(std::string filename, const Qfunc& Q,const std::vector<Inequality>& aInequality);
    void readTestData(std::string filename, Qfunc& Q, std::vector<Inequality>& aInequality);
    //void printPoint(std::vector<Point>& A);
}