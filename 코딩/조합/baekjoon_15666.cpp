#include<iostream>
#include<algorithm>
using namespace std;

int N,M;
int numbers[10];
int arr[10];

void combination_repetition(int start, int idx){
    if(idx==M){
        for(int i=0; i<idx; i++){
            cout<<arr[i]<<" ";
        }
        cout<<'\n';
        return;
    }

    int last_num = -1;
    for(int i=start; i<N; i++){
        if(numbers[i]!=last_num){
            arr[idx] = numbers[i];
            last_num = numbers[i];
            combination_repetition(i, idx+1);
        }
    }
}
int main(){
    cin>>N>>M;

    for(int i=0; i<N; i++){
        cin>>numbers[i];
    }

    sort(numbers, numbers+N);
    combination_repetition(0,0);

    return 0;
}