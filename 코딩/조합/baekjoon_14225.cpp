#include<iostream>
using namespace std;

int N;
int arr[21];
bool visited[21];
bool answer[21*100000 + 1];

int ans = 1;

void subsets(int idx){
    if(idx==N){
        int sum = 0;
        for(int i=0; i<N; i++){
            if(visited[i])
                sum += arr[i];
        }
        answer[sum] = true;
        return;
    }

    visited[idx] = true;
    subsets(idx+1);

    visited[idx] = false;
    subsets(idx+1);
    
}

int main(){
    cin>>N;
    for(int i=0; i<N; i++)
        cin>>arr[i];

    subsets(0);

    for(int i=1; i<=21*100000 + 1; i++){
        if(!answer[i]){
            cout<<i<<'\n';
            break;
        }
    }
    
    return 0;
}