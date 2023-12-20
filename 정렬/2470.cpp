#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

#define MAX 100001

int arr[MAX];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  sort(arr, arr + n);

  int left = 0;
  int right = n - 1;
  int ans = arr[left] + arr[right];
  int left_idx = left;
  int right_idx = right;

  while (left < right)
  {
    int temp = arr[left] + arr[right];
    if (abs(ans) > abs(temp))
    {
      ans = abs(temp);
      left_idx = left;
      right_idx = right;
      if (ans == 0)
        break;
    }

    if (temp < 0)
    {
      left++;
    }
    else
    {
      right--;
    }
  }
  cout << arr[left_idx] << " " << arr[right_idx] << '\n';
}