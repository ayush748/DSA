#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n=s.size();
    vector<int>arr;
    for(int i=0;i<n;i++){
        if(s[i]!='+'){
            int val=s[i]-'0';
            arr.push_back(val);
        }
    }
    sort(arr.begin(),arr.end());
    n=arr.size();
    for(int i=0;i<n;i++){
        cout<<arr[i];
        if(i<n-1){
            cout<<"+";
        }
    }
    cout<<endl;
    return 0;
}