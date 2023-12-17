#include <iostream>
#include <stack>
using namespace std;

#define MAX 500001

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  stack<int> h;
  stack<int> num;

  int n;
  int arr[MAX];
  cin >> n;

  for (int i = 1; i <= n; i++)
  {
    cin >> arr[i];
  }

  int answer[MAX];

  answer[1] = 0;
  h.push(arr[1]);
  num.push(1);

  for (int i = 2; i <= n; i++)
  {
    while (!h.empty() && arr[i] > h.top())
    {
      h.pop();
      num.pop();
    }
    if (h.empty())
    {
      answer[i] = 0;
    }
    else
    {
      answer[i] = num.top();
    }
    h.push(arr[i]);
    num.push(i);
  }

  for (int i = 1; i <= n; i++)
  {
    cout << answer[i] << " ";
  }
  cout << '\n';
}