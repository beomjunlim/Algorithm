#include <iostream>
#include <algorithm>
using namespace std;

int ans[10];
int arr[10] = {3, 1, 2, 4, 7, 9, 10, 6, 8, 5};

void merge(int start, int end, int mid)
{
  int i = start;
  int j = mid + 1;
  int k = start;

  while (i <= mid && j <= end)
  {
    if (arr[i] < arr[j])
    {
      ans[k] = arr[i];
      i++;
      k++;
    }
    else
    {
      ans[k] = arr[j];
      j++;
      k++;
    }
  }
  while (i <= mid)
  {
    ans[k] = arr[i];
    i++;
    k++;
  }
  while (j <= end)
  {
    ans[k] = arr[j];
    j++;
    k++;
  }

  for (int i = start; i <= end; i++)
  {
    arr[i] = ans[i];
  }
}

void mergeSort(int start, int end)
{
  if (start >= end)
  {
    return;
  }
  else
  {
    int mid = (start + end) / 2;
    mergeSort(start, mid);
    mergeSort(mid + 1, end);
    merge(start, end, mid);
  }
}

int main()
{
  mergeSort(0, 9);
  for (int i = 0; i < 10; i++)
  {
    cout << arr[i] << " ";
  }
}