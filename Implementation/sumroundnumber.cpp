#include<iostream>
#include<vector>
#include<cmath>
#include<string>
using namespace std;
void solve(){
    int n;
    cin>>n;
    int cnt=1;
    vector<int>arr;
    while(n>0){
        int val1=n%10;
        if(val1!=0){
            arr.push_back(val1*cnt);
        }
        n=n/10;
        cnt=cnt*10;
    }
    cout << arr.size() << endl;
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}