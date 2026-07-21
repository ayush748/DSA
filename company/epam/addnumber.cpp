#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int m;
    cin>>m;
    vector<int>brr(m);
    for(int i=0;i<m;i++){
        cin>>brr[i];
    }
    int carry=0;
    int i=0;
    int j=0;
    // carry divide
    // mod sum
    vector<int>ans;
    while(i<n && j<m ){
        int sum=arr[i]+brr[j]+carry;
        // carry ki divide
        carry=sum/10;
        // arr me store %
        int val=sum%10;
        ans.push_back(val);
        i++;
        j++;
    }
    while(i<n){
        int sum=arr[i]+carry;
        carry=sum/10;
        int val=sum%10;
        ans.push_back(val);
        i++;
    }
    while(j<m){
        int sum=brr[i]+carry;
        carry=sum/10;
        int val=sum%10;
        ans.push_back(val);
        j++;
    }
    if(carry!=0){
        ans.push_back(carry);
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}