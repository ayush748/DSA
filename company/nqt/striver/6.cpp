#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        arr[i]=data;
    }
    sort(arr.begin(),arr.end());
    int i=0;
    vector<int>brr;
    while(i<(n/2)){
        brr.push_back(arr[i]);
        i++;
    }
    int j=i;
    i=n-1;
    while(i>=j){
        brr.push_back(arr[i]);
        i--;
    }
    for(int i=0;i<n;i++){
        cout<<brr[i]<<" ";
    }
    return 0;
}