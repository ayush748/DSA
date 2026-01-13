#include<iostream>
#include<vector>
using namespace std;
void approach(vector<int>arr){
    int n=arr.size();
    vector<int>brr(n,0);
    int j=0;
    int k=j+1;
    for(int i=0;i<n;i++){
        if(arr[i]>=0){
            brr[j]=arr[i];
            j+=2;
        }else{
            brr[k]=arr[i];
            k+=2;
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    approach(arr);
    return 0;
}