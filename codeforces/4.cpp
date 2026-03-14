#include <iostream>
#include <algorithm>
using namespace std;
bool check(long long a, long long b, long long c, long long m) {
    if (a==0){
        return b==0;
    }
    if (b<a){
        return false;
    }
    if (m==1){
        if(c==1){
            return false;
        }
        bool flag=(b>=2*a && b<=c*a);
        return flag;
    }
    if (m==c){
        bool flag=(b>=a && b<=(c-1)*a);
        return flag;
    }
    long long x=(b-a)/m;
    long long y1=b-a*(m-1);
    long long y2=c-m+1;
    long long y=0;
    if (y1>0){
        y=(y1+y2-1)/y2;
    }
    bool flag=max(0LL, y) <= min(a, x);
    return flag;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        long long a,b,c,m;
        cin>>c>>a>>b>>m;
        for (long long i=0;i<=a;i++) {
            long long k=a-i;
            long long s=b-i*m;

            if(check(k,s,c,m)){
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}