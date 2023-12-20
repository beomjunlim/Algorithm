#include <iostream>
using namespace std;

int arr[11] = {3, 1, 2, 4, 7, 9, 10, 6, 8, 5, 11};

void insertion_sort(int first, int end, int gap)
{
  int i, j, key;
  for (i = first + gap; i <= end; i = i + gap)
  {
    key = arr[i];

    for (j = i - gap; j >= first && arr[j] > key; j = j - gap)
    {
      arr[j + gap] = arr[j];
    }
    arr[j + gap] = key;
  }
}

void shell_sort(int n)
{
  int gap, i;
  for (gap = n / 2; gap > 0; gap = gap / 2)
  {
    if (gap % 2 == 0)
      gap++;
    for (i = 0; i < gap; i++)
    {
      insertion_sort(i, n - 1, gap);
    }
  }
}

int main()
{
  shell_sort(11);

  for (int i = 0; i < 11; i++)
  {
    cout << arr[i] << " ";
  }
}