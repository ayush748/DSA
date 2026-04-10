#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int minval=arr[0];
    int profit=0;
    for(int i=1;i<n;i++){
        int val1=arr[0]-minval;
        profit=max(profit,minval);
        minval=min(minval,arr[i]);
    }
    cout<<profit<<endl;
    return 0;
}