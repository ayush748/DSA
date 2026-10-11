#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>arr(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    int target;
    cin>>target;
    int r=arr.size();
    int c=arr[0].size();
    int total=r*c;
    int s=0;
    int e=total-1;
    int mid=s+(e-s)/2;
    bool flag=false;
    while(s<=e){
        mid=s+(e-s)/2;
        int ir=mid/c;
        int ic=mid%c;
        int curr=arr[ir][ic];
        if(curr=target){
            flag=true;
            break;
        }else if(curr<target){
            s=mid+1;
        }else{
            e=mid-1;
        }

    }

    return 0;
}