#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  map<string, int> m;
  int n;
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    string s;
    cin >> s;
    m[s]++;
  }

  int maxNum = 0;
  string answer;

  for (auto i : m)
  {
    maxNum = max(maxNum, i.second);
  }

  for (auto i : m)
  {
    if (i.second == maxNum)
    {
      cout << i.first;
      return 0;
    }
  }
}