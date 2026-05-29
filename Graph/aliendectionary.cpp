#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<string>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<string>w;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        w.push_back(s);
    }
    vector<int>indegree(26,0);
    vector<bool>present(26,false);
    unordered_map<char,vector<char>>adj;
    for(auto str:w){
        for(auto ch:str){
            present[ch-'a']=true;
        }
    }
    int i=0;
    int j=1;
    while(j<n){

        string s=w[i];
        string t=w[j];

        int m=s.size();
        int k=t.size();

        int a=0;
        int b=0;
        bool found=false;
        while(a<m && b<k){
            if(s[a]!=t[b]){
                adj[s[a]].push_back(t[b]);
                found=true;
                break;
            }
            a++;
            b++;
        }
        if(!found && m>k){
            cout<<"";
            return 0;
        }
        i++;
        j++;
    }
    for(auto x:adj){
        for(auto nbr:x.second){
            indegree[nbr-'a']++;
        }
    }
    queue<char>q;
    vector<char>ans;

    for(int i=0;i<26;i++){
        if(present[i] && indegree[i]==0){
            q.push(char(i+'a'));
        }
    }
    while(!q.empty()){
        auto front=q.front();
        ans.push_back(front);
        q.pop();
        for(auto nbr:adj[front]){
            indegree[nbr-'a']--;
            if(indegree[nbr-'a']==0){
                q.push(nbr);
            }
        }
    }
    int cnt=0;
    for(int i=0;i<26;i++){
        if(present[i]){

            cnt++;
        }
    }
    if(ans.size()!=cnt){
        cout<<"";
        return 0;
    }
    for(auto ch:ans){
        cout<<ch;
    }
    return 0;
}