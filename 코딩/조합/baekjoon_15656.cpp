#include<iostream>
#include<algorithm>
using namespace std;

int numbers[10];
int N,M;
int ans[10];

void permutation_repetition(int idx){
    if(idx==M){
        for(int i=0; i<M; i++){
            cout<<ans[i]<<" ";
        }
        cout<<'\n';
        return;
    }

    for(int i=0; i<N; i++){
        ans[idx] = numbers[i];
        permutation_repetition(idx+1);
    }
}

int main(){
    cin>>N>>M;

    for(int i=0; i<N; i++){
        cin>>numbers[i];
    }

    sort(numbers, numbers+N);
    permutation_repetition(0);
    return 0;
}