#include<iostream>
#include<algorithm>
using namespace std;

int N,S;
int answer;
int people[21];

void combination_repetition(int idx, int height){
    if(height<S){
        return;
    }
    if(idx==N){
        answer = min(answer, height - S);
        return;
    }
    
    if(height - people[idx]>=S)
        combination_repetition(idx+1, height - people[idx]);
    combination_repetition(idx+1, height);
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin>>N>>S;
        int sum = 0;
        for(int i=0; i<N; i++){
            cin>>people[i];
            sum += people[i];
        }
        answer = sum;
        combination_repetition(0, sum);


        cout<<"#"<<test_case<<" "<<answer<<'\n';

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}