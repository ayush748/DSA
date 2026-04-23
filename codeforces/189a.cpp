#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long x, y;
        cin >> x >> y;

        bool flag = false;

        for(long long i=x+x;i<y;i=i+x){
            if(y%i!=0){ 
                flag = true;
                break;
            }
        }

        if(flag){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}