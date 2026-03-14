#include<iostream>
#include<vector>
#include<deque>
#include<climits>
using namespace std;

void solve2(int a,int b,int c,vector<vector<int>>&arr,vector<int>&deg,vector<int>&src,vector<int>&dist)
{
	deque<pair<int,int>>drr;
	int i=1;
	while(i<=a)
	{
		if(deg[i]==1)
		{
			dist[i]=0;
			drr.push_back(make_pair(i,0));
		}
		i++;
	}

	while(!drr.empty())
	{
		pair<int,int>err=drr.front();
		drr.pop_front();
		int e=err.first;
		int f=err.second;

		if(f!=dist[e])
		{
			continue;
		}
		if(f>=b)
		{
			continue;
		}

		int g=0;
		while(g<(int)arr[e].size())
		{
			int h=arr[e][g];

			if(dist[h]==0)
			{
				g++;
				continue;
			}
			if(f+1<dist[h])
			{
				dist[h]=f+1;
				src[h]=e;
				drr.push_back(make_pair(h,f+1));
			}
			else if(src[h]!=e && f+1<=b)
			{
				dist[h]=0;
				src[h]=-1;
				drr.push_front(make_pair(h,0));
			}
			g++;
		}
	}
}
void solve()
{
	int a,b,c;
	cin>>a>>b>>c;
	vector<vector<int>>arr(a+1);
	vector<int>deg(a+1,0);
	int i=0;
	while(i<a-1)
	{
		int d,e;
		cin>>d>>e;
		arr[d].push_back(e);
		arr[e].push_back(d);
		deg[d]++;
		deg[e]++;
		i++;
	}
	vector<int>dist(a+1,INT_MAX);
	vector<int>src(a+1,-1);
	solve2(a,b,c,arr,deg,src,dist);
	cout<<(dist[c]==0?"YES":"NO")<<endl;
}
int main()
{
	int a;
	cin>>a;
    while(a--)
    {
        solve();
    }
	
	return 0;
}