#include <iostream>
#include <string>
#include <vector>

void const_vars()
{
  int x = 5;
  const int y = 6;

  x = 12;
  // y = 8;

  int* px = &x;
  const int* py = &y;
  const int* cpx = &x;

  // (*py) += 15;

  x += 15;
  // (*cpx) += 15;

  int* const const_px = &x;
  (*const_px) += 10;

  // const_px = &y;

  const int* const const_cpy = &y;

  // (*const_cpy) += 10;
  // const_cpy = &x;
}

void modify_var_x_with_parameter_y_1(int* px, int y)
{
  (*px) = (*px) + 4 * y;
  y = y + 5; // it will be assigned but it doesn't affect external "y"
}

void modify_var_x_with_parameter_y_2(int* px, const int* py) // let it be not int but a very-big-class with a size = 10 KB
{
  (*px) = (*px) + 4 * (*py);
  // (*py) = (*py) + 5;
}

void modify_var_x_with_parameter_y_3(int& rx, const int& ry) // let it be not int but a very-big-class with a size = 10 KB
{
  rx = rx + 4 * ry;
  // ry = ry + 5;
}

int x; // global variable

// global
// stack (local vars)
// heap (dynamic vars)

int proc()
{
  char a[] = "First";
  char b[] = "Second";
  strcpy(a, "Third");

  for (int i = 0; a[i] != '\0'; ++i);

  std::string sa = "First";
  std::string sb = "Second";
  sa = "Third";
  std::string sc = sa + sb;
  auto sd = sb + sa;

  for (int i = 0; i < sa.length(); ++i);

  // std::unordered_map<std::string, std::vector<std::pair<int, int> > >::const_forward_iterator it = v.begin();
  // auto it = v.begin();

  int n;
  std::cin >> n;

  int* x = new int[n]; // проблема с исключениями решается через RAII

  for (int i = 0; i < n; ++i)
    std::cin >> x[i];

  if (n > 3 && x[3] == 7)
  {
    delete[] x;
    return 8;
  }

  delete[] x;
  return 5;

  std::vector<int> vx(n);

  if (n > 15)
  {
    vx[5] = 4;
    std::cout << vx[13];
  }
}

int old_main()
{
  proc();
  double y; // local variable // float, double, long double - float point numbers
  // bool b; // logical type
  // char c; // symbolic type
  // wchar_t; // unicode symbol

  char hw[14] = "Hello, world!";
  std::string s_hw = hw;

  // std::cout << x + y << std::endl;
  std::cout << hw << std::endl;
  
  std::cin >> x >> y;
  std::cout << x + y << " " << s_hw[1] << arr[2] << std::endl;

  return 0;
}
