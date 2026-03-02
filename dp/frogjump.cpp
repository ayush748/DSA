#include <iostream>
#include <vector>
using namespace std;
void solve(){
    int n;
    cin>>n;
    long long val1=1;
    int i=2;
    while((i*i)<=n){
        if(n%i==0){
            val1=val1*i;
            while(n%i==0){
                n=n/i;
            }
        }
        i++;
    }
    val1=n>1?n*val1:val1;
    cout<<val1<<endl;
    
}
int main() {
    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}