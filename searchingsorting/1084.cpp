#include <iostream>
#include <vector>
#include <deque>
using namespace std;
void solve(){
    int a,b,c;
    cin>>a>>b>>c;
    vector<int>arr(a);
    int i=0;
    while(i<a){
        cin>>arr[i];
        i++;
    }
    vector<int>brr;
    int d=0;
    i=b;
    while(i<c){
        brr.push_back(arr[i]);
        if(brr.back()<brr[d]){
            d=brr.size()-1;
        }
        i++;
    }
    int e=brr.size();
    vector<int>crr(e);
    i=0;
    while(i<e){
        int val=(d+i)%e;
        crr[i]=brr[val];
        i++;
    }
    deque<int>drr;
    i=0;
    while(i<b){
        drr.push_back(arr[i]);
        i++;
    }
    i=c;
    while(i<a){
        drr.push_back(arr[i]);
        i++;
    }
    int f=drr.size();
    i=0;
    while(i<drr.size()){
        if(drr[i]>crr[0]){
            f=i;
            break;
        }
        i++;
    }
    vector<int>ans;
    i=0;
    while(i<f){
        ans.push_back(drr[i]);
        i++;
    }
    i=0;
    while(i<e){
        ans.push_back(crr[i]);
        i++;
    }
    i=f;
    while(i<drr.size()){
        ans.push_back(drr[i]);
        i++;
    }
    i=0;
    while(i<a){
        cout<<ans[i]<<" ";
        i++;
    }
    cout<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}