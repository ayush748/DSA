#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int>>arr(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]==-1){
                arr[i][j]=1e9;
            }
        }
        arr[i][i]=0;
    }
    for(int via=0;via<n;via++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                arr[i][j]=min(arr[i][j],arr[i][via]+arr[via][j]);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]==1e9){
                arr[i][j]=-1;
            }
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}