#include "stdafx.h"
#include "Meggido.h"

namespace meggido
{
;

void CMeggido::algo()
{
    //printInequality(Q, aInequality);

    std::cout << "Нормировка" << std::endl;
    meggido::CMeggido::Norm(m_Q);
    //printInequality(Q, aInequality);

    std::cout << "Разделение на 3 класса" << std::endl;
    meggido::CMeggido::Divided();// разделение на 3 класса
    std::cout << "I+ Количество = " << m_IPlus.size() << std::endl;
    //printIndexInequality(aInequality, IPlus);
    //printInequality(Q, aInequality, IPlus);
    std::cout << "I-  Количество = " << m_IMinus.size() << std::endl;
    //printIndexInequality(aInequality, IMinus);
    //printInequality(Q, aInequality, IMinus);
    std::cout << "I0  Количество = " << m_IZero.size() << std::endl;
    //printIndexInequality(aInequality, IZero);
    //printInequality(Q, aInequality, IZero);



    std::cout << "Определяем область определения" << std::endl;
    m_IZero = meggido::CMeggido::FindsLimX();
    std::cout << m_U;

    std::cout << "Преобразуем IPlus" << std::endl;
    meggido::CMeggido::Transformation(m_IPlus);
    //printIndexInequality(aInequality, IPlus);
    //printInequality(Q, aInequality, IPlus);

    std::cout << "Удаляем ограничения из IPlus" << std::endl;
    meggido::CMeggido::DeleteParallelIneqPlus();
    /*printIndexInequality(aInequality, IPlus);
    printInequality(Q, aInequality, IPlus);*/

    std::cout << "I+ Количество = " << m_IPlus.size() << std::endl;

    std::cout << "Преобразуем IMinus" << std::endl;
    meggido::CMeggido::Transformation(m_IMinus);
    //printIndexInequality(aInequality, IMinus);
    //printInequality(Q, aInequality, IMinus);

    std::cout << "Удаляем ограничения из IMinus" << std::endl;
    meggido::CMeggido::DeleteParallelIneqMinus();
    /*printIndexInequality(aInequality, IMinus);
    printInequality(Q, aInequality, IMinus);*/

    std::cout << "I-  Количество = " << m_IMinus.size() << std::endl;

    std::cout << "Удаляем ограничения" << std::endl;
    meggido::CMeggido::DeleteIneq();
    /*printIndexInequality(aInequality, IPlus);
    printInequality(Q, aInequality, IPlus);
    printIndexInequality(aInequality, IMinus);
    printInequality(Q, aInequality, IMinus);*/
    if(m_IMinus.size() > 1)
        m_result = meggido::CMeggido::PointInterseption(m_IMinus, 0, 1);
    std::cout << m_result;
}

void CMeggido::printInequality(Qfunc& Q)
{
    if(m_aInequality.size() != 0)
    {
        if(m_aInequality.size() < m_printMaxN)
        {
            std::cout << Q;
            for(int i = 0; i < m_aInequality.size(); i++)
            {
                std::cout << m_aInequality[i];
            }
            std::cout << std::endl;
        }
    }
    else
        std::cout << "Ограничений такого вида нет" << std::endl;
}
void CMeggido::printInequality(Qfunc& Q, std::vector<int>& Index)
{
    if(Index.size() != 0)
    {
        if(m_aInequality.size() < m_printMaxN)
        {
            std::cout << Q;
            for(int i = 0; i < Index.size(); i++)
            {
                std::cout << m_aInequality[Index[i]];
            }
            std::cout << std::endl;
        }
    }
    else
        std::cout << "Ограничений такого вида нет" << std::endl;
}

void CMeggido::printIndexInequality(std::vector<int>& Index)
{
    if(m_aInequality.size() < m_printMaxN)
    {
        for(int i = 0; i < Index.size(); i++)
        {
            std::cout << Index[i] << " ";
        }
        std::cout << std::endl;
    }
}
void CMeggido::doExam()
{
    std::ifstream fin;
    std::string filename(m_filename);
    filename.append(".exam");
    fin.open(filename.c_str());
    if(fin.is_open())
    { 
        fin.close();
        const Point exam(readExamData());
        //if(!m_result.isEqual(exam))
        CMeggido::saveResultData();
    }
    else
        saveExamData();
}

void CMeggido::saveExamData()
{
    std::ofstream fout;
    std::string filename(m_filename);
    filename.append(".exam");
    fout.open(filename.c_str(), std::ios_base::out);
    fout << m_result.x << " " << m_result.y << " " << m_result.NumIneq1 << " " << m_result.NumIneq2 << " " << "\n";
    fout.close();
}

void CMeggido::saveResultData()
{
    std::ofstream fout;
    std::string filename(m_filename);
    filename.append(".result");
    fout.open(filename.c_str(), std::ios_base::out);
    fout << m_result.x << " " << m_result.y << " " << m_result.NumIneq1 << " " << m_result.NumIneq2 << " " << "\n";
    fout.close();
}

Point CMeggido::readExamData()
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
/*void printPoint(std::vector<Point>& m_aInequality)
{
    if(m_aInequality.size() < Nmax)
    {
        for(int i = 0; i < (m_aInequality.size()*(m_aInequality.size() - 1) / 2); i++)
        {
            std::cout << m_aInequality[i];
        }
        std::cout << std::endl;
    }
}*/

Point CMeggido::PointInterseption(std::vector<int>& Index, int i, int j)
{
    Point X;
    X.x = ((-m_aInequality[Index[i]].c)*m_aInequality[Index[j]].b - (-m_aInequality[Index[j]].c)*m_aInequality[Index[i]].b) / (m_aInequality[Index[i]].a*m_aInequality[Index[j]].b - m_aInequality[Index[j]].a*m_aInequality[Index[i]].b);
    X.y = (m_aInequality[Index[i]].a*(-m_aInequality[Index[j]].c) - m_aInequality[Index[j]].a*(-m_aInequality[Index[i]].c)) / (m_aInequality[Index[i]].a*m_aInequality[Index[j]].b - m_aInequality[Index[j]].a*m_aInequality[Index[i]].b);
    X.NumIneq1 = Index[i];
    X.NumIneq2 = Index[j];
    return X;
}

void randIneq(Qfunc& Q, std::vector<Inequality>& aInequality)
{
    Q.a = 1 + std::rand() % 10000;
    Q.b = 1 + std::rand() % 10000;
    int i = 10;
//#pragma omp parallel shared (aInequality) private (i)
    {
        for(i = 10; i < aInequality.size(); i++)
        {
            aInequality[i].a = -500 + std::rand() % 1000;
            aInequality[i].b = -500 + std::rand() % 1000;
            aInequality[i].c = -500 + std::rand() % 1000;
        }
    }
}

void saveTestData(std::string filename, const Qfunc& Q, const std::vector<Inequality>& aInequality)
{
    std::ofstream fout;
    filename.append(".test");
    fout.open(filename.c_str(), std::ios_base::out);
    fout << aInequality.size() << "\n";
    fout << Q.a << " " << Q.b << " " << Q.c << " " << "\n";
    for(const auto& in: aInequality)
        fout << in.a << " " << in.b << " " << in.c << " " << "\n";
    fout.close();
}

void readTestData(std::string filename, Qfunc& Q, std::vector<Inequality>& aInequality)
{
    std::ifstream fin;
    filename.append(".test");
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

Point CMeggido::Mediana(std::vector<Point>& A, int q)
{
    Point Med;
    div_t d = div(q, 5);
#pragma omp parallel for
    for(int j = 0; j < d.quot; j++)
    {
        for(int i = j * 5; i < (j + 1) * 5; i++)
        {
            for(int k = 4; k > 0; k--)
            {
                if(A[k + j * 5].x < A[k + j * 5 - 1].x)
                    std::swap(A[k + j * 5], A[k + j * 5 - 1]);
                //cout << m_aInequality[k + j * 5] << endl;
            }
        }
        A[j] = A[j * 5 + 2];
    }
    div_t q1 = div(d.quot, 5);
    if(q1.quot != 0)
        Mediana(A, d.quot);
    else
    {
        for(int i = 0; i < d.quot; i++)
        {
            for(int k = d.quot - 1; k > 0; k--)
            {
                if(A[k].x < A[k - 1].x)
                    std::swap(A[k], A[k - 1]);
            }
            std::cout << A[i] << std::endl;
        }
        Med = A[div(d.quot, 2).quot];
        std::cout << "Mediana = " << Med << std::endl;
        return Med;
    }
}

void CMeggido::Norm(Qfunc& Q)
{
#pragma omp parallel for
    for(int i = 0; i < m_aInequality.size(); i++)
    {
        m_aInequality[i].b = m_aInequality[i].b / Q.b;
        m_aInequality[i].a = m_aInequality[i].a - m_aInequality[i].b*Q.a;
    }
    Q.b = Q.b / Q.b;
    Q.a = 0;
}

void CMeggido::Divided()
{
    if(!m_aInequality.empty())
    {
        for(int i = 0; i < m_aInequality.size(); i++)
        {
            if(m_aInequality[i].b > 0)
                m_IPlus.push_back(i);
            if(m_aInequality[i].b < 0)
                m_IMinus.push_back(i);
            if(m_aInequality[i].b == 0)
                m_IZero.push_back(i);
        }
    }
}

std::vector<int> CMeggido::FindsLimX()
{
    bool Error = false;
    if(!m_IZero.empty())
    {
        for(int i = 0; i < m_IZero.size(); i++)
        {
            double del = -(m_aInequality[m_IZero[i]].c / m_aInequality[m_IZero[i]].a);
            if(m_aInequality[m_IZero[i]].a < 0)
            {
                if(del < m_U.u2)
                {
                    m_U.u2 = del;
                }
            }
            else
            {
                if(del > m_U.u1)
                {
                    m_U.u1 = del;
                }
            }
        }
        /*if (m_U.u1 > m_U.u2)
        {
        m_IZero[0] = -INFINITY;
        m_IZero[1] = +INFINITY;
        m_U.u1 = -INFINITY;
        m_U.u2 = +INFINITY;
        }
        else
        {*/
        m_IZero[0] = m_U.u1;
        m_IZero[1] = m_U.u2;
        /*m_IZero[0] = -INFINITY;
        m_IZero[1] = +INFINITY;
        m_U.u1 = -INFINITY;
        m_U.u2 = +INFINITY;*/
        //}
    }
    return m_IZero;
}

void CMeggido::Transformation(std::vector<int>& Index)
{
    if(!Index.empty())
    {
#pragma omp parallel for
        for(int i = 0; i < Index.size(); i++)
        {
            m_aInequality[Index[i]].a = -(m_aInequality[Index[i]].a / m_aInequality[Index[i]].b);
            m_aInequality[Index[i]].c = -(m_aInequality[Index[i]].c / m_aInequality[Index[i]].b);
            m_aInequality[Index[i]].b = 1;
        }
    }
}

double CMeggido::FuncPlus(double x)
{
    double y;
    if(!m_IPlus.empty())
    {
        y = INFINITY;
        //#pragma omp parallel for
        for(int i = 0; i < m_IPlus.size(); i++)
        {
            //#pragma omp flush(y)
            if(y > m_aInequality[m_IPlus[i]].a*x + m_aInequality[m_IPlus[i]].c)
            {
                //#pragma omp critical
                {
                    y = m_aInequality[m_IPlus[i]].a*x + m_aInequality[m_IPlus[i]].c;
                }
            }
        }
    }
    return y;
}

double CMeggido::FuncMinus(double x)
{
    double y;
    if(!m_IMinus.empty())
    {
        y = -INFINITY;
        //#pragma omp parallel for
        for(int i = 0; i < m_IMinus.size(); i++)
        {
            //#pragma omp flush(y)
            if(y < m_aInequality[m_IMinus[i]].a*x + m_aInequality[m_IMinus[i]].c)
            {
                //#pragma omp critical
                {
                    y = m_aInequality[m_IMinus[i]].a*x + m_aInequality[m_IMinus[i]].c;
                }
            }
        }
    }
    return y;
}

void CMeggido::DeleteParallelIneqPlus()
{
    std::vector<int> IPlus2;
    std::vector<int> IPlus3;
    if(!m_IPlus.empty())
    {
        if(m_IPlus.size() & 1)
            IPlus2.push_back(m_IPlus[m_IPlus.size() - 1]);
        for(int i = 0; i < m_IPlus.size() - 1; i = i + 2)
        {
            if(m_aInequality[m_IPlus[i]].a == m_aInequality[m_IPlus[i + 1]].a)
            {
                if(m_aInequality[m_IPlus[i]].c > m_aInequality[m_IPlus[i + 1]].c)
                    IPlus2.push_back(m_IPlus[i + 1]);
                else
                    IPlus2.push_back(m_IPlus[i]);
            }
            else
            {
                Point X = PointInterseption(m_IPlus, i, i + 1);
                if(X.x < m_U.u1)
                {
                    if(m_aInequality[m_IPlus[i]].a > m_aInequality[m_IPlus[i + 1]].a)
                        IPlus2.push_back(m_IPlus[i + 1]);
                    else
                        IPlus2.push_back(m_IPlus[i]);
                }
                if(X.x > m_U.u2)
                {
                    if(m_aInequality[m_IPlus[i]].a > m_aInequality[m_IPlus[i + 1]].a)
                        IPlus2.push_back(m_IPlus[i]);
                    else
                        IPlus2.push_back(m_IPlus[i + 1]);
                }
                if((m_U.u1 <= X.x) && (X.x <= m_U.u2))
                {
                    IPlus3.push_back(m_IPlus[i]);
                    IPlus3.push_back(m_IPlus[i + 1]);
                }
            }
        }
        m_IPlus = IPlus2;
    }
}

void CMeggido::DeleteParallelIneqMinus()
{
    std::vector<int> IMinus2;
    std::vector<int> IMinus3;
    if(!m_IMinus.empty())
    {
        if(m_IMinus.size() & 1)
            IMinus2.push_back(m_IMinus[m_IMinus.size() - 1]);
        for(int i = 0; i < m_IMinus.size() - 1; i = i + 2)
        {
            if(m_aInequality[m_IMinus[i]].a == m_aInequality[m_IMinus[i + 1]].a)
            {
                if(m_aInequality[m_IMinus[i]].c < m_aInequality[m_IMinus[i + 1]].c)
                    IMinus2.push_back(m_IMinus[i]);
                else
                    IMinus2.push_back(m_IMinus[i + 1]);
            }
            else
            {
                Point X = PointInterseption(m_IMinus, i, i + 1);
                if(X.x < m_U.u1)
                {
                    if(m_aInequality[m_IMinus[i]].a > m_aInequality[m_IMinus[i + 1]].a)
                        IMinus2.push_back(m_IMinus[i]);
                    else
                        IMinus2.push_back(m_IMinus[i + 1]);
                }
                if(X.x > m_U.u2)
                {
                    if(m_aInequality[m_IMinus[i]].a > m_aInequality[m_IMinus[i + 1]].a)
                        IMinus2.push_back(m_IMinus[i + 1]);
                    else
                        IMinus2.push_back(m_IMinus[i]);
                }
                if((m_U.u1 <= X.x) && (X.x <= m_U.u2))
                {
                    // cout << "xcvbnm" << endl;
                    IMinus3.push_back(m_IMinus[i]);
                    IMinus3.push_back(m_IMinus[i + 1]);
                }
            }
        }
        m_IMinus = IMinus2;
    }
}

void CMeggido::InterPointDel()
{
    std::vector<Point> P;
    if(!m_IPlus.empty())
    {
        for(int i = 0; i < m_IPlus.size() - 1; i = i + 2)
        {
            Point x(PointInterseption(m_IPlus, i, i + 1));
            P.push_back(x);
        }
    }
    if(!m_IMinus.empty())
    {
        for(int i = 0; i < m_IMinus.size() - 1; i = i + 2)
        {
            Point x(PointInterseption(m_IMinus, i, i + 1));
            P.push_back(x);
        }
    }
    if(!P.empty())
    {
        Point Med(Mediana(P, P.size()));
        double fp;
        fp = FuncPlus(Med.x);
        double fm;
        fm = FuncMinus(Med.x);
        std::cout << "fm = " << fm << " fp = " << fp << std::endl;
    }
}

void CMeggido::DeleteIneq()
{
    std::vector<int> IPlus2;
    std::vector<int> IPlus3;
    std::vector<int> IMinus2;
    std::vector<int> IMinus3;
#pragma omp parallel sections
    {
#pragma omp section
        {
            if(!m_IPlus.empty())
            {
                if(m_IPlus.size() & 1)
                    IPlus2.push_back(m_IPlus[m_IPlus.size() - 1]);
                for(int i = 0; i < m_IPlus.size() - 1; i = i + 2)
                {
                    if(m_aInequality[m_IPlus[i]].a == m_aInequality[m_IPlus[i + 1]].a)
                    {
                        if(m_aInequality[m_IPlus[i]].c > m_aInequality[m_IPlus[i + 1]].c)
                            IPlus2.push_back(m_IPlus[i + 1]);
                        else
                            IPlus2.push_back(m_IPlus[i]);
                    }
                    else
                    {
                        Point X = PointInterseption(m_IPlus, i, i + 1);
                        //cout << "u1 = "<< m_U.u1 << "  " << X << endl;
                        //cout << "u2 = "<< m_U.u2 << "  " << X << endl;
                        if(X.x < m_U.u1)
                        {
                            if(m_aInequality[m_IPlus[i]].a > m_aInequality[m_IPlus[i + 1]].a)
                                IPlus2.push_back(m_IPlus[i + 1]);
                            else
                                IPlus2.push_back(m_IPlus[i]);
                        }
                        if(X.x > m_U.u2)
                        {
                            if(m_aInequality[m_IPlus[i]].a > m_aInequality[m_IPlus[i + 1]].a)
                                IPlus2.push_back(m_IPlus[i]);
                            else
                                IPlus2.push_back(m_IPlus[i + 1]);
                        }
                        if((m_U.u1 <= X.x) && (X.x <= m_U.u2))
                        {
                            IPlus3.push_back(m_IPlus[i]);
                            IPlus3.push_back(m_IPlus[i + 1]);
                        }
                    }
                }
                m_IPlus.clear();
                m_IPlus = IPlus2;
                IPlus2.clear();
            }
        }
#pragma omp section
        {
            if(!m_IMinus.empty())
            {
                if(m_IMinus.size() & 1)
                    IMinus2.push_back(m_IMinus[m_IMinus.size() - 1]);
                for(int i = 0; i < m_IMinus.size() - 1; i = i + 2)
                {
                    if(m_aInequality[m_IMinus[i]].a == m_aInequality[m_IMinus[i + 1]].a)
                    {
                        if(m_aInequality[m_IMinus[i]].c < m_aInequality[m_IMinus[i + 1]].c)
                            IMinus2.push_back(m_IMinus[i]);
                        else
                            IMinus2.push_back(m_IMinus[i + 1]);
                    }
                    else
                    {
                        Point X = PointInterseption(m_IMinus, i, i + 1);
                        //cout << "u1 = " << m_U.u1 << "  " << X << endl;
                        //cout << "u2 = " << m_U.u2 << "  " << X << endl;
                        if(X.x < m_U.u1)
                        {
                            if(m_aInequality[m_IMinus[i]].a > m_aInequality[m_IMinus[i + 1]].a)
                                IMinus2.push_back(m_IMinus[i]);
                            else
                                IMinus2.push_back(m_IMinus[i + 1]);
                        }
                        if(X.x > m_U.u2)
                        {
                            if(m_aInequality[m_IMinus[i]].a > m_aInequality[m_IMinus[i + 1]].a)
                                IMinus2.push_back(m_IMinus[i + 1]);
                            else
                                IMinus2.push_back(m_IMinus[i]);
                        }
                        if((m_U.u1 <= X.x) && (X.x <= m_U.u2))
                        {
                            IMinus3.push_back(m_IMinus[i]);
                            IMinus3.push_back(m_IMinus[i + 1]);
                        }
                    }
                }
                m_IMinus.clear();
                m_IMinus = IMinus2;
                IMinus2.clear();
            }
        }
    }
#pragma omp barrier 
    /*printIndexInequality(m_aInequality, IPlus3);
    printInequality(Q, m_aInequality, IPlus3);
    printIndexInequality(m_aInequality, IMinus3);
    printInequality(Q, m_aInequality, IMinus3);*/
    InterPointDel();
}
}