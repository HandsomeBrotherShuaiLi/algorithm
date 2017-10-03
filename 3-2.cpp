#include<iostream>
#include<string>
using namespace std;
int min(int a,int b)
{
	return (a<b?a:b);
}

int edit(string a,string b)
{
	int lena=a.length();
	int lenb=b.length();
	//int p[lena+1][lenb+1];
	int **p=new int*[lena+1];
	for(int i=0;i<lena+1;i++)
	{
		p[i]=new int[lenb+1];
	}
	
	for(int i=0;i<lena+1;i++)
		p[i][0]=i;
	for(int j=0;j<lenb+1;j++)
		p[0][j]=j;
	
	for(int i=1;i<=lena;i++)
		for(int j=1;j<=lenb;j++)
		{
			int tmp=min(p[i-1][j]+1,p[i][j-1]+1);
			int tmp1;
			if(a[i-1]==b[j-1])
			 tmp1=p[i-1][j-1];
			else
				tmp1=p[i-1][j-1]+1;
			p[i][j]=min(tmp,tmp1);
		}
		return p[lena][lenb];
}
int main()
{
	string a,b;
	cin>>a>>b;
	cout<<edit(a,b)<<endl;
	system("pause");
	return 0;
}