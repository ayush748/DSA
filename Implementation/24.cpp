#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int cnt=0;
        int x=n;

        while(n){
            cnt++;
            n=n/10;
        }
        int val1=x%10;
        int val=(val1-1)*10+((cnt)*(cnt+1))/2;
        cout<<val<<endl;
    }
    return 0;
}