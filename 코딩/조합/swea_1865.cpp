#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cmath>
using namespace std;

int N;
int arr[20][20];
bool visited[20];
double answer = 0;

void permutation(int idx, double sum){
    if(answer>sum)
        return;
    if(idx==N){
        answer = max(answer, sum);
        return;
    }

    for(int i=0; i<N; i++){
        if(!visited[i]){
            visited[i] = true;
            double next = (sum *arr[idx][i]) / 100;
            if(next>answer)
                permutation(idx+1, next);
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
        answer = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin>>arr[i][j];
            }
        }

        permutation(0,100);
        cout<<"#"<<test_case<<" "<<fixed<<setprecision(6)<<answer<<'\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}