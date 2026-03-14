#include<iostream>
#include<vector>
#include<climits>
using namespace std;

void solve()
{
	int a;
	cin>>a;
	vector<int>arr(a+1);
	vector<int>crr;

	int b=1;
	while(b<=a)
	{
		cin>>arr[b];
		b++;
	}

	if(arr[1]>a)
	{
		cout<<"NO"<<endl;
		return;
	}

	b=1;
	while(b<=a)
	{
		int val1=arr[b];
		if(val1<a-b)
		{
			cout<<"NO"<<endl;
			return;
		}
		b++;
	}

	b=2;
	while(b<=a)
	{
		int val1=arr[b];
		if(val1>arr[b-1])
		{
			cout<<"NO"<<endl;
			return;
		}
		b++;
	}

	cout<<"YES"<<endl;

	int val2=arr[1];
	vector<bool>brr(val2+1,false);

	b=1;
	while(b<=a)
	{
		int val1=arr[b];
		brr[val1]=true;
		b++;
	}

	b=0;
	while(b<arr[1])
	{
		if(!brr[b])
		{
			crr.push_back(b);
		}
		b++;
	}

	int c=0;
	int d=INT_MAX;
	vector<int>drr(a+1);

	b=a;
	while(b>=2)
	{
		if(arr[b-1]==arr[b])
		{
			drr[b]=crr[c];
			c++;
		}
		else
		{
			drr[b]=d;
			d--;
		}
		b--;
	}
	if(c<(int)crr.size())
	{
		drr[1]=crr[c];
		c++;
	}
	else
	{
		drr[1]=d;
		d--;
	}
	b=1;
	while(b<=a)
	{
		cout<<drr[b];
		if(b!=a)
		{
			cout<<" ";
		}
		b++;
	}
	cout<<endl;
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