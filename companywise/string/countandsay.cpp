#include<iostream>
#include<vector>
#include<string>
using namespace std;

string solve(int n){
    if(n==1){
        return "1";
    }

    string val=solve(n-1);
    string result="";
    int m=val.size();
    int i=0;

    while(i<m){
        int cnt=1;
        while(i<m-1 && val[i]==val[i+1]){
            cnt++;
            i++;
        }
        result=result+to_string(cnt)+string(1,val[i]);
        i++;
    }

    return result;
}

int main(){
    int n;
    cin>>n;
    string ans=solve(n);
    cout<<ans;
    return 0;
}