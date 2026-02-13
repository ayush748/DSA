#include <iostream>
#include <vector>
using namespace std;

bool check(int mid, vector<int> &a, int k){
    int sum = 0, cnt = 1;

    for(int i = 0; i < a.size(); i++){
        if(a[i] > mid) return false;

        if(sum + a[i] <= mid)
            sum += a[i];
        else{
            cnt++;
            sum = a[i];
        }
    }
    return cnt <= k;
}

int main(){
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
        
    int l = a[0], r = 0;
    for(int i = 0; i < n; i++){
        if(a[i] > l) l = a[i];
        r += a[i];
    }

    int ans = r;

    while(l <= r){
        int mid = (l + r) / 2;

        if(check(mid, a, k)){
            ans = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }

    cout << ans;
    return 0;
}