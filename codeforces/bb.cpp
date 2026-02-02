#include <iostream>
#include <vector>
#include <algorithm>
#include<queue>
using namespace std;
void solve(int n){
    vector<int>arr(n);
    priority_queue<pair<int,int>>pq;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        pq.push({arr[i],i});
    }
    int i=0;
    while(i < n){
        if(arr[i]!=n-i){
            break;
        }
        i++;
    }
    if(i == n){
        for(int x : arr){
            cout << x << " ";
        }
        return;
    }
    int j=i;
    while(!pq.empty()){

        auto front=pq.top();
        int val1=front.first;
        int index=front.second;

        if(val1 > arr[i] && index>=i){
            j=index;
            break;
        }
        pq.pop();
    }
    while(i<j){
        swap(arr[i], arr[j]);
        i++;
        j--;
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        solve(n);
        cout<<endl;
    }
    return 0;
}
