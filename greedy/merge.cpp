#include<iostream>
#include<vector>
#include<algorithm>
using namespace std; 
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> merged;

    for (auto interval : intervals) {
        if (merged.empty() || merged.back()[1] < interval[0]) {
            merged.push_back(interval);
        } else {
            merged.back()[1] = max(merged.back()[1], interval[1]);
        }
    }

    return merged;
}
int main(){
    vector<vector<int>>arr={{1,3}, {2,6}, {8,10}, {15,18}};
    vector<vector<int>>res;
    sort(arr.begin(),arr.end());
    vector<vector<int>>ans;
    int n=arr.size();
    int i=0;
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