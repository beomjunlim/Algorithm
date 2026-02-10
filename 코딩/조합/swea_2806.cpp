#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

int N;
bool visited[9];
int answer = 0;
int arr[10];

bool canGo(int col, int row){
    if(visited[row])
        return false;
    for(int i=0; i<col; i++){
        if(abs(col-i)==abs(row-arr[i]))
            return false;
    }
    return true;
}

void permutation(int idx){
    if(idx==N){
        answer += 1;
        return;
    }

    for(int i=0; i<N; i++){
        if(canGo(idx, i)){
            visited[i] = true;
            arr[idx] = i;
            permutation(idx+1);
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
        answer = 0;
        memset(visited, false, sizeof(visited));
        cin>>N;
        permutation(0);
        cout<<"#"<<test_case<<" "<<answer<<'\n';

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}