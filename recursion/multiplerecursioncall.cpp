#include<iostream>
#include<vector>
using namespace std;
int solve(int n){
    if(n<=1){
        return n;
    }
    int ans=solve(n-1)+solve(n-2);
    return ans;
}
int main(){
    int n;
    cin>>n;
    int ans=solve(n);
    cout<<ans;
    return 0;
}