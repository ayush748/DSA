#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int solve(string a,string b,string c){
    int n=a.size();
    int val1=0;
    int start=0;
    int val2=0;
    int x1=0;
    int x2=val1;
    int x3=start;
    for(int i=0;i<n;i++){
        int x=b[i]-'0';
        int y=c[i]-'0';
        int val3=x-y;
        val1=val1+val3;
        
        if(a[i] == '1'){
            start=start+val3;
        }
    }
    x2=val1;
    x3=start;
    if (x1 > x2){
        swap(x1, x2);
    }
    if (x2 > x3){
        swap(x2, x3);
    }
    if (x1 > x2){
        swap(x1, x2);
    }
    int last=x2;
    int ans=val2+ abs(last- start)+ abs(last)+abs(val1 - last);
    return ans;
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    string a,b,c;
	    cin>>a>>b>>c;
	    
	    int ans=solve(a,b,c);
	    cout<<ans<<endl;
	    
	}
}
