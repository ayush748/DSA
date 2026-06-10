#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
vector<int> parent;
vector<int> rnk;
int find(int x){
    if(x==parent[x]){
        return x;
    }
    return parent[x]=find(parent[x]);
}
void Union(int x,int y){
    int xp=find(x);
    int yp=find(y);
    if(xp==yp){
        return;
    }
    if(rnk[xp]<rnk[yp]){
        parent[xp]=yp;
    }
    else if(rnk[xp]>rnk[yp]){
        parent[yp]=xp;
    }
    else{
        parent[yp]=xp;
        rnk[xp]++;
    }
}
vector<vector<string>> accountsMerge(vector<vector<string>>& accounts){
    int n=accounts.size();
    parent.resize(n);
    rnk.resize(n,0);
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
    unordered_map<string,int> mp;
    for(int i=0;i<n;i++){
        for(int j=1;j<accounts[i].size();j++){
            string email=accounts[i][j];
            if(mp.find(email)==mp.end()){
                mp[email]=i;
            }
            else{
                Union(i,mp[email]);
            }
        }
    }
    unordered_map<int,vector<string>>group;
    for(auto it:mp){
        string email=it.first;
        int idx=it.second;
        int p=find(idx);
        group[p].push_back(email);
    }
    vector<vector<string>> ans;
    for(auto it:group){
        int p=it.first;
        vector<string> emails=it.second;
        sort(emails.begin(),emails.end());
        vector<string> temp;
        temp.push_back(accounts[p][0]);
        for(auto email:emails){
            temp.push_back(email);
        }
        ans.push_back(temp);
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<vector<string>> accounts(n);
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        string name;
        cin>>name;
        accounts[i].push_back(name);
        for(int j=0;j<m;j++){
            string email;
            cin>>email;
            accounts[i].push_back(email);
        }
    }
    vector<vector<string>> ans=accountsMerge(accounts);
    for(auto account:ans){
        for(auto s:account){
            cout<<s<<" ";
        }
        cout<<endl;
    }
    return 0;
}