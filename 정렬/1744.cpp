#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 51

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  int ans = 0;
  vector<int> minus;
  vector<int> plus;
  int arr[MAX];
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  sort(arr, arr + n);

  for (int i = 0; i < n; i++)
  {
    if (arr[i] > 1)
    {
      plus.push_back(arr[i]);
    }
    else if (arr[i] == 1)
    {
      ans += arr[i];
    }
    else
    {
      minus.push_back(arr[i]);
      if (minus.size() == 2)
      {
        int a = minus.back();
        minus.pop_back();
        int b = minus.back();
        minus.pop_back();
        ans += a * b;
      }
    }
  }

  sort(plus.begin(), plus.end());

  while (!plus.empty())
  {
    int a = plus.back();
    plus.pop_back();
    if (!plus.empty())
    {
      int b = plus.back();
      plus.pop_back();
      ans += a * b;
    }
    else
    {
      ans += a;
    }
  }

  while (!minus.empty())
  {
    ans += minus.back();
    minus.pop_back();
  }
  cout << ans;
}