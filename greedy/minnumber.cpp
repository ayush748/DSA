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
    vector<int>deps(n);
    for(int i=0;i<n;i++){
        cin>>deps[i];
    }

    int ans=1;
    for(int i=0;i<n;i++){
        int cnt=1;
        for(int j=i+1;j<n;i++){
            if((arr[i]>=arr[j] && arr[i]<=deps[j]) || (arr[j]>=arr[i] && arr[j]<=deps[i])){
                cnt++;
            }
        }
        ans=max(ans,cnt);
    }
    return 0;
}