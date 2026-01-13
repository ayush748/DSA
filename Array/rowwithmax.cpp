#include<iostream>
#include<vector>
using namespace std;
vector<int> function(vector<vector<int>>arr){

    int n=arr.size();
    int m=arr[0].size();

    int row=INT_MIN;
    int count=INT_MIN;
    for(int i=0;i<n;i++){
        int val=0;
        for(int j=0;j<m;j++){
            if(arr[i][j]==1){
                val++;
            }
        }
        if(val>count){
            row=i;
            count=val;
        }
    }

    return {row,count};

}
int main(){
    int n,m;
    cin>>n,m;

    vector<vector<int>>arr(n,vector<int>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    vector<int>brr=function(arr);





    return 0;
}