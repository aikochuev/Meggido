#include "stdafx.h"
#include "Test.h"
#include <fstream>
#include "Meggido.h"

namespace test
{
;
void Test::runTest()
{
    std::vector<Inequality> aInequality;
    Qfunc Q;
    std::cout << "Чтение данных для теста" << std::endl;
    readTestData(m_filename, Q, aInequality);

    meggido::CMeggidoMaxX meggidoAlgoMaxX(Q, aInequality);
    std::cout << "meggidoAlgoMaxX" << std::endl;
    double t_start = omp_get_wtime();
    m_result = meggidoAlgoMaxX.algo();
    double t_end = omp_get_wtime();
    std::cout << "time = " << t_end - t_start << std::endl;
    doExam();

    meggido::CMeggidoMaxY meggidoAlgoMaxY(Q, aInequality);
    std::cout << "meggidoAlgoMaxY" << std::endl;
    t_start = omp_get_wtime();
    m_result = meggidoAlgoMaxY.algo();
    t_end = omp_get_wtime();
    std::cout << "time = " << t_end - t_start << std::endl;
    doExam();

    meggido::CMeggidoMinX meggidoAlgoMinX(Q, aInequality);
    std::cout << "meggidoAlgoMinX" << std::endl;
    t_start = omp_get_wtime();
    m_result = meggidoAlgoMinX.algo();
    t_end = omp_get_wtime();
    std::cout << "time = " << t_end - t_start << std::endl;
    doExam();

    meggido::CMeggidoMinY meggidoAlgoMinY(Q, aInequality);
    std::cout << "meggidoAlgoMinY" << std::endl;
    t_start = omp_get_wtime();
    m_result = meggidoAlgoMinY.algo();
    t_end = omp_get_wtime();
    std::cout << "time = " << t_end - t_start << std::endl;
    doExam();
}

void Test::doExam()
{
    std::ifstream fin;
    std::string filename(m_filename);
    filename.append(".exam");
    fin.open(filename.c_str());
    if(fin.is_open())
    {
        fin.close();
        if(m_result != readExamData())
            saveResultData();
    }
    else
        saveExamData();
}

void Test::saveExamData()
{
    std::ofstream fout;
    std::string filename(m_filename);
    filename.append(".exam");
    fout.open(filename.c_str(), std::ios_base::out);
    fout << m_result.x << " " << m_result.y << " " << m_result.NumIneq1 << " " << m_result.NumIneq2 << " " << "\n";
    fout.close();
}

void Test::saveResultData()
{
    std::ofstream fout;
    std::string filename(m_filename);
    filename.append(".result");
    fout.open(filename.c_str(), std::ios_base::out);
    fout << m_result.x << " " << m_result.y << " " << m_result.NumIneq1 << " " << m_result.NumIneq2 << " " << "\n";
    fout.close();
}

Point Test::readExamData()
{
    std::ifstream fin;
    std::string filename(m_filename);
    filename.append(".exam");
    fin.open(filename.c_str(), std::ios_base::in);
    Point exam;
    char buff[50];
    fin >> buff;
    exam.x = std::strtod(buff, NULL);
    fin >> buff;
    exam.y = strtod(buff, NULL);
    fin >> buff;
    exam.NumIneq1 = atoi(buff);
    fin >> buff;
    exam.NumIneq2 = atoi(buff);
    fin.close();
    return exam;
}

void Test::saveTestData(std::string filename, const Qfunc& Q, const std::vector<Inequality>& aInequality)
{
    std::ofstream fout;
    filename.append(".test");
    fout.open(filename.c_str(), std::ios_base::out);
    fout << aInequality.size() << "\n";
    fout << Q.a << " " << Q.b << " " << Q.c << " " << "\n";
    for(const auto& in : aInequality)
        fout << in.a << " " << in.b << " " << in.c << " " << "\n";
    fout.close();
}

void Test::readTestData(std::string filename, Qfunc& Q, std::vector<Inequality>& aInequality)
{
    std::ifstream fin;
    fin.open(filename.c_str(), std::ios_base::in);
    int n = 0;
    char buff[50];
    fin >> buff;
    n = atoi(buff);
    aInequality.resize(n);
    fin >> buff;
    Q.a = atof(buff);
    fin >> buff;
    Q.b = atof(buff);
    fin >> buff;
    Q.c = atof(buff);
    for(int i = 0; i < n; i++)
    {
        fin >> buff;
        aInequality[i].a = atof(buff);
        fin >> buff;
        aInequality[i].b = atof(buff);
        fin >> buff;
        aInequality[i].c = atof(buff);
    }
    fin.close();
}
}