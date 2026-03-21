#include<iostream>
using namespace std;
int solve(int u, int v) {
    cout<< "? "<<u<<" "<<v<<endl;
    int r;
    cin >> r;
    return r;
}
int main(){
    int t;
    cin>>t;
    while (t>0){
        int n;
        cin>>n;
        int a=2*n;
        if(solve(1,2)==1){
            a=1;
        }
        else if(solve(2,3)==1){
            a=2;
        }
        else if(solve(3,1)==1){
            a = 3;
        }
        else {
            int i=4;
            while(i<2*n) {
                if(solve(i,i+1)==1){
                    a=i;
                    break;
                }
                i=i+2;
            }
        }
        cout<<"! "<<a<<endl;
        t--;
    }
    return 0;
}