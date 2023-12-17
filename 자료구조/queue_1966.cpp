#include <iostream>
#include <queue>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  while (n > 0)
  {
    queue<pair<int, int>> q;
    priority_queue<int> pq;

    int a, b;
    cin >> a >> b;
    int cnt = 0;

    for (int i = 0; i < a; i++)
    {
      int num;
      cin >> num;
      q.push({i, num});
      pq.push(num);
    }

    while (!q.empty())
    {
      int idx = q.front().first;
      int val = q.front().second;
      q.pop();

      if (pq.top() == val)
      {
        pq.pop();
        cnt++;

        if (idx == b)
        {
          cout << cnt << '\n';
          break;
        }
      }
      else
      {
        q.push({idx, val});
      }
    }
    n--;
  }
}