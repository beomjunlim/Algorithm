#include<iostream>
#include<stack>
using namespace std;

#define MAX 101

int graph[MAX][MAX] = {0, };
bool visited[MAX] = {false, };
int n, m, a, b;
int cnt = 0;

int dfs(int num){
    stack<int> s;
    s.push(num);
    visited[num] = true;
    int cnt = -1;

    while(!s.empty()){
        int node = s.top();
        s.pop();

        for(int i=1; i<=n; i++){
            if(graph[node][i]== 1 && visited[i]== false){
                if(i==b){
                    cnt = s.size() + 1;
                    return cnt;
                }
                visited[i] = true;
                s.push(node);
                s.push(i);
                break;
            }
        }
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    cin>>a>>b;
    cin>>m;

    for(int i=0; i<m; i++){
        int x,y;
        cin>>x>>y;
        graph[x][y] = 1;
        graph[y][x] = 1;
    }

    cout<<dfs(a);

}