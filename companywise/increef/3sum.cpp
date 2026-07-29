#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<vector<int>>ans(n);
    for(int i=0;i<n-2;i++){
        if(i>0 && arr[i]==arr[i-1]){
            continue;
        }
        int j=i+1;
        int k=n-1;
        while(j<k){
            int val=arr[i]+arr[j]+arr[k];
            if(val<0){
                j++;
            }else if(val>0){
                k--;
            }else{
                ans.push_back({arr[i],arr[j],arr[k]});
                while(j<k && arr[j]==arr[j+1]){
                    j++;
                }
                while(j<k && arr[j]==arr[k-1]){
                    k--;
                }
                j++;
                k--;
            }
        }
    }
    
    return 0;
}