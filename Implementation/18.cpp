#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
int main(){
    string s;
    cin>>s;
    unordered_map<char,int>mp;
    int n=s.size();
    for(int i=0;i<n;i++){
        mp[s[i]]++;
    }
    n=mp.size();
    if(n&1){
        cout<<"IGNORE HIM!"<<endl;
    }else{
        cout<<"CHAT WITH HER!"<<endl;
    }

    return 0;
}