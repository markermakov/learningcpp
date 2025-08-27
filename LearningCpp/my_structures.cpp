#include <iostream>
#include <string>
#include <algorithm>

#include "structures.h"

void __my_main__1()
{
  int n;
  std::cin >> n;

  std::string* names = new std::string[n];
  double* scores = new double[n];

  for (int i = 0; i < n; ++i)
    std::cin >> names[i] >> scores[i];

  for (int i = 0; i < n; ++i)
  {
    int index_of_min = i;
    for (int j = i + 1; j < n; ++j)
      if (scores[j] < scores[index_of_min])
        index_of_min = j;

    std::string tname = names[i];
    names[i] = names[index_of_min];
    names[index_of_min] = tname;

    double tscore = scores[i];
    scores[i] = scores[index_of_min];
    scores[index_of_min] = tscore;
  }

  for (int i = 0; i < n; ++i)
    std::cout << names[i] << ' ' << scores[i] << std::endl;
}

bool compare (const StudentData& a, const StudentData& b)
{
  return a.score < b.score;
}

void __my_main__2()
{
  int n;
  std::cin >> n;

  StudentData* students = new StudentData[n];

  for (int i = 0; i < n; ++i)
    std::cin >> students[i].name >> students[i].score;

  std::sort(students, students + n, compare);

  for (int i = 0; i < n; ++i)
    std::cout << students[i].name << ' ' << students[i].score << std::endl;
}
