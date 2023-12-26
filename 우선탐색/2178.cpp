#include<iostream>
#include<queue>
using namespace std;

#define MAX 101

int n,m;
int graph[MAX][MAX];
int cnt[MAX][MAX] = {0, };
bool visited[MAX][MAX] = {false, };


void bfs(int x, int y){
    visited[x][y] = true;
    queue<pair<int,int>> q;
    q.push(make_pair(x, y));
    cnt[x][y] = 1;

    while(!q.empty()){
        int node_x = q.front().first;
        int node_y = q.front().second;
        q.pop();

        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};

        for(int i=0; i<4; i++){
            int nx = node_x + dx[i];
            int ny = node_y + dy[i];

            if(graph[nx][ny]==1 && !visited[nx][ny]){
                visited[nx][ny] = true;
                q.push(make_pair(nx, ny));
                cnt[nx][ny] = cnt[node_x][node_y] + 1;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin>>n>>m;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            char num;
            cin>>num;
            graph[i][j] = num -'0';
        }
    }

    bfs(1, 1);
    cout<<cnt[n][m];
}   