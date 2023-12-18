#include <iostream>
#include <queue>
using namespace std;

#define MAX 101

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, k, l;
  queue<pair<int, int>> snake;
  queue<pair<int, char>> qDir;
  int arr[MAX][MAX] = {
      0,
  };

  cin >> n >> k;

  for (int i = 0; i < k; i++)
  {
    int a, b;
    cin >> a >> b;
    arr[a][b] = 1;
  }

  cin >> l;

  for (int i = 0; i < l; i++)
  {
    int t;
    char d;
    cin >> t >> d;
    qDir.push(make_pair(t, d));
  }

  int dx[] = {0, 1, 0, -1}; // 오 아 왼 위
  int dy[] = {1, 0, -1, 0};
  int dir = 0;

  int x = 1, y = 1;
  snake.push(make_pair(x, y));
  arr[x][y] = 2;

  y += 1;
  int cnt = 1;

  while (1)
  {
    if (x > n || y > n || x < 1 || y < 1 || arr[x][y] == 2)
      break;

    if (!qDir.empty())
    {
      if (cnt == qDir.front().first)
      {
        if (qDir.front().second == 'L')
        {
          dir = (dir + 3) % 4;
        }
        else if (qDir.front().second == 'D')
        {
          dir = (dir + 1) % 4;
        }
        qDir.pop();
      }
    }

    if (arr[x][y] == 1)
    {
      snake.push(make_pair(x, y));
    }

    if (arr[x][y] == 0)
    {
      snake.push(make_pair(x, y));
      arr[snake.front().first][snake.front().second] = 0;
      snake.pop();
    }
    arr[x][y] = 2;
    x += dx[dir];
    y += dy[dir];
    cnt++;
  }
  cout << cnt << '\n';
}