#include<iostream>
#include<algorithm>
using namespace std;

int N;
int oper[4];
int num[13];
int big_val = -1e9;
int small_val = 1e9;

void permutation_repetition(int idx, int sum){
    if(idx==N){
        big_val = max(big_val, sum);
        small_val = min(small_val, sum);
        return;
    }
    
    for(int i=0; i<4; i++){
        if(oper[i]>0){
            oper[i] -= 1;
            int next = sum;
            if(i==0)
                next += num[idx];
            else if(i==1)
                next -= num[idx];
            else if(i==2)
                next *= num[idx];
            else if(i==3)
                next /= num[idx];
            permutation_repetition(idx+1, next);
            oper[i] += 1;
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
        big_val = -1e9;
        small_val = 1e9;
        for(int i=0; i<4; i++){
            cin>>oper[i];
        }

        for(int i=0; i<N; i++){
            cin>>num[i];
        }

        permutation_repetition(1, num[0]);
        cout<<"#"<<test_case<<" "<<big_val - small_val<<'\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}