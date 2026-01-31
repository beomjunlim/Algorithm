#include<iostream>
#include<vector>
using namespace std;

vector<int> arr;
int ans[6];



void combination(int start, int idx){
    if(idx==6){
        for(int i=0; i<6; i++){
            cout<<ans[i]<<" ";
        }
        cout<<'\n';
        return;
    }

    for(int i=start; i<arr.size(); i++){
        ans[idx] = arr[i];
        combination(i+1, idx+1);
    }
}
int main(){
    int n;

    while(1){
        cin>>n;

        arr.clear();

        if(n==0)
            break;
        
        for(int i=0; i<n; i++){
            int num;
            cin>>num;
            arr.push_back(num);
        }
        combination(0,0);
        cout<<'\n';
    }
    return 0;
}