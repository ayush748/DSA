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
    bool flag=false;
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            flag=true;
            break;
        }
    }
    if(flag){
        cout<<"Hard"<<endl;
    }else{
        cout<<"Easy"<<endl;
    }
    return 0;
}