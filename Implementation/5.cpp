#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int>arr(3);
    for(int i=0;i<3;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());

    int val=arr[1];
    int ans=(arr[1]-arr[0])+(arr[2]-arr[1]);
    cout<<ans<<endl;
    return 0;
}