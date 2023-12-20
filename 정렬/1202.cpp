#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> m(n);
  vector<int> size(k);
  priority_queue<int> pq;

  for (int i = 0; i < n; i++)
  {
    cin >> m[i].first >> m[i].second;
  }

  for (int i = 0; i < k; i++)
  {
    cin >> size[i];
  }

  sort(m.begin(), m.end());
  sort(size.begin(), size.end());

  int index = 0;
  long long ans = 0;

  for (int i = 0; i < k; i++)
  {
    while (index < n && m[index].first <= size[i])
    {
      pq.push(m[index++].second);
    }
    if (!pq.empty())
    {
      ans += pq.top();
      pq.pop();
    }
  }

  cout << ans << '\n';
}