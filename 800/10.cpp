#include<iostream>
#include<vector>
using namespace std;
long long solve(vector<vector<char>>arr){
    int n=arr.size();
    int m=arr[0].size();
    long long ans=0;
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<m;j++){
            if(arr[i][j]=='X'){
                count++;
            }
        }

        if(i==0 || i==9){
            ans+=(count*1);
        }else if(i==1 || i==8){
            ans+=(count*2);
        }else if(i==2 || i==7){
            ans+=(count*3);
        }else if(i==3 || i==6){
            ans+=(count*4);
        }else{
            ans+=(count*5);
        }
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<char>>arr(10,vector<char>(10));
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                cin>>arr[i][j];
            }
        }

        long long ans=solve(arr);
        cout<<ans<<endl;
    }
    return 0;
}