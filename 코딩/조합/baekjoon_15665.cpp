#include<iostream>
#include<algorithm>
using namespace std;

int N,M;
int numbers[10];
int ans[10];

void permutation_repetition(int idx){
    if(idx==M){
        for(int i=0; i<idx; i++){
            cout<<ans[i]<<" ";
        }
        cout<<'\n';
        return;
    }

    int last_val = -1;
    for(int i=0; i<N; i++){
        if(numbers[i]!=last_val){
            ans[idx] = numbers[i];
            last_val = numbers[i];
            permutation_repetition(idx+1);
        }
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