#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
int main(){
    vector<string>arr={"flower","flow","flight"};
    int n=arr.size();
    string ans=arr[0];
    sort(arr.begin(),arr.end());
    string f=arr[0];
    string l=arr[n-1];
    string ans;
    int l1=f.size();
    int l2=l.size();
    int n=min(l1,l2);
    string ans;
    for(int i=0;i<n;i++){
        if(f[i]!=l[i]){
            break;
        }
        ans=ans+f[i];
    }
    return 0;
}