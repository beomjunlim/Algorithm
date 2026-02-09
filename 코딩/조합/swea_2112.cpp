#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int D,W,K;
int film[14][21];
int temp[14][21];
int answer = 0;
int change[14];

bool check_col(int col){
    int pre_num = film[0][col];
    int sum = 1;
    
    if(change[0]==0)
        pre_num = 0;
    else if(change[0]==1)
        pre_num = 1;
    
    for(int i=1; i<D; i++){
        if(sum>=K)
            return true;
        int num = film[i][col];

        if(change[i]==0)
            num = 0;
        else if(change[i]==1)
            num = 1;

        if(num==pre_num)
            sum += 1;
        else
            sum = 1;
        pre_num = num;
    }

    if(sum>=K)
        return true;
    return false;
}

bool check(){
    for(int i=0; i<W; i++){
        if(!check_col(i))
            return false;
    }
    return true;
}
void generateSubsets(int idx, int count){
    if(count>=answer)
        return;
    if(check()){
        answer = min(answer, count);
        return;
    }

    if(idx==D)
        return;

    change[idx] = -1;
    generateSubsets(idx+1, count);
    change[idx] = 0;
    generateSubsets(idx+1, count+1);
    change[idx] = 1;
    generateSubsets(idx+1, count+1);
    change[idx] = -1;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin>>D>>W>>K;
        memset(change, -1, sizeof(change));
        answer = D;
        for(int i=0; i<D; i++){
            for(int j=0; j<W; j++){
                cin>>film[i][j];
            }
        }

        generateSubsets(0,0);
        cout<<"#"<<test_case<<" "<<answer<<'\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}