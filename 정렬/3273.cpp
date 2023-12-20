#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 1000001

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

  int x;
  cin >> x;

  int left = 0;
  int right = n - 1;
  int ans = 0;

  while (left < right)
  {
    if (arr[left] + arr[right] == x)
    {
      ans++;
      right--;
    }
    else if (arr[left] + arr[right] > x)
    {
      right--;
    }
    else if (arr[left] + arr[right] < x)
    {
      left++;
    }
  }
  cout << ans;
}