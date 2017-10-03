#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct time{
	int s;
	int f;
	int  no;//会场编号
	bool anpai;//后面接了其他活动就是true,其他就是false;
	time()
	{  no=0;
	   anpai=false;
	}
};
bool comp(time a,time b)
{
	if(a.s<b.s)
		return true;
	else if(a.s==b.s)
		return a.f<b.f;
	else
		return false;
}
int greedy(vector<time> p)
{
	 int len=p.size();
	 sort(p.begin(),p.end(),comp);
     int sum=1;
	 p[0].no=1;
	 
	 for(int i=1;i<len;i++)
	 {
		 int j=0;
	 for(;j<i;j++)
	 {
		 if(p[j].anpai==false&&p[j].f<p[i].s)
		 {
			 p[i].no=p[j].no;
			 p[j].anpai=true;//安排好了后面的活动，就不再考虑下一次为此活动接后续活动。
		    break;
		 }
	 }
	 if(j==i)
	 {
		 sum+=1;
		 p[i].no=sum;
	 }
	 }
	 return sum;
}




int main()
{
	int k;
	vector<time> p;
	cin>>k;
	for(int i=0;i<k;i++)
	{
		time h;
		cin>>h.s>>h.f;
		p.push_back(h);
	}
   cout<<greedy(p)<<endl;
	system("pause");
	return 0;
}

