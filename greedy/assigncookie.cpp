#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>g(n);
    for(int i=0;i<n;i++){
        cin>>g[i];
    }
    int m;
    cin>>m;
    vector<int>s(n);
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    sort(s.begin(),s.end());
    int n=g.size();//g
    int m=s.size();//s
    int l=0;//g
    int r=0;//s
    sort(g.begin(),g.end());
    sort(s.begin(),s.end());
    int ans=0;
    while(l<n && r<m){
        if(s[r]>=g[l]){
            l++;
            r++;
            ans++;
        }else{
            r++;
        }
    }
    return 0;
}