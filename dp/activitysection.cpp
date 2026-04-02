#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int>start={1,3,0,5,8,5};
    vector<int>end={2,4,6,7,9,9};

    int n=start.size();
    vector<pair<int,int>>arr;

    for(int i=0;i<n;i++){
        arr.push_back({end[i],start[i]});
    }

    sort(arr.begin(),arr.end());

    int cnt=1;
    int last=arr[0].first;

    for(int i=1;i<n;i++){
        if(arr[i].second>=last){
            cnt++;
            last=arr[i].first;
        }
    }

    cout<<cnt<<endl;
    return 0;
}