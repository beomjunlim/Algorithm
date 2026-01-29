#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX 1001

string arr[MAX];

int main()
{
  string s;
  string temp;
  cin >> s;

  for (int i = 0; i < s.length(); i++)
  {
    temp = s.substr(i, s.length() - i);
    arr[i] = temp;
  }

  sort(arr, arr + s.length());

  for (int i = 0; i < s.length(); i++)
  {
    cout << arr[i] << '\n';
  }
}