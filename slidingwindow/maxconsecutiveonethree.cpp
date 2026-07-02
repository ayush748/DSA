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
    int l=0;
    int r=0;
    int zero=0;
    int maxlen=0;
    while(r<n){
        if(arr[r]==0){
            zero++;
        }
        while(zero>k){
            if(arr[l]==0){
                zero--;
            }
            l++;
        }
        maxlen=max(maxlen,r-l+1);
        r++;
    }
    return 0;
}