#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a,b;
		long long c;
		cin>>a>>b>>c;
		vector<long long>arr(a);
		int i=0;
		while(i<a)
		{
			cin>>arr[i];
			i++;
		}
		vector<long long>brr(b+1,0);
		vector<long long>drr(b+1,0);
		vector<long long>err(b+1,0);
		long long d=0;
		i=0;
		while(i<=a)
		{
			long long e=(i<a)?arr[i]:c;
			long long f=e-d;
			d=e;
			int j;
			for(j=1;j<=b;j++)
			{
				brr[j]+=f;
				drr[j]+=f;
			}
			err[0]=0;
			j=1;
			while(j<=b)
			{
				err[j]=err[j-1]+brr[j];
				drr[j]=min(drr[j],err[j]);
				j++;
			}
			if(i<a)
			{
				vector<long long>frr(b+1,0);
				j=1;
				while(j<b)
				{
					long long g=drr[j+1];
					long long h=0,k=brr[1];
					long long l=g;
					for(;h<=k;)
					{
						long long m=h+(k-h)/2;
						int n=1,o=j+1;
						int p=0;
						for(;n<=o;)
						{
							int q=n+(o-n)/2;
							if(brr[q]>=m)
							{
								p=q;
								n=q+1;
							}
							else
							{
								o=q-1;
							}
						}
						long long r=1LL*p*m+(err[j+1]-err[p]);
						if(r>=g)
						{
							l=m;
							k=m-1;
						}
						else
						{
							h=m+1;
						}
					}
					frr[j]=g-l;
					j++;
				}
				frr[b]=(b>1)?frr[b-1]:0;
				for(j=1;j<b;j++)
				{
					brr[j]=brr[j+1];
				}
				brr[b]=0;
				err[0]=0;
				for(j=1;j<=b;j++)
				{
					err[j]=err[j-1]+brr[j];
				}
				j=1;
				while(j<=b)
				{
					drr[j]=min(frr[j],err[j]);
					j++;
				}
			}
			i++;
		}

		cout<<drr[1]<<'\n';
	}
}