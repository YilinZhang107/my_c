#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define MAX 0x3f
int n,m,k;
int quan[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
char ma[11] = {'1','0','X','9','8','7','6','5','4','3','2'};
int main(){
    cin>>n;
    string s;
	bool you = false;
    for(int i=0;i<n;i++){
        cin>>s;
		int sum  = 0;
		for(int j=0;j<17;j++){
			sum += quan[j]*(s[j]-'0');
			
		}
		sum %= 11;
		if(s[s.size()-1] != ma[sum]){
			cout<<s<<endl;
			you = true;
		}
    }	
    if(!you){
    	cout<<"All passed";
	}
    return 0;
}