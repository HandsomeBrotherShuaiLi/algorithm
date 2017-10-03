#include<iostream>
#include<cstring>
using namespace std;
int max(int a,int b)
{
	return(a>b?a:b);
}
int min(int a,int b)
{
	return (a<b?a:b);
}
int main()
{
	int a[10],b[10];
	int t[100][100][10];
	int n;
	cin>>n;
	memset(t,0,sizeof(t));
	int suma=0,sumb=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		suma+=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
		sumb+=b[i];
	}
	t[0][0][0]=1;
	for(int k=1;k<=n;k++)
		for(int i=0;i<=suma;i++)
			for(int j=0;j<=sumb;j++)
			{
				if(i>=a[k]&&t[i-a[k]][j][k-1])
					t[i][j][k]=1;
				if(j>=b[k]&&t[i][j-b[k]][k-1])
					t[i][j][k]=1;
			}
			int ans=0x7FFFFFFF;//ans要是一个足够大的数，否则不行。
	for(int i=0;i<=suma;i++)
		for(int j=0;j<=sumb;j++)
			if(t[i][j][n])
				ans=min(ans,max(i,j));
	cout<<ans<<endl;
	system("pause");
	return 0;
}


