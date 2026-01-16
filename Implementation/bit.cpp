#include<iostream>
#include<vector>
using namespace std;
int main(){

    int n;
    cin>>n;
    vector<string>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i] =="X++" || arr[i]=="++X"){
            count++;
        }else{
            count--;
        }
    }
    cout<<count;
    return 0;
}