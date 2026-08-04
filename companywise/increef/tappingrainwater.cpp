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
    int leftmax=0;
    int rightmax=0;
    int i=0;
    int j=n-1;
    int total=0;
    while(i<j){
        if(arr[i]<=arr[j]){
            if(arr[i]>=leftmax){
                leftmax=arr[i];
            }else{
                total=total+(leftmax-arr[i]);
            }
            i++;
        }else{
            if(arr[j]>=rightmax){
                rightmax=arr[j];
            }else{
                total=total+(rightmax-arr[j]);
            }
            j--;
        }
    }
    return 0;
}