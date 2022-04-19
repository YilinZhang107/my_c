#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int num[1005];
vector<int> v;
int flag;

void  find(int l,int r){
    if(l>r) return ;
    int l1 = l+1,r1 = r;
    if(flag){
        while (l1 <= r && num[l1] < num[l]) l1++;
		while (r1 > l && num[r1] >= num[l]) r1--;
        // while(num[l1]<num[l])l1++;  要考虑当前这个树的区间
        // while(num[r1]>=num[l])r1--;
    }else{
        while(l1 <= r && num[l1]>=num[l])l1++;
        while(r1 > l && num[r1]<num[l])r1--;
    }
    if(r1 != l1-1)  return;
    find(l+1,r1);
    find(l1, r);
    v.push_back(num[l]);
    return;
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%d", &num[i]);
    }
    flag = 1;
    find(0,n-1);
    if(v.size()!=n){
        flag=0;
        v.clear();
        find(0,n-1);
    }
    if(v.size()!= n)
        cout<<"NO";
    else{
        cout<<"YES"<<endl;
        for(int i=0;i<n;i++){
            if(i==0)
                cout<<v[i];
            else
                cout<<" "<<v[i];
        }
    }
    return 0;
}