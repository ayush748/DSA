#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
int main(){
    vector<string>arr={"eat","tea","tan","ate","nat","bat"};
    map<string,vector<string>>mp;
    int n=arr.size();
    for(int i=0;i<n;i++){
        string strs=arr[i];
        sort(strs.begin(),strs.end());
        mp[strs].push_back(arr[i]);
    }
    vector<vector<string>>ans;
    for(auto it=mp.begin();it!=mp.end();it++){
        ans.push_back(it->second);
    }
    n=ans.size();
    for(int i=0;i<n;i++){
        int m=ans[i].size();
        for(int j=0;j<m;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}