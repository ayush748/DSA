#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n+1);
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }
        vector<int>brr(n+1);
        for(int i=1;i<=n;i++){
            brr[arr[i]]=i;
        }
        int cnt=0;
        int ans=0;
        int i=1;
        while(i<=n){
            if(brr[i]>=i){
                cnt++;
            }
            ans=max(ans,cnt);
            i++;
        }
       
        cout<<ans<<endl<<endl;
    }
    return 0;
}