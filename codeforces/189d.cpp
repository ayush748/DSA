#include<iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n,x;
		cin>>n>>x;
		long long mod=998244353;
		long long a,b,c,d;
		if(x-1<1)
		{
			a=0;
		}
		else
		{
			a=(x-2)/4+1;
		}
		b=(x-1<3)?0:(x-4)/4+1;
		b=(b+1)%mod;
		long long t1,t2;
		t1=(n<1)?0:(n-1)/4+1;

		if(x-1<1)
		{
			t2=0;
		}
		else
		{
			t2=(x-2)/4+1;
		}
		c=(t1-t2)%mod;
		if(c<0)
		{
			c+=mod;
		}
		long long t3,t4;
		if(n<3)
		{
			t3=0;
		}
		else
		{
			t3=(n-3)/4+1;
		}
		t4=(x-1<3)?0:(x-4)/4+1;
		d=(t3-t4)%mod;
		if(d<0)
		{
			d+=mod;
		}
		long long ans=((a%mod*c%mod)%mod+(b%mod*d%mod)%mod)%mod;

		cout<<ans<<endl;
	}
	return 0;
}