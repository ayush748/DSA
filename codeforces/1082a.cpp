#include<iostream>
#include<vector>
#include<string>
using namespace std;
void solve(int x,int y){
    bool flag=true;
    int val=x-(2*y);
    int k=val/3;
    if(val%3!=0){
        cout<<"No"<<endl;
    }else{
        if(y>=0){
            if(k>=0){
                cout<<"Yes"<<endl;
            }else{
                cout<<"No"<<endl;
            }
        }else{
            if(k>= -2*y){
                cout<<"Yes"<<endl;
            }else{
                cout<<"No"<<endl;
            }
        }
    }

}
int main(){
    int t;
    cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
        solve(x,y);
    }
    return 0;
}