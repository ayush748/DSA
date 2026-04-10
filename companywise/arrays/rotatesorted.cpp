#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>arr={1,2,3,4};
    int n=arr.size();
    int cnt=0;

    for(int i=0;i<n;i++){
        if(arr[i]>arr[(i+1)%n]){
            cnt++;
        }
    }
    if(cnt<=1){
        cout<<cnt<<endl;
    }
    return 0;
}