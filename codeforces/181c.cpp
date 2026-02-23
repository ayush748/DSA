#include <iostream>
#include <vector>
#include<map>
#include<algorithm>
#include<unordered_map>
#include<string>
using namespace std;
void solve(long long n,long long h,long long k,vector<long long>& arr,long long s){
    vector<long long>brr(n);
    brr[0]=arr[0];
    int l=1;
    while(l<n){
        if(brr[l-1]<arr[l]){
            brr[l]=brr[l-1];
        }else{
            brr[l]=arr[l];
        }
        l++;
    }
    vector<long long>crr(n);
    crr[n-1]=arr[n-1];
    int idx=n-2;
    while(idx>=0){
        if(crr[idx+1]>arr[idx]){
            crr[idx]=crr[idx+1];
        }else{
            crr[idx]=arr[idx];
        }
        idx--;
    }
    long long ans=-1;
    long long p=0;
    long long i=0;
    while(i<n){
        p+=arr[i];
        long long val1=p;
        if(i+1<n){
            long long val=crr[i+1]-brr[i];
            if(val>0){
                val1+=val;
            }
        }
        long long rem=h-val1,c=0;
        if(rem>0){
            c=(rem+s-1)/s;
        }
        long long cur=c*(n+k)+(i+1);
        if(ans==-1||cur<ans){
            ans=cur;
        }
        i++;
    }
    cout<<ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        long long n,h,k;
        cin>>n>>h>>k;
        vector<long long>arr(n);
        long long ss=0;
        int i=0;
        while(i<n){
            cin>>arr[i];
            ss=ss+arr[i];
            i++;
        }
        solve(n,h,k,arr,ss);
        cout<<endl;
    }
    return 0;
}