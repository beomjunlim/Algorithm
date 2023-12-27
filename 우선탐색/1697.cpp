#include<iostream>
#include<queue>
#include<vector>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,k;
    cin>>n>>k;
    queue<int> q;
    int arr[100001] = {0, };
    
    q.push(n);


    while(!q.empty()){
        int subin = q.front();
        q.pop();

        if(subin<0||subin>100000) continue;
        if(subin==k){
            cout<<arr[subin]<<'\n';
            break;
        }

        if(subin-1>=0 && arr[subin-1]==0){
            arr[subin-1] = arr[subin] + 1;
            q.push(subin-1);
        }
        if(subin+1<=100000 && arr[subin+1]==0){
            arr[subin+1] = arr[subin] + 1;
            q.push(subin+1);
        }
        if(2*subin<=100000 && arr[2*subin]==0){
            arr[2*subin] = arr[subin] + 1;
            q.push(2*subin);
        }
    }
}