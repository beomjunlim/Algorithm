#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int N;
int Map[22][22];
bool visited[22];
int answer = 1e9;

void combination(int start, int idx){
    if(idx==N/2){
        int team_a = 0;
        int team_b = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(visited[i]&&visited[j]){
                    team_a += Map[i][j];
                }
                if(!visited[i]&&!visited[j]){
                    team_b += Map[i][j];
                }
            }
        }
        answer = min(answer, abs(team_a-team_b));
        return;
    }

    for(int i=start; i<N; i++){
        if(visited[i])
            continue;
        visited[i] = true;
        combination(i+1, idx+1);
        visited[i] = false;
    }
}

int main(){
    cin>>N;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>Map[i][j];
        }
    }

    visited[0] = true; // 0번 팀원을 A팀에 무조건 합류 시킨다.

    combination(1,1);
    cout<<answer<<'\n';

    return 0;
}