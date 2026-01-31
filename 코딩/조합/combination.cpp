#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main() {
    vector<int> nums = {1,2,3,4};
    int r = 2;
    vector<bool> check(nums.size());

    fill(check.begin() + r, check.end(), true);

    do {
        for(int i=0; i<nums.size(); i++){
            if(!check[i])
                cout<<nums[i]<<" ";
        }
        cout<<'\n';
    } while(next_permutation(check.begin(), check.end()));
    return 0;
}