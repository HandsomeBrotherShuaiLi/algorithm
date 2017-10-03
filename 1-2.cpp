#include<iostream>
#include<vector>
#include<cstring>
#include<string>
using namespace std;
int f(int n)//n!方程
{      
    int ans=1;
	for(int i=1;i<=n;i++)
	  ans*=i;
	  return ans; 
 } 
int main()
{
	int num[27][7];//以第I个字母为首字母的J长的字符串一共多少个 
	int sum[7];//j个长度的字符串一共有多少个 
	memset(num,0,sizeof(num));
	memset(sum,0,sizeof(sum));
	for(int i=1;i<=26;i++)
	for(int j=1;j<=6;j++)
	{
	  num[i][j]=f(26-i)/(f(j-1)*f(27-i-j));	
	}
	for(int j=1;j<=6;j++)
	for(int i=1;i<=26;i++)
	sum[j]+=num[i][j];
	cout<<"input.txt"<<endl;
	int n;
	string s;
	vector<int>location;
	cin>>n;
	for(int i=0;i<n;i++)
   {
	cin>>s;
	int loc=0;
	for(int i=1;i<s.length();i++)
	loc+=sum[i];
	char ch='a';
    for(int i=1;i<s[0]-'a'+1;i++)
	loc+=num[i][s.length()];
	for(int j=1;j<s.length();j++)
	for(int i=s[0]-'a'+1+j;i<s[j]-'a'+1;i++)
	loc+=num[i][s.length()-j];
	location.push_back(loc+1);
	} 
	cout<<"output.txt"<<endl;
    for(int i=0;i<location.size();i++)
    cout<<location[i]<<endl;
    return 0;
}



	
		
		
	  
	  
