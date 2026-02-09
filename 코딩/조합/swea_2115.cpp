#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int Map[11][11];
int people[2];
int M,N,C;
int honey;
int answer = 0;

void subsets(int idx, int row, int col, int sum, int capacity){
    if(idx==M){
        honey = max(honey, sum);
        return;
    }

    subsets(idx+1,row,col+1, sum, capacity);
    int next_capacity = capacity - Map[row][col];
    if(next_capacity>=0)
        subsets(idx+1,row,col+1, sum + pow(Map[row][col],2), next_capacity);
}

void get_honey(int first, int second){
    int f_row = first / N;
    int f_col = first % N;
    int s_row = second / N;
    int s_col = second % N;

    if(abs(f_col-s_col)<M&&f_row==s_row)
        return;

    honey = 0;
    subsets(0,f_row, f_col, 0, C);
    int first_honey = honey;
    honey = 0;
    subsets(0,s_row, s_col, 0, C);
    answer = max(answer, first_honey + honey);
}

void select_start(int start, int idx){
    if(idx==2){
        get_honey(people[0], people[1]);
        return;
    }

    for(int i=start; i<pow(N,2); i++){
        if(i%N+M>N)
            continue;

        people[idx] = i;
        select_start(i+1, idx+1);
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

    cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin>>N>>M>>C;
        answer = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin>>Map[i][j];
            }
        }
        select_start(0,0);
        cout<<"#"<<test_case<<" "<<answer<<'\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}