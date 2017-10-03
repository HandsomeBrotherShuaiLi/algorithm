#include<iostream>
#include<vector>
using namespace std;
void greedy_jiayou(vector<int> d,int n,int k)
{
	int num=0;
	int s=0;
	for(int i=0;i<=k;i++)
		if(d[i]>n)
		{
			cout<<"No solution"<<endl;
			break;
		}
    for(int i=0;i<=k-1;i++)
	{
		s+=d[i];
		if(s<=n&&s+d[i+1]>n)
		{
			num++;
			s=0;
		}
	}
	cout<<num<<endl;
}
int main()
{
	vector<int> d;
	int n,k;
	cin>>n>>k;
	int x;
	for(int i=0;i<=k;i++)
	{
		cin>>x;
		d.push_back(x);
	}
	greedy_jiayou(d,n,k);
	system("pause");
	return 0;
}
