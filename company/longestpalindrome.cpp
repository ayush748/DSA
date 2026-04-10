#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    string s="babad";
    int len=INT_MAX;
    string ans2;
    int n=s.size();
    for(int i=0;i<n;i++){
        int j=i;
        int start=i;
        while(start>=0 && j<=n && s[start]==s[j])
        {
            int ans=j-start+1;
            if(ans>len){
                ans=len;
                ans2=ans2.substr(i,start-j+1);
            }
            i++;
            j--;
        }
        start=i;
        j=i+1;
        while(start>=0 && j<=n && s[start]==s[j]){
            int ans=j-start+1;
            if(ans>len){
                len=ans;
                ans2=ans2.substr(start,j-start+1);

            }
            start++;
            j--;
        }
    }
    return  0;
}