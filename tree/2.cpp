#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int z=0,o=0;
    stack<char> st;
    for(int i=0;i<n;){
        int j=i;
        while(j<n && s[j]==s[i]){
            j++;
        }
        st.push(s[i]);
        if(s[i]=='0'){
            z+=(j-i-1);
        }
        else{
            o+=(j-i-1);
        }
        i=j;
    }
    vector<char>ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    int e0=0,e1=0;
    int m=ans.size();
    if(m){
        if(ans.front()=='0'){
            e0++;
        }
        else{
            e1++;
        }
        if(m>1){
            if(ans.back()=='0'){
                e0++;
            }
            else{
                e1++;
            }
        }
    }
    int i=0;
    while(i<=e0){
        int j=0;
        while(j<=e1){
            int x=z+i;
            int y=o+j;
            if(abs(x-y)<=1){
                cout<<x+y<<endl;
                return;
            }

            j++;
        }
        i++;
    }
    cout<<-1<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}