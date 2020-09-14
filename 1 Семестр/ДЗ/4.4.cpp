#include <iostream>

using namespace std;

int main()
{
  for (int i = 0; i < 13; ++i)
  {
      if (i >= 1 && i <= 6)
      {
          for (int j = 0; j < 8; ++j)
              cout << "*";
          for (int j = 8; j < 49; ++j)
              cout << "_";
      }
      else
          for (int j = 0; j < 49; ++j)
              cout << "_";
      cout << endl;
  }
  return 0;
}
