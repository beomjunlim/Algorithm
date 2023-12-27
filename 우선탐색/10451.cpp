#include<iostream>
#include<vector>
using namespace std;

#define MAX 1001

int graph[MAX][MAX] = {0, };
bool visited[MAX] = {false, };

void clear(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            graph[i][j] = 0;
        }
        visited[i] = false;
    }
}

void dfs(int v, int n){
    visited[v] = true;

    for(int i=1; i<=n; i++){
        if(!visited[i] && graph[v][i]==1){
            dfs(i,n);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while(t>0){
        int n;
        int cnt=0;
        cin>>n;
        

        for(int i=1; i<=n; i++){
            int a;
            cin>>a;
            graph[i][a]=1;
            graph[a][i]=1;
        }

        for(int i=1; i<=n; i++){
            if(!visited[i]){
                cnt++;
                dfs(i, n);
            }
        }
        cout<<cnt<<'\n';
        clear(n);
        t--;
    }
}