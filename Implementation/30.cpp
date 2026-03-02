#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int count=0;
    while(m>n){
        if(m%3==0){
            m=m/3;
        }else if(m%2==0){
            m=m/2;
        }else{
            cout<<"-1"<<endl;
            return 0;
        }
        count++;
    }
    if(m == n)
        cout << count;
    else
        cout << -1;
    return 0;
}