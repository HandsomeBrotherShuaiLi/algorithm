/*#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#define N 100
using namespace std;
int fmin(int* p,int n)//求最小值
{
	int m[N][N];
	memset(m,-1,(n+1)*(n+1));
	
	for(int i=1;i<=n;i++)
		m[i][i]=0;
	for(int i=1;i<=n-1;i++)
	{
		m[i][i+1]=p[i]+p[i+1];
	}
	for(int r=3;r<=n;r++)
		for(int i=1;i<=n-r+1;i++)
		{
			int j=i+r-1;
			int sum=0;
			for(int b=i;b<=j;b++)
				sum+=p[b];
			m[i][j]=m[i+1][j]+sum;
			for(int k=i+1;k<j;k++)
			{
				int t=m[i][k]+m[k+1][j]+sum;
				if(t<m[i][j])
					m[i][j]=t;
			}
		}
			return m[1][n];
}
int fmax(int *p,int n)//最大值
{
	int m[N][N];
	memset(m,-1,(n+1)*(n+1));

	for(int i=1;i<=n;i++)
		m[i][i]=0;
	for(int i=1;i<=n-1;i++)
	{
		m[i][i+1]=p[i]+p[i+1];
	}
	for(int r=3;r<=n;r++)
		for(int i=1;i<=n-r+1;i++)
		{
			int j=i+r-1;
			int sum=0;
			for(int b=i;b<=j;b++)
				sum+=p[b];
			m[i][j]=m[i+1][j]+sum;
			for(int k=i+1;k<j;k++)
			{
				int t=m[i][k]+m[k+1][j]+sum;
				if(t>m[i][j])
					m[i][j]=t;
			}
		}
			return m[1][n];
}
int  MatrixChain_max(int p[N],int n)
{
       int m[N][N];
         for(int x=1;x<=n;x++)
        for(int z=1;z<=n;z++)
        {
            m[x][z]=-1;           
        }


     int max=0;
     //一个独自组合时
    for(int g = 1;g<=n;g++) m[g][g]=0;
    //两个两两组合时
    for(int i=1;i<=n-1;i++)
    {
        int j=i+1;
        m[i][j]=p[i]+p[j];
    }

    for(int r=3; r<=n;r++)
         for(int i=1;i<=n-r+1;i++)
         {
             int j = i+r-1;
             int sum=0;
             for(int b=i;b<=j;b++)
                 sum+=p[b];
             m[i][j] = m[i+1][j]+sum;
             
             for(int k=i+1;k<j;k++)
             {
                 int t=m[i][k]+m[k+1][j]+sum;
                 if(t>m[i][j])
                     m[i][j] = t;

             }
         }

         max=m[1][n];
         return max;

        
}
int main()
{
	int n;
	cin>>n;
	int* t=new int[n+1];
	for(int i=1;i<=n;i++)
		cin>>t[i];

	vector<int>maxn;
	vector<int>minn;
	maxn.push_back(MatrixChain_max(t,n));
	minn.push_back(fmin(t,n));
	for(int i=2;i<=n;i++)
	{
		int start=t[1];
		int z=2;
		for(;z<=n;z++)
			t[z-1]=t[z];
		t[z]=start;
		maxn.push_back(MatrixChain_max(t,n));
		minn.push_back(fmin(t,n));
	}
	cout<<*min_element(minn.begin(),minn.end())<<endl;
	cout<<*max_element(maxn.begin(),maxn.end())<<endl;
	system("pause");
	return 0;
}

*/
#include <iostream>  
#include <string.h>  
#include <stdio.h>  
  
using namespace std;  
const int INF = 1<<30;  
const int N = 205;  
  
int mins[N][N];  
int maxs[N][N];  
int sum[N],a[N];  
int minval,maxval;  
int n;  
  
int getsum(int i,int j)  
{  
    if(i+j >= n) return getsum(i,n-i-1) + getsum(0,(i+j)%n);  
    else return sum[i+j] - (i>0 ? sum[i-1]:0);  
}  
  
void Work(int a[],int n)  
{  
    for(int i=0;i<n;i++)  
        mins[i][0] = maxs[i][0] = 0;  
    for(int j=1;j<n;j++)  
    {  
        for(int i=0;i<n;i++)  
        {  
            mins[i][j] = INF;  
            maxs[i][j] = 0;  
            for(int k=0;k<j;k++)  
            {  
                mins[i][j] = min(mins[i][j],mins[i][k] + mins[(i+k+1)%n][j-k-1] + getsum(i,j));  
                maxs[i][j] = max(maxs[i][j],maxs[i][k] + maxs[(i+k+1)%n][j-k-1] + getsum(i,j));  
            }  
        }  
    }  
    minval = mins[0][n-1];  
    maxval = maxs[0][n-1];  
    for(int i=0;i<n;i++)  
    {  
        minval = min(minval,mins[i][n-1]);  
        maxval = max(maxval,maxs[i][n-1]);  
    }  
}  
  
int main()  
{  
    while(scanf_s("%d",&n)!=EOF)  
    {  
        for(int i=0;i<n;i++)  
            scanf_s("%d",&a[i]);  
        sum[0] = a[0];  
        for(int i=1;i<n;i++)  
            sum[i] = sum[i-1] + a[i];  
        Work(a,n);  
        printf("%d %d\n",minval,maxval);  
    }  
    return 0;  
}  


	

