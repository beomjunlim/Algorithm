#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  int arr[10] = {3, 1, 2, 4, 7, 9, 10, 6, 8, 5};

  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10 - i - 1; j++)
    {
      if (arr[j + 1] < arr[j])
        swap(arr[j + 1], arr[j]);
    }
  }
  for (int i = 0; i < 10; i++)
  {
    cout << arr[i] << " ";
  }
}