#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<vector<int>>arr={{1,3},{2,6},{8,10},{15,18}};
    sort(arr.begin(),arr.end());
    vector<vector<int>>ans;
    int i=0;
    int n=arr.size();
    while(i<n){
        int s=arr[i][0];
        int e=arr[i][1];
        int j=i+1;
        while(j<n && arr[j][0]<=e){
            e=max(e,arr[j][1]);
            j++;
        }
        ans.push_back({s,e});
        i=j;
    }

    return 0;
}