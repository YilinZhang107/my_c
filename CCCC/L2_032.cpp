#include<bits/stdc++.h>
using namespace std;

//要注意一定要让他输入完整(哭笑...)
//不能错误了马上退出

int main(){
	int n, max, k;
	cin>>n>>max>>k;
	vector<bool> ans;
	for(int i=0; i<k; i++){
		int need = 1;
        bool yes =  1;
        stack<int> jia;
		for(int j=0; j<n; j++){
			int t;
			cin>>t;
			while(!jia.empty() && jia.top() == need){
				jia.pop();
				need++;
				//cout<<"qu ";
			}
			
			if(t == need){
				need++;
				//out<<"hanghao ";
			}
			else{
				if(jia.size() == max){
                    yes = 0;
					continue;
				}
				else{
					//cout<<"jin ";
					jia.push(t);
				}
			}
			while(!jia.empty() && jia.top() == need){
				jia.pop();
				need++;
			}
		}
		if(jia.empty() && yes){
			ans.push_back(1);
		}
		else
			ans.push_back(0);
	}
	for(int i=0; i<k; i++){
		if(i!=k-1){
			if(ans[i])
			cout<<"YES"<<endl;
			else
			cout<<"NO"<<endl;
		}
		else{
			if(ans[i])
			cout<<"YES";
			else
			cout<<"NO";
		}
		
	}
	return 0;
	
}


