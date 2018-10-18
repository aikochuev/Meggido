#pragma once
#include <vector>
#include "Inequality.h"
namespace test
{
    class Test
    {
    public:
        Test(const std::string& filepath) :m_filename(filepath) {}
        static void saveTestData(std::string filename, const Qfunc& Q, const std::vector<Inequality>& aInequality);
        void runTest();
    private:
        void doExam();
        void saveExamData();
        void saveResultData();
        Point readExamData();
        void readTestData(std::string filename, Qfunc& Q, std::vector<Inequality>& aInequality);
        Point m_result;
        std::string m_filename;
    };
}