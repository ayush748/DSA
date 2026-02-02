#include<iostream>
#include<vector>
using namespace std;
void solve(int n){
    int left=1;
    int right=n;
    int i=n-1;
    vector<int>arr(n);
    bool flag=true;
    while(i>=0){
        if(flag){
            arr[i]=left;
            left++;
        }else{
            arr[i]=right;
            right--;
        }
        if(flag){
            flag=false;
        }else{
            flag=true;
        }
        

        i--;
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        solve(n);
    }
    return 0;
}