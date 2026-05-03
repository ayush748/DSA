#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool ok(pair<int,int>&a,pair<int,int>&b){
    return a.first>b.second;
}

int frec(vector<pair<int,int>>&a,int i,int p){
    if(i==a.size()) return 0;
    int x=0;
    if(p==-1 || ok(a[i],a[p])) x=1+frec(a,i+1,i);
    int y=frec(a,i+1,p);
    return max(x,y);
}

int fmem(vector<pair<int,int>>&a,int i,int p,vector<vector<int>>&dp){
    if(i==a.size()) return 0;
    if(dp[i][p+1]!=-1) return dp[i][p+1];
    int x=0;
    if(p==-1 || ok(a[i],a[p])) x=1+fmem(a,i+1,i,dp);
    int y=fmem(a,i+1,p,dp);
    return dp[i][p+1]=max(x,y);
}

int tab(vector<pair<int,int>>&a){
    int n=a.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    for(int i=n-1;i>=0;i--){
        for(int p=i-1;p>=-1;p--){
            int x=0;
            if(p==-1 || ok(a[i],a[p])) x=1+dp[i+1][i+1];
            int y=dp[i+1][p+1];
            dp[i][p+1]=max(x,y);
        }
    }
    return dp[0][0];
}

int so(vector<pair<int,int>>&a){
    int n=a.size();
    vector<int>nxt(n+1,0),cur(n+1,0);
    for(int i=n-1;i>=0;i--){
        for(int p=i-1;p>=-1;p--){
            int x=0;
            if(p==-1 || ok(a[i],a[p])) x=1+nxt[i+1];
            int y=nxt[p+1];
            cur[p+1]=max(x,y);
        }
        nxt=cur;
    }
    return nxt[0];
}

int greedy(vector<pair<int,int>>&a){
    sort(a.begin(),a.end(),[](pair<int,int>&x,pair<int,int>&y){
        return x.second<y.second;
    });
    int c=1,e=a[0].second;
    for(int i=1;i<a.size();i++){
        if(a[i].first>e){
            c++;
            e=a[i].second;
        }
    }
    return c;
}

int main(){
    vector<pair<int,int>>a={{5,24},{15,25},{27,40},{50,60}};
    sort(a.begin(),a.end());

    int r1=frec(a,0,-1);

    vector<vector<int>>dp(a.size(),vector<int>(a.size()+1,-1));
    int r2=fmem(a,0,-1,dp);

    int r3=tab(a);
    int r4=so(a);
    int r5=greedy(a);

    cout<<r1<<"\n";
    cout<<r2<<"\n";
    cout<<r3<<"\n";
    cout<<r4<<"\n";
    cout<<r5<<"\n";
}