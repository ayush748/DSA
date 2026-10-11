#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int i=0;
    int ans=0;
    int one=0;
    while(i<n){
        if(arr[i]==1){
            one++;
        }else{
            one=0;
        }
        ans=max(ans,one);
        i++;
    }
    cout<<ans;
    return 0;
}
