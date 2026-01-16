#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,k,l,c,d,p,nl,np;
    cin>>n>>k>>l>>c>>d>>p>>nl>>np;

    int val1=k*l;
    int val2=val1/nl;
    int val3=c*d;
    int val4=p/np;
    int ans=min(val2,min(val3,val4));
    cout<<ans/n<<endl;
    return 0;
}