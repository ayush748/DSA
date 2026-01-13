#include<iostream>
#include<vector>
using namespace std;
float function(vector<int>arr,int k){

    int n=arr.size();
    // sum
    int sum=0;

    for(int i=0;i<k;i++){
        sum+=arr[i];
    }

    float avg=(float)sum/k;
    float ans=avg;
    int i=1;
    int j=k;
    while(j<n){
        sum+=arr[j];
        sum-=arr[i-1];
        float val=(float)sum/k;
        avg=max(avg,val);
        i++;
        j++;
    }
    return avg;

}
int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    float val=function(arr,k);
    return 0;
}