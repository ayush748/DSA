#include<iostream>
#include<vector>
using namespace std;
void function(vector<int>&arr){
    int n=arr.size();
    int i=0;
    int j=0;
    while(j<n){
        while(j<n && arr[j]>=0){
            j++;
        }
        if(j<n){
            swap(arr[i],arr[j]);
            i++;
            j++;
        }
    }

}
int main(){

    vector<int>arr={23,-7,12,10,-11,40,-6};
    function(arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}