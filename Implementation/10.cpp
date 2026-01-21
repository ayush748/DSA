#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int maxI=0;
    int maxAns=INT_MIN;
    int minI=0;
    int minAns=INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i]>maxAns){
            maxAns=arr[i];
            maxI=i;
        }

        if(arr[i]<=minAns){
            minAns=arr[i];
            minI=i;
        }
    }
    int val=maxI+(n-1-minI);
    if(maxI>minI){
        val--;
    }
    cout<<val;
    return 0;
}