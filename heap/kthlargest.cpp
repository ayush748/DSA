#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    priority_queue<int>pq;
    for(int i=0;i<n;i++){
        pq.push(arr[i]);
    }
    while(k--){
        pq.pop();
    }
    return 0;
}