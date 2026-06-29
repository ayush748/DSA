#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int wt=0;
    int tt=0;
    for(int i=0;i<n;i++){
        wt=wt+tt;
        tt=tt+arr[i];
    }
    cout<<wt/n;
    return 0;
}
