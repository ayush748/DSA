#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void solve(int n){
	vector<long long>err(n);
	vector<long long>brr(n);
	int i=0;
	while(i<n){
        cin>>err[i];
        i++;
    }
	i=0;
	while(i<n){
        cin>>brr[i];
        i++;
    }

	vector<pair<long long,long long>>mp(n);
	for(i=0;i<n;i++){
        mp[i]={err[i],brr[i]};
    }
	sort(mp.begin(),mp.end());

	for(i=0;i<n;i++){
		err[i]=mp[i].first;
		brr[i]=mp[i].second;
	}

	vector<long long> crr(n+1,0);
	i=0;
	while(i<n){
        crr[i+1]=crr[i]+brr[i];
        i++;
    }

	long long c=0;
	i=0;
	while(i<n){
		if(i>0 && err[i]==err[i-1]){
            i++; 
            continue;
        }
		long long a=err[i];
		long long b=n-i;
		int l=0,r=n,ans=0;
		while(l<=r){
			int m=(l+r)/2;
			if(crr[m]<=b){
				ans=m;
				l=m+1;
			}else r=m-1;
		}
        long long val=a*ans;
		if(ans>0 && val>c){
            c=a*ans;
        }
		i++;
	}
	cout<<c;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		solve(n);
        cout<<endl;
	}
	return 0;
}
