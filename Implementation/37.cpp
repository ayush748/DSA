#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    int sum=n;
    for(int i=0;i<n;i++){
        sum=sum+(n-i)*i;
    }
    cout<<sum<<endl;
    return 0;
}