#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    int t;
    cin>>t;
    vector<int>arr(n);
    for(int i=0;i<n-1;i++){
        cin>>arr[i];
    }
    int i=1;
    int j=0;
    bool flag=false;
    if(t==1){
        flag=true;
    }
    while(i<t){
        int ans=arr[j]+i;
        if(ans==t){
            flag=true;
            break;
        }
        if(ans>t){
            break;
        }
        i=ans;
        j=i-1;
    }
    if(flag){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
    return 0;
}