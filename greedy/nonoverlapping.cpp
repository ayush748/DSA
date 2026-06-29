#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int>>arr(n,vector<int>(2));
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            cin>>arr[i][j];
        }
    }
    int cnt=0;
    int i=0;
    int j=1;
    while(j<n){
        vector<int>curr=arr[i];
        vector<int>brr=arr[j];
        int cs=curr[0];
        int ce=curr[1];
        int ns=brr[0];
        int ne=brr[1];
        if(ce<=ns){
            i=j;
            j++;
        }else if(ce<=ne){
            j++;
            cnt++;
        }else{
            i=j;
            j++;
            cnt++;
        }
    }


    return 0;
}