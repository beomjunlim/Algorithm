#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 2000000

int arr_a[MAX];
int arr_b[MAX];
int arr[MAX];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++)
  {
    cin >> arr_a[i];
  }

  for (int i = 0; i < m; i++)
  {
    cin >> arr_b[i];
  }

  sort(arr_a, arr_a + n);
  sort(arr_b, arr_b + m);

  int cnt = 0;
  int idx_a = 0;
  int idx_b = 0;

  while (idx_a < n && idx_b < m)
  {
    if (arr_a[idx_a] < arr_b[idx_b])
    {
      arr[cnt] = arr_a[idx_a];
      cnt++;
      idx_a++;
    }
    else
    {
      arr[cnt] = arr_b[idx_b];
      cnt++;
      idx_b++;
    }
  }

  while (idx_a < n)
  {
    arr[cnt] = arr_a[idx_a];
    cnt++;
    idx_a++;
  }

  while (idx_b < m)
  {
    arr[cnt] = arr_b[idx_b];
    cnt++;
    idx_b++;
  }

  for (int i = 0; i < n + m; i++)
  {
    cout << arr[i] << " ";
  }
  cout << '\n';
}