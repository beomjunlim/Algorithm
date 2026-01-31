#include<iostream>
using namespace std;

int N, S;
int arr[21];
int ans[21];
int answer = 0;

void combination(int start, int idx, int count){
    if(idx==count){
        int sum = 0;
        for(int i=0; i<count; i++){
            sum += ans[i];
        }

        if(sum==S)
            answer += 1;
        return;
    }

    for(int i=start; i<N; i++){
        ans[idx] = arr[i];
        combination(i+1, idx+1, count);
    }
}

int main(){
    cin>>N>>S;

    for(int i=0; i<N; i++){
        cin>>arr[i];
    }

    for(int i=1; i<=N; i++){
        combination(0,0,i);
    }

    cout<<answer;
    return 0;
}