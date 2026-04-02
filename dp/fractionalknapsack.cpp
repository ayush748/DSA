#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int> val = {60,100,120};
    vector<int> wt  = {10,20,30};
    int W = 50;

    int n = val.size();

    // {ratio, index}
    vector<pair<double,int>> arr;

    for(int i=0;i<n;i++){
        double ratio = (double)val[i]/wt[i];
        arr.push_back({ratio,i});
    }

    sort(arr.rbegin(), arr.rend());

    double ans = 0.0;

    for(int i=0;i<n;i++){
        int idx = arr[i].second;

        if(W >= wt[idx]){
            ans += val[idx];
            W -= wt[idx];
        }else{
            ans += arr[i].first * W;
            W = 0;
            break;
        }
    }

    cout<<ans<<endl;
    return 0;
}