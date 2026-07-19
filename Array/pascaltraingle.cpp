#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int>>res(n);
    for(int i=0;i<n;i++){
        res[i]=vector<int>(i+1,1);
        for(int j=1;j<i;j++){
            res[i][j]=res[i-1][j]+res[i-1][j-1];
        }
    }
    
    return 0;
}