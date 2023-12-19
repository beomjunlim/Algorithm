#include <iostream>
#include <algorithm>
using namespace std;

int ans[10];
int arr[10] = {3, 1, 2, 4, 7, 9, 10, 6, 8, 5};

int partition(int start, int end)
{
  int pivot = arr[start];
  int left = start + 1;
  int right = end;

  while (1)
  {
    while (left <= right && arr[left] <= pivot)
    {
      left++;
    }
    while (arr[right] >= pivot && right >= left)
    {
      right--;
    }
    if (right < left)
    {
      break;
    }
    else
    {
      swap(arr[left], arr[right]);
    }
  }
  swap(arr[start], arr[right]);
  return right;
}

void quickSort(int start, int end)
{
  if (start < end)
  {
    int pivotIndex = partition(start, end);
    quickSort(start, pivotIndex - 1);
    quickSort(pivotIndex + 1, end);
  }
}
int main()
{
  quickSort(0, 9);
  for (int i = 0; i < 10; i++)
  {
    cout << arr[i] << " ";
  }
}