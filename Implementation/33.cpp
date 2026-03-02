#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<unordered_map>
using namespace std;
int main(){
    int k;
    cin>>k;
    string s;
    cin>>s;
    map<char,int>mp;
    int n=s.size();
    for(int i=0;i<n;i++){
        mp[s[i]]++;
    }
    string ans;
    for(auto it=mp.begin();it!=mp.end();it++){
        int val=it->second;
        if(val%k!=0){
            cout<<-1;
            return 0;
        }else{
            int j=0;
            while(j<(val/k)){
                ans.push_back(it->first);
                j++;
            }
        }
    }
    string v=ans;
    ans="";
    while (k>0)
    {
        ans=ans+v;
        k--;
    }
    cout<<ans;
    
    return 0;
}