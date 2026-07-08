#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int>arr={0,1,0,2,1,0,1,3,2,1,2,1};
    int n=arr.size();

    int i=0;
    int j=n-1;
    int lm=0;
    int rm=0;
    int total=0;
    while(i<=j){
        if(arr[i]<=arr[j]){
            if(arr[i]>=lm){
                lm=arr[i];
            }else{
                total=total+(lm-arr[i]);
            }
            i++;
        }else{
            if(arr[j]>=rm){
                rm=arr[j];
            }
            else
            {
                total=total+(rm-arr[j]);
            }
            j--;
        }
    }
    return 0;
}