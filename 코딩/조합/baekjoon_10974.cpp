#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int n;
  cin >> n;

  vector<int> arr;

  for (int i = 1; i <= n; i++)
  {
    arr.push_back(i);
  }

  do
  {
    for (int i : arr)
      cout << i << " ";
    cout << '\n';
  } while (next_permutation(arr.begin(), arr.end()));
  return 0;
}

// int N;
// bool visited[10];
// int arr[10];

// void permutation(int n)
// {
//   if (n == N + 1)
//   {
//     for (int i = 1; i <= N; i++)
//     {
//       cout << arr[i] << " ";
//     }
//     cout << '\n';
//     return;
//   }

//   for (int i = 1; i <= N; i++)
//   {
//     if (!visited[i])
//     {
//       visited[i] = true;
//       arr[n] = i;
//       permutation(n + 1);
//       visited[i] = false;
//     }
//   }
// }

// int main()
// {
//   cin >> N;

//   permutation(1);
//   return 0;
// }