#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int a=pow(2,n);
    vector<int>s;
    for(int i=0;i<n;i++){
        s.push_back(i^(i>>1));
    }
    
    return 0;
}