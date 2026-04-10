#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int>arr;
    vector<int>brr;
    vector<pair<int,int>>crr;
    int n=arr.size();
    for(int i=0;i<n;i++){
        crr.push_back({brr[i],arr[i]});
    }
    sort(crr.begin(),crr.end());
    int last=crr[0].second;
    int cnt=1;
    for(int i=0;i<n;i++){
        if(crr[i].first>=last){
            last=crr[i].first;
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}