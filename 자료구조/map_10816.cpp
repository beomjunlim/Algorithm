#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  unordered_map<int, int> cnt;
  int n, m;
  int card;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> card;
    cnt[card]++;
  }

  cin >> m;
  for (int i = 0; i < m; i++)
  {
    cin >> card;
    cout << cnt[card] << " ";
  }
}