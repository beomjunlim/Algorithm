#include <iostream>
#include <queue>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  queue<int> q;
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    q.push(i);
  }

  while (q.size() != 1)
  {
    q.pop();
    int idx = q.front();
    q.pop();
    q.push(idx);
  }
  cout << q.front() << '\n';
}