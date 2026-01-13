#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool check(string s,string x){
    if(x.find(s)!=string::npos){
        return true;
    }else{
        return false;
    }
}

int solve(string s,string x){
    string x0=x;
    string x1=x0+x0;
    string x2=x1+x1;
    string x3=x2+x2;
    string x4=x3+x3;
    string x5=x4+x4;

    int ans=-1;
    if(check(s,x0)){
        ans=0;
    }else if(check(s,x1)){
        ans=1;
    }else if(check(s,x2)){
        ans=2;
    }else if(check(s,x3)){
        ans=3;
    }else if(check(s,x4)){
        ans=4;
    }else if(check(s,x5)){
        ans=5;
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        string x,s;
        cin>>x;
        cin>>s;
        int ans=solve(s,x);
        cout<<ans<<endl;
    }
    return 0;
}