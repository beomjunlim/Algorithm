#include<iostream>
#include<stack>
#include<queue>
using namespace std;

#define MAX 1001

int graph[MAX][MAX]={0,};
bool visited[MAX];
int n,m,v;

void reset(){
    for(int i=1; i<=n; i++){
        visited[i]=0;
    }
}

void DFS(int num){
    visited[num] = true;
    cout<<num<<" ";

    for(int i=1; i<=n; i++){
        if(graph[num][i]==1&&visited[i]==0){
            DFS(i);
        }
    }
}

void BFS(int num){
    queue<int>q;
    q.push(num);
    visited[num] = true;
    cout<<num<<" ";

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(int i=1; i<=n; i++){
            if(graph[node][i]==1&&visited[i]==0){
                q.push(i);
                visited[i]= true;
                cout<<i<<" ";
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    queue<pair<int,int>>q;
    stack<pair<int, int>> s;
    cin>>n>>m>>v;

    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }
    
    reset();
    DFS(v);

    cout<<'\n';

    reset();
    BFS(v);

}