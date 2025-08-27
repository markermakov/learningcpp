#include <iostream>
#include <string>
#include <algorithm>

void __my_main__1();

struct StudentData
{
    std::string name;
    double score;

    static bool compare(const StudentData& a, const StudentData& b)
    {
        return a.score < b.score;
    }
}; // semicolon!!!


void __my_main__2();
