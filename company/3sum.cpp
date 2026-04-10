#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int>arr={-1,0,1,2,-1,-4};
    int n=arr.size();
    vector<vector<int>>brr;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n-2;i++){
        if(i>0 && arr[i]==arr[i-1]){
            continue;
        }
        int j=i+1;
        int k=n-1;
        while(j<k){
            int value=arr[i]+arr[j]+arr[k];
            if(value<0){
                j++;
            }else if(value>0){
                k--;
            }else{
                brr.push_back({arr[i],arr[j],arr[k]});
                while(j<k && arr[j+1]==arr[j]){
                    j++;
                }
                while(j<k && arr[k-1]==arr[k]){
                    k--;
                }
                j++;
                k--;
            }

        }
    }
    return 0;
}