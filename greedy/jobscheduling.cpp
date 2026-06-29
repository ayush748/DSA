#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool compresion(vector<int>a,vector<int>b){
    return a[2]>b[2];
}
int main(){
    vector<vector<int>>arr={
        {1, 2, 100},
        {2, 1, 19},
        {3, 2, 27},
        {4, 1, 25},
        {5, 3, 15},
        {6, 2, 60},
        {7, 4, 70},
        {8, 3, 65},
        {9, 5, 80},
        {10, 4, 30}
    };
    int n=arr.size();
    sort(arr.begin(),arr.end());
    int maxi=0;
    for(auto vec:arr){
        maxi=max(maxi,vec[1]);
    }
    vector<int>slot(maxi+1,-1);
    int c=0;
    int j=0;
    for(int i=0;i<n;i++){
        for(int j=arr[i][1];j>0;j++){
            if(slot[j]==-1){
                slot[j] = i;
                c++;
                j += arr[i][2];
                break;

            }
        }
    }
    return 0;
}