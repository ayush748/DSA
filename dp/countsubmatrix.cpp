#include<iostream>
#include<vector>
using namespace std;
int onecount(vector<int>& arr){
    int cons=0;
    int subCount=0;
    int n=arr.size();
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            cons=0;
        }
        else{
            cons++;
        }
        subCount+=cons;
    }
    return subCount;
}
int solve(vector<vector<int>>& arr){
    int m=arr.size();
    int n=arr[0].size();
    int result=0;
    for(int s=0;s<m;s++){
        vector<int> vec(n,1);
        for(int e=s;e<m;e++){
            for(int col=0;col<n;col++){
                vec[col]=vec[col] & arr[e][col];
            }
            result+=onecount(vec);
        }
    }
    return result;
}
int main(){
    string s;
    cin>>s;
    return 0;
}