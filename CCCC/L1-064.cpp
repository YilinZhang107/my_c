#include<bits/stdc++.h>
using namespace std;

//应该加一个check是否是单独字符串
int check(const char *str,int i,int n){
		if((i==0||s[i-1]>'z' || (s[i-1]<'a' && s[i-1]!='I')) && ((i+n)>=s.length()||s[i+n]>'z' || (s[i+n]<'a' && s[i+n]!='I')))
		return 1;
		return 0;
}//判断字符串是否独立 

int main(){
	int n;
	cin>>n;
	getchar();
	vector<string> ans, ans1;
	for(int i=0; i<n; i++){
		string s;
		getline(cin, s);
		ans.push_back(s);
	}
	
	
	for(int i=0; i<n;i++){
		cout<<ans[i]<<endl;
		
		//去首尾
		while(ans[i][0] == ' ')
			ans[i].erase(0, 1);
		int len = ans[i].size()-1;
		int number = 0;
		while(ans[i][len] == ' '){
			len--;
			number++;
		}	
		ans[i].erase(len+1,number); 
			
		
		for(int j=0; j<ans[i].size(); j++){
			if((ans[i][j] ==',' || ans[i][j] =='.'|| ans[i][j] =='!' || ans[i][j] =='?' || ans[i][j] =='\'' ) && ans[i][j-1] ==' '){
				while(ans[i][j-1] == ' ' && j-1>=0){
					ans[i].erase(j-1, 1);
					j--;
				}
			}
			if(ans[i][j] >='A' && ans[i][j] <= 'Z' && ans[i][j] !='I')
				ans[i][j] -= 'A'-'a';
			
		}
		for(int j=0; j<ans[i].size(); j++){
			if(ans[i][j] ==' ' && ans[i][j+1] == ' '){
				while(ans[i][j+1] == ' '){
					ans[i].erase(j, 1);
				}
			}
		}
		
		while(ans[i].find("I") != string::npos){
			ans[i].replace(ans[i].find("I"), 1, "you");
		}
		while(ans[i].find("me") != string::npos){
			ans[i].replace(ans[i].find("me"), 2, "you");
		}
		
		while(ans[i].find("can you") != string::npos){
			ans[i].replace(ans[i].find("can you"), 7, "I can");
		}
		while(ans[i].find("could you") != string::npos){
			ans[i].replace(ans[i].find("could you"), 9, "I could");
		}
		while(ans[i].find("?") != string::npos){
			ans[i].replace(ans[i].find("?"), 1, "!");
		}
		
		if(i != n-1)	
			cout<< "AI: "<<ans[i]<<endl;
		else 
			cout<<"AI: "<<ans[i];
	}
	
	return 0;
}