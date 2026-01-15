#include <iostream>
#include<vector>
using namespace std;
int main() {
    int n,k;
    cin>>n>>k;
    vector<bool>arr(n+1,true);
    arr[0]=arr[1]=false;
    for (int i=2;i*i<=n;i++){
        if (arr[i]){
            for (int j=i*i;j<=n;j=j+i){
                arr[j] = false;
            }
        }
    }
    vector<int>brr;
    for (int i=2;i<=n;i++){
        if (arr[i]){
            brr.push_back(i);
        }
    }
    int count=0;
    for(int i=1;i<brr.size();i++){
        int sum=brr[i]+brr[i-1]+1;
        if(sum<=n && arr[sum]){
            count++;
        }
    }
    if(count>=k){
        cout<<"Yes"<<endl;
    }else{
        cout<<"NO"<<endl;
    }   
    return 0;
}
// pair wali approach


