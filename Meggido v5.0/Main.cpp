#include "stdafx.h"
#include <ctime>
#include "Meggido.h"


int main()
{
    std::srand(time(NULL));
    setlocale(LC_ALL, "Russian");
    double t_end;
    double t_start;
    int n = 0;
    do
    {
        std::cout << "n = ";
        std::cin >> n;
        std::cout << std::endl;
    } while(n > 10000001);

    std::vector<Inequality> aInequality(n);

    aInequality[0].a = 1; aInequality[0].b = 0; aInequality[0].c = 3; aInequality[0].z = false;
    aInequality[1].a = -1; aInequality[1].b = 0; aInequality[1].c = 3; aInequality[1].z = false;

    aInequality[2].a = -1; aInequality[2].b = 1; aInequality[2].c = -5; aInequality[2].z = false;
    aInequality[3].a = -0.33; aInequality[3].b = 1; aInequality[3].c = -2; aInequality[3].z = false;

    aInequality[4].a = -0.33; aInequality[4].b = -1; aInequality[4].c = -2; aInequality[4].z = false;
    aInequality[5].a = -1; aInequality[5].b = -1; aInequality[5].c = -5; aInequality[5].z = false;

    aInequality[6].a = 0.33; aInequality[6].b = 1; aInequality[6].c = -2; aInequality[6].z = false;
    aInequality[7].a = 1; aInequality[7].b = 1; aInequality[7].c = -5; aInequality[7].z = false;

    aInequality[8].a = 1; aInequality[8].b = -1; aInequality[8].c = -5; aInequality[8].z = false;
    aInequality[9].a = 0.33; aInequality[9].b = -1; aInequality[9].c = -2; aInequality[9].z = false;

    Qfunc Q;
    Q.a = 4; Q.b = 5; Q.c = 0;
    meggido::randIneq(Q, aInequality);
    meggido::saveTestData(Q, aInequality);
    meggido::CMeggido meggidoAlgo(Q, aInequality);
    t_start = omp_get_wtime();
    meggidoAlgo.algo();
    t_end = omp_get_wtime();
    std::cout << "time = " << t_end - t_start << std::endl;
    system("pause");
    return 0;
}
