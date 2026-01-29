#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  cout << "next_permutation 이용" << endl;

  vector<int> num = {1, 2, 3};

  do
  {
    for (int i : num)
    {
      cout << i << " ";
    }
    cout << '\n';
  } while (next_permutation(num.begin(), num.end()));
  return 0;
}