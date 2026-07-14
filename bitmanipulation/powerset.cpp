#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>subset={1,2,3};
    int n=subset.size();
    int m=1<<n;
    vector<vector<int>>ans;
    for(int i=0;i<m;i++){
        vector<int>arr;
        for(int j=0;j<n;j++){
            if(i & (1<<j)){
                arr.push_back(subset[j]);
            }
        }
        ans.push_back(arr);
    }
    return 0;
}