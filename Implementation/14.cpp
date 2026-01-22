#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main(){
    int n;
    cin>>n;
    int ans=INT_MIN;
    int val=0;
    while(n--){
        int a;
        int b;
        cin>>a>>b;
        val=(val-a)+b;
        ans=max(ans,val);
    }
    cout<<ans;
    return 0;
}