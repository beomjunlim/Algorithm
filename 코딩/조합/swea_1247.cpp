#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

pair<int,int> graph[13];
int N;
int answer = 1e9;
bool visited[13];


void permutation(int x, int y, int sum, int idx){
    if(sum>=answer)
        return;
	if(idx==N){
        sum += (abs(x-graph[1].first) + abs(y-graph[1].second));
        answer = min(sum, answer);
        return;
    }

    for(int i=2; i<N+2; i++){
        if(!visited[i]){
            visited[i] = true;
            int nx = graph[i].first;
            int ny = graph[i].second;
            permutation(nx, ny, sum + abs(x-nx) + abs(y-ny), idx+1);
            visited[i] = false;
        }
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin>>N;
        answer = 1e9;
        memset(visited, false, sizeof(visited));
        for(int i=0; i<N+2; i++){
        	int x,y;
            cin>>x>>y;
            graph[i] = {x,y};
        }

        permutation(graph[0].first, graph[0].second, 0, 0);
        cout<<"#"<<test_case<<" "<<answer<<'\n';
	}
	return 0;
}