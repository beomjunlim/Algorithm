#include<iostream>
using namespace std;

#define MAX 101

int graph[MAX][MAX];
bool visited[MAX] = {false, };
int cnt = 0;
int n;

void dfs(int num){
    cnt++;
    visited[num] = true;

    for(int i=1; i<=n; i++){
        if(graph[num][i]==1 && visited[i]== false){
            dfs(i);
        }
    }    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin>>n;
    int m;
    cin>>m;

    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        graph[a][b] = 1;
    }

    dfs(1);

    cout<<cnt-1<<'\n';
}