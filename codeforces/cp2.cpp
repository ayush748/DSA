#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    bool flag=true;
    for(int i=0;i<n;i++){
        int val1=i+1;
        while((val1%2)==0){
            val1=val1/2;   
        }
        int val2=arr[i];
        while((val2%2)==0){
            val2=val2/2;   
        }
        if(val1!=val2){
            flag=false;
            break;
        }
    }
    if(flag){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }

}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}