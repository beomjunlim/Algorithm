#include<iostream>
using namespace std;

int N,K;
int answer = 0;
int arr[21];

void combination_repetition(int sum, int idx){
    if(idx==N){
        if(sum==K)
            answer += 1;
        return;
    }


    combination_repetition(sum, idx+1);
    combination_repetition(sum+arr[idx], idx+1);
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        answer = 0;
        cin>>N>>K;

        for(int i=0; i<N; i++){
            cin>>arr[i];
        }

        combination_repetition(0,0);
        cout<<"#"<<test_case<<" "<<answer<<'\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}