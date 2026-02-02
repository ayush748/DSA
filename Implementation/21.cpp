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
    int i=0;
    int j=1;
    int cnt=1;
    int val1=1;
    while(j<n){
        if(arr[j]>arr[j-1]){
            val1++;
        }else{
            val1=1;
        }
        cnt=max(cnt,val1);
        j++;
    }
    cout<<cnt<<endl;
    return 0;
}