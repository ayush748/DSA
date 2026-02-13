#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<string>arr(n);

        for(int i=0;i<n;i++){
            cin>>arr[i];
        }


        int res=0;
        
        for(int i=0;i<m;i++){
            if(arr[n-1][i]=='D'){
                res++;
            }
        }
        for(int i=0;i<n;i++){
            if(arr[i][m-1]=='R'){
                res++;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}