#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  int arr[10] = {3, 1, 2, 4, 7, 9, 10, 6, 8, 5};

  for (int i = 0; i < 10; i++)
  {
    int idx = i;
    for (int j = i + 1; j < 10; j++)
    {
      if (arr[j] < arr[idx])
        idx = j;
    }
    swap(arr[i], arr[idx]);
  }

  for (int i = 0; i < 10; i++)
  {
    cout << arr[i] << " ";
  }
}