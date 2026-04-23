#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        string s1;
        cin >> s1;
        string s2;
        cin >> s2;
        
        int i = 1;
        long long val1 = 0;
        long long val2 = (s1[0] != s2[0]);
        while(i < n){
            long long x = (s1[i] != s2[i]);
            long long v1 = (s1[i-1] != s1[i]);
            long long v2 = (s2[i-1] != s2[i]);
            long long y = (v1 + v2);
            long long v3 = val2 + x;
            long long v4 = val1 + y;
            long long z = min(v3, v4);
            val1 = val2;
            val2 = z;
            i++;
        }
        cout<<val2<<endl;
    }
    return 0;
}