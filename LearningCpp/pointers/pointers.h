#include <iostream>
#include <string>
#include <vector>

void pointers_vs_links()
{
  int x = 16;
  int* const px = &x;
  int& rx = x; // always const (rx can't ref to other vars)

  *px = 24;
  std::cout << x << std::endl;

  rx = 36;
  std::cout << x << std::endl;

  int y = 50;
  const int* const py = &y;
  const int& ry = y;

  y++;
  // ry++;

  /*
  int y = 75;
  // px = &y;
  *px = 100;

  // rx ??? y; //
  rx = 100; // *px = 100;
  */
}

void new_delete()
{
  int* w = new int;
  std::cout << w << std::endl;
  std::cout << *w << std::endl;
  (*w) = 12;
  std::cout << w << std::endl;
  std::cout << *w << std::endl;
  delete w; // without brackets

  // undefined behaviour (UB)
  // std::cout << w << std::endl;  // old address
  // std::cout << *w << std::endl; // data on this address

  // w = nullptr; // w = NULL; // w = 0;
  // std::cout << w << std::endl;
  // std::cout << *w << std::endl;
  
  /*
  w = new int;
  std::cout << w << std::endl;
  std::cout << *w << std::endl;
  (*w) = 18;
  std::cout << w << std::endl;
  std::cout << *w << std::endl;
  */
}

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

int old_main_2()
{
  int a = 10;
  int b = 40;

  // type w;
  // type* pw = &w;
  // pw++; // increase pw not with 1 but with sizeof(type)

  int x[10];
  int* first = &x[0];
  int* end = &x[10];

  for (int i = 0; i < 10; ++i)
    std::cin >> x[i];

  for (int* ptr = first; ptr != end; ++ptr)
    std::cin >> (*ptr);

  std::vector<int> vx(10);

  for (int i = 0; i < 10; ++i)
    std::cin >> vx[i];

  for (int& item : vx)
    std::cin >> item;
    
  return 0;
}
