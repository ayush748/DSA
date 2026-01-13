#include<iostream>
#include<vector>
using namespace std;

vector<int>function(vector<vector<int>>arr){
    vector<int>brr;
    int n=arr.size();
    int m=arr[0].size();
    int total=n*m;

    int count=0;
    int sR=0;
    int sC=0;
    int eR=n-1;
    int eC=m-1;

    while(count<total){
        for(int i=sC;i<=eC && count<total;i++){
            int val=arr[sR][i];
            brr.push_back(val);
            count++;
        }
        sR++;
        for(int i=sR;i<=eR && count<total;i++){
            int val=arr[i][eC];
            brr.push_back(val);
            count++;
        }
        eC--;
        for(int i=eC;i>=sC && count<total;i--){
            int val=arr[eR][i];
            brr.push_back(val);
            count++;
        }
        eR--;
        for(int i=eR;i>=sR && count<total;i--){
            int val=arr[i][eC];
            brr.push_back(val);
            count++;
        }
        sC++;
    }
    return brr;
}

int main(){
    vector<vector<int>>arr;
    int n;
    int m;
    cin>>n>>m;
    vector<vector<int>>arr(n,vector<int>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    vector<int>brr=function(arr);
    return 0;
}