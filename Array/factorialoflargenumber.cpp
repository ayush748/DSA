#include<iostream>
#include<vector>
using namespace std;
vector<int>solve(int n){
    vector<int>arr;
    arr.push_back(1);
    for(int i=2;i<=n;i++){
        int carry=0;
        for(int j=0;j<arr.size();j++){
            int val1=arr[j]*i+carry;
            arr[j]=val1%10;
            carry=val1/10;
        }
        while(carry){
            arr.push_back(carry%10);
            carry=carry/10;
        }
    }
    reverse(arr.begin(),arr.end());
    return arr;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr=solve(n);
    return 0;
}