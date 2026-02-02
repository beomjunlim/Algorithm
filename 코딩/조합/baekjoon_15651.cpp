#include<iostream>
using namespace std;

int N,M;
int arr[10];

void permutation_repetition(int idx){
    if(idx==M){
        for(int i=0; i<idx; i++){
            cout<<arr[i]<<" ";
        }
        cout<<'\n';
        return;
    }

    for(int i=1; i<=N; i++){
        arr[idx] = i;
        permutation_repetition(idx+1);
    }
}

int main(){
    cin>>N>>M;
    permutation_repetition(0);
    return 0;
}