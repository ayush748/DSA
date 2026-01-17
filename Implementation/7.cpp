#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>>arr(n,vector<char>(m));
    bool flag=true;
    for(int i=0;i<n;i++){
        if(i%2==0){
            for(int j=0;j<m;j++){
                arr[i][j]='#';
            }
        }else{
            if(flag){
                arr[i][m-1]='#';
                for(int j=0;j<m-1;j++){
                    arr[i][j]='.';
                }
                flag=false;
            }else{
                arr[i][0]='#';
                for(int j=1;j<m;j++){
                    arr[i][j]='.';
                }
                flag=true;
            }

        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j];
        }
        cout<<endl;
    }
    return 0;
}