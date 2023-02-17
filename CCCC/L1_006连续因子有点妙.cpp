#include<bits/stdc++.h>
using namespace std;
int n;
 
int main()
{
	cin>>n;
	int ans=0;
	int ansi=0;
	for(int i=2;i<=n/i;i++)//其中因子按递增顺序输出，1 不算在内。
	{
		if(n%i==0)
		{
			int t=i;
			int n1=n;
			int l=0;
			
			
			while(n1%t==0)
			{
				n1/=t;
				t++;
				l++;//最长连续因子的个数
			}
			
			if(ans<l)
			{
				ans=l;
				ansi=i;
			}
		}
	}
	if(ans==0)
	cout<<1<<endl<<n<<endl;
	else
	{
		cout<<ans<<endl;
	    for(int i=0;i<ans-1;i++)
    	cout<<ansi+i<<"*";
    	cout<<ansi+ans-1<<endl;
	}
 
	
	return 0;
}