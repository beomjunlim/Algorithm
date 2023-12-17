#include <iostream>
#include <stack>
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
    stack<char> s;
    string str;
    string answer = "YES";
    cin >> str;

    for (int i = 0; i < str.length(); i++)
    {
      if (str[i] == '(')
      {
        s.push(str[i]);
      }
      else if (!s.empty() && str[i] == ')' && s.top() == '(')
      {
        s.pop();
      }
      else
      {
        answer = "NO";
        break;
      }
    }

    if (!s.empty())
    {
      answer = "NO";
    }

    cout << answer << '\n';
    n--;
  }
}