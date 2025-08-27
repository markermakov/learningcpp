#include <iostream>
#include <string>
#include <vector>

void arrays()
{
  int a[10];

  const int n = 5;
  int b[n] = { 7, 14, 2, 3, 4 };

  int t;
  std::cin >> t;
  const int n2 = 10 + t;
  //int c[n2];
  int* c = new int[n2];
  std::vector<int> vc(n2);

  std::cout << b[5] << std::endl;

  int k;
  std::cin >> k;
  for (int i = 0; i < k; ++i)
    std::cout << b[i] << ' ';
  delete[] c;
}

// arrays + pointers
// arrays in array
void new_delete_2()
{
  int* w = new int;
  std::cout << w << std::endl;
  std::cout << *w << std::endl;
  std::cout << &w << std::endl;
  (*w) = 12;
  std::cout << w << std::endl;
  std::cout << *w << std::endl;
  std::cout << &w << std::endl;

  int** q = &w;

  delete w; // without brackets

  // int a[4][8];

  int** a = new int* [4];
  for (int i = 0; i < 4; ++i)
    a[i] = new int[8];

  for (int i = 0; i < 4; ++i)
    delete[] a[i];
  delete[] a;

  std::vector<std::vector<int>> va(4);
  for (int i = 0; i < va.size(); ++i)
    va[i].resize(8);
  va[3][6] = 123;

  int* ma = new int[4 * 8];
  ma[3 * 8 + 6] = 123; // a[3][6] = 123;
  delete[] ma;

  void* vp = ma;
  ma = (int*)vp;

  float* fp = (float*)ma; // not recommended
}
