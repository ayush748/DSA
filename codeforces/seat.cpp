//File Name: CTC92034.cpp
//==================================
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
void solve(int t){

	vector<vector<int>>ra(t,vector<int>(2));
	for(int i=0;i<t;i++){
		for(int j=0;j<2;j++){
			cin>>ra[i][j];
		}
	}

	
	for(int i=0;i<t;i++){
		int l=ra[i][0];
		int r=ra[i][1];
		
		vector<bool>arr(r+1,true);
		arr[0]=false;
		arr[1]=false;
		for(int i=2;i*i<=r;i++){
			if(arr[i]){
				for(int j=i*i;j<=r;j=j+i){
					arr[j]=false;
				}
			}
		}
		int cnt=0;
		for(int i=l;i<=r;i++){
			// cout<<i<<" "<<arr[i]<<endl;
			if(arr[i]){
				// cout<<i<<" ";
				cnt++;
			}
		}
	
		// cout<<endl;
		cout<<cnt<<endl;
	}
	
}
int main(){
	int t;
	cin>>t;
	

	solve(t);
	
	return 0;
}