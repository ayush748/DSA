#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int n,q;
    cin>>n>>q;
    vector<long long>arr(n+1);
    vector<long long>brr(n+2);
    for (int i=1;i<=n;i++) {
        cin>>arr[i];
    }
    for (int i=1;i<=n;i++){
        cin>>brr[i];
    }
    vector<long long>crr(n+2);
    for (int i=1;i<=n;i++){
        crr[i] =brr[i];
    }
    vector<long long>drr(n+3,0);
    for (int i = n;i>=1;i--) {
        drr[i]=max({arr[i], crr[i], drr[i+1]});
    }
    vector<long long> pref(n+2,0);
    for (int i=1;i<=n;i++) {
        pref[i] = pref[i-1]+drr[i];
    }
    while (q--) {
        int l, r;
        cin>>l>>r;
        cout<<pref[r]-pref[l-1]<< " ";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
        cout<<endl;
    }
    return 0;
}
