#include<iostream>
#include<algorithm>
using namespace std;

int N;
int numbers[12];
int operators[4];
int arr[12] = {0};
int max_ans = -1e9;
int min_ans = 1e9;
// + - x /
/*
ee
*/


void permutation(int depth){
    if(depth==N-1){
        int idx = 0;
        int left_num = numbers[idx];
        idx += 1;
        for(int i=0; i<depth; i++){
            if(arr[i]==0){
                left_num += numbers[idx];
            }
            else if(arr[i]==1){
                left_num -= numbers[idx];
            }
            else if(arr[i]==2){
                left_num *= numbers[idx];
            }
            else if(arr[i]==3){
                left_num /= numbers[idx];
            }
            idx +=1;
        }
        max_ans = max(max_ans, left_num);
        min_ans = min(min_ans, left_num);
        return;
    }

    for(int i=0; i<4; i++){
        if(operators[i]>0){
            operators[i]--;
            arr[depth] = i;
            permutation(depth+1);
            operators[i]++;
        }
    }
}


int main(){
    cin>>N;

    for(int i=0; i<N; i++){
        cin>>numbers[i];
    }

    for(int i=0; i<4; i++){
        cin>>operators[i];
    }

    permutation(0);

    cout<<max_ans<<'\n';
    cout<<min_ans<<'\n';

    return 0;
}