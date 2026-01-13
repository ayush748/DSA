#include<iostream>
#include<vector>
using namespace std;
void function(vector<int>&arr){
    int n=arr.size();
    int i=0;
    int j=n-1;
    int k=0;
    while(k<=j){
        if(arr[k]==2){
            swap(arr[j],arr[k]);
            j--;
        }else if(arr[k]==0){
            swap(arr[i],arr[k]);
            i++;
            k++;
        }else{
            k++;
        }
    }
}
int main(){
    vector<int>arr={2,0,2,1,1,0};
    function(arr);
    int n=arr.size();
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}