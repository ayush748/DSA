#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
int main(){
    int k=3;
    string num="1432219";
    string ans;
    stack<char>st;
    int i=0;
    int n=num.size();
    while(i<n && k>0){
        if(st.empty()){
            st.push(num[i]);
        }else{
            char ch=st.top()-'0';
            char ch2=num[i]-'0';
            if(ch2<ch){
                st.pop();

                st.push(num[i]);
                k--;
            }else{
    
                st.push(num[i]);
            }
        }
        i++;
    }
    while(i<n){
        st.push(num[i]);
        i++;
    }
    while(!st.empty()){
        char ch=st.top();
        ans=ans+ch;
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
    

    return 0;
}