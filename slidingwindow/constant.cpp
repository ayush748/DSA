#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    int i=0;
    int j=k-1;
    int sum=0;
    for(int a=i;a<=j;a++){
        sum=sum+arr[a];
    }   
    int ans=sum;
    j++;
    while(j<n){
        sum=sum+arr[j];
        sum=sum-arr[i];
        i++;
        j++;
    }
    
    return 0;
}