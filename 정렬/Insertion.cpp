#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  int arr[10] = {3, 1, 2, 4, 7, 9, 10, 6, 8, 5};

  for (int i = 0; i < 10; i++)
  {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && key < arr[j])
    {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
  for (int i = 0; i < 10; i++)
  {
    cout << arr[i] << " ";
  }
}