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
    int k;
    cin>>k;
    int i=0;
    int j=0;
    int cnt=0;
    int mul=1;
    while(i<n){
        mul=mul*arr[j];
        if(mul<k){
            cnt++;
        }else{
            mul=1;
            i++;
            j=i;
        }
        if(j==n-1){
            mul=1;
            i++;
            j=i;
            continue;
        }
        j++;
    }
    cout<<cnt;
    return 0;
}