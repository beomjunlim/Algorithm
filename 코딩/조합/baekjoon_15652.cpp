#include<iostream>
using namespace std;

int N,M;
int arr[10];

void combination_repetition(int start, int idx){
    if(idx==M){
        for(int i=0; i<idx; i++){
            cout<<arr[i]<<" ";
        }
        cout<<'\n';
        return;
    }

    for(int i=start; i<=N; i++){
        arr[idx] = i;
        combination_repetition(i, idx+1);
    }
}
int main(){
    cin>>N>>M;
    combination_repetition(1,0);

    return 0;
}