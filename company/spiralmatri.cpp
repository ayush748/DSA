#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<vector<int>>arr={{1,2,3},{4,5,6},{7,8,9}};
    vector<int>brr;
    int n=arr.size();
    int m=arr[0].size();
    int total=n*m;
    
    int sc=0;
    int sr=0;
    int er=n-1;
    int ec=m-1;

    int cnt=0;
    while(cnt<total){
        for(int i=sc;i<=ec && cnt<total;i++){
            brr.push_back(arr[sr][i]);
            cnt++;
        }
        sr++;
        for(int i=sr;i<=er && cnt<total;i++){
            brr.push_back(arr[i][ec]);
            cnt++;
        }
        ec--;
        for(int i=ec;i>=sc && cnt<total;i--){
            brr.push_back(arr[er][i]);
            cnt++;
        }
        er--;
        for(int i=er;i>=sr && cnt<total;i--){
            brr.push_back(arr[i][sc]);
            cnt++;
        }
        sc++;
    }

    return 0;
}