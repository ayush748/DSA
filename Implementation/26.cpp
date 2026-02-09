#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int i=0;
    string ans;
    int j=1;
    while(i<n){
        ans.push_back(s[i]);
        i=j+i;
        j++;
    }
    cout<<ans<<endl;
    return 0;
}