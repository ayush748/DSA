#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>
using namespace std;
int main(){
    string s="abcabcbb";
    string ans;
    int i=0;
    int n=s.size();
    if(n==0){
        return 0;
    }
    int maxlen=1;
    ans.push_back(s[i]);
    i=i+1;
    while(i<n){
        char ch=s[i];
        bool flag=false;
        int j=0;
        while(j<ans.size()){
            if(ch==ans[j]){
                flag=true;
                break;
            }
            j++;
        }
        if(flag){
            ans.erase(ans.begin(),ans.begin()+j+1);
        }
        ans.push_back(ch);
        int m=ans.size();
        maxlen=max(maxlen,m);
        i++;
    }
    
    cout<<maxlen;
    return 0;
}