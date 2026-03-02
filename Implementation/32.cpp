#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(7);
    for(int i=0;i<7;i++){
        cin>>arr[i];
    }
    int count=0;
    int i=0;
    while(n>0){
        if(i==7){
            i=0;
        }
        n=n-arr[i];
        count++;
        i++;
    }
    cout<<i<<endl;
    return 0;
}