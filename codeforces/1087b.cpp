#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void solve(vector<long long> arr){
	int n=arr.size();
	for(int i=0;i<n;i++){
		vector<long long>a;
		vector<int>b;
		int c=0;
		for(int j=i+1;j<n;j++){
			if(arr[i]==arr[j]){
				continue;
			}
			long long d=arr[i]+arr[j];
			if(arr[j]<arr[i]){
				c++;
				a.push_back(d);
				b.push_back(-1);
			}else{
				a.push_back(d);
				b.push_back(1);
			}
		}
		int m=a.size();
		vector<int> crr(m);
		for(int k=0;k<m;k++){
			crr[k]=k;
		}
		sort(crr.begin(),crr.end(),[&](int x,int y){
			return a[x]<a[y];
		});
		int e=c;
		int k=0;
		while(k<m){
			long long x=a[crr[k]];
			int s=0;
			while(k<m && a[crr[k]]==x){
				s+=b[crr[k]];
				k++;
			}
			c+=s;
			e=max(e,c);
		}
		cout<<e<<" ";
	}
	cout<<endl;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<long long> arr(n);
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		solve(arr);
	}
	return 0;
}