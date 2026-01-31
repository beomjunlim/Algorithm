#include<iostream>
using namespace std;

int N,M;
int arr[10];
int ans[10];

void combination(int start, int idx){
    if(idx==M){
        for(int i=0; i<M; i++){
            cout<<ans[i]<<" ";
        }
        cout<<'\n';
        return;
    }

    for(int i=start; i<N; i++){
        ans[idx] = arr[i];
        combination(i+1, idx+1);
    }
}


int main(){
    cin>>N>>M;

    for(int i=0; i<N; i++){
        arr[i] = i+1;
    }

    combination(0,0);
    return 0;
}