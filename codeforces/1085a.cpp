#include <iostream>
#include<vector>
#include<map>
#include <string>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int val1=0,val2=0;
        int i=0;
        while(i<n){
            if(s[i]=='1'){
                int j=i;
                int val3=i;
                for(;j<n;j++) {
                    if (s[j]=='1'){
                        val3=j;
                    }
                    if((j+1<n)&& (s[j] == '0') && (s[j+1] == '0')){
                        break;
                    }
                }
                int l=val3-i+1;
                val2 =val2+l;
                val1 =val1+ (l/2)+1;
                i=j;
            }else{
                i++;
            }
        }
        cout<<val1<<" "<<val2<<endl;
    }
    return 0;
}