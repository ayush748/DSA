#include<iostream>
#include<vector>
using namespace std;
int function(vector<int>arr){
    int val=0;
    int n=arr.size();
    int totalSum=(n*(n+1))/2;
    int sum=0;
    for(int i=0;i<n;i++){
        sum=sum+arr[i];
    }

    val=totalSum-sum;

    return val;
}
int functionApproach2(vector<int>arr){
    int n=arr.size();
    int sum=0;
    int number=0;
    for(int i=0;i<n;i++){
        sum=sum^arr[i];
    }

    for(int i=0;i<=n;i++){
        number=number^i;
    }

    return sum^number;


}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int val=function(arr);
    cout<<val;
    return 0;
}