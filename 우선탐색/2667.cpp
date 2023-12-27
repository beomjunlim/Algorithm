#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

#define MAX 26

int n;
int graph[MAX][MAX] = {0, };
bool visited[MAX][MAX] = {false, };
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<n;
}

int bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push(make_pair(x,y));
    visited[x][y] = true;
    int count=1;

    while(!q.empty()){
        int current_x = q.front().first;
        int current_y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int next_x = current_x + dx[i];
            int next_y = current_y + dy[i];
            if(InRange(next_x, next_y) && graph[next_x][next_y]==1 && !visited[next_x][next_y]){
                count++;
                visited[next_x][next_y] = true;
                q.push(make_pair(next_x, next_y));
            }
        }
    }
    return count;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> v;
    cin>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            char num;
            cin>>num;
            graph[i][j] = num -'0';
        }
    }

    int cnt = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(graph[i][j]==1 && !visited[i][j]){
                cnt++;
                v.push_back(bfs(i, j));
            }
        }
    }

    sort(v.begin(), v.end());
    cout<<cnt<<'\n';

    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<'\n';
    }
}