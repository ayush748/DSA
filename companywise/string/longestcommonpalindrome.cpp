#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    string s;
    cin>>s;
    string ans;
    int len=INT_MAX;
    string ans;
    int n=s.size();
    for(int i=0;i<n;i++){
        int j=i;
        int start=i;
        while(start>=0 && j<=n && s[start]==s[j]){
            int ans1=j-start+1;
            if(ans1>len){
                ans1=len;
                ans=s.substr(start,j-start+1);
            }
            start--;
            j++;
        }
        j=i+1;
        start=i;
        while(start>=0 && j<=n && s[start]==s[j]){
            int ans1=j-start+1;
            if(ans1>len){
                ans1=len;
                ans=s.substr(start,j-start+1);
            }
            start--;
            j++;
        }
    }
}