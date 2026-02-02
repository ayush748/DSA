#include <iostream>
#include<climits>
#include<algorithm>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n,x,k;
	    cin>>n>>x>>k;
	    int val1=x%k;
	    int ans=val1;
	    if (val1!=0 && x+(k-val1)<=n) {
            ans = min(ans,k-val1);
        }
        ans = min(ans, x);
	    cout<<ans<<endl;
	}

}
