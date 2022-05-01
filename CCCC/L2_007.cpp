#include<bits/stdc++.h>
using namespace std;

struct peo{
    int ind=-1;
//     int home;
    int fa;
    int ma;
    int child[5]= {-1,-1,-1,-1,-1};
    int tao;
    double mj;
};
peo man[10005];
int n,i,j;
struct home{
    int name;
    int size;
    double tao;
    double mj;
};
vector<home> ans;
bool mcmp(home h1,home h2){
    if(h1.mj>h2.mj)
        return true;
    else if(h1.mj==h2.mj){
        return h1.name<h2.name;
    }else{
        return false;
    }
}
vector<set<int>> homes;

int main(){
    int k;
    cin>>n;
    for(i=0;i<n;i++){
        int index,f,m,cn,cind,taoshu,mianji;
        set<int> now;
        cin>>index;
        man[index].ind = index;
        cin>>f>>m;
        man[index].fa = f;
        man[index].ma = m;
        cin>>cn;
        for(j=0;j<cn;j++){
            cin>>cind;
            man[index].child[j] = cind;
            now.insert(cind);
        }
        cin>>taoshu>>mianji;
        man[index].tao = taoshu;
        man[index].mj = mianji;       
        now.insert(index);
        if(f!=-1)
            now.insert(f);
        if(m!=-1)
            now.insert(m);
        bool exi =false;
        int which = -1;
       for(int l=0;l<homes.size();l++){
           for(auto z=now.begin();z!=now.end();z++){
               if(homes[l].count(*z)){
                   exi = true;
                   which = l;
               }
           }
       }
        if(exi){
            for(auto z=now.begin();z!=now.end();z++){
                homes[which].insert(*z);
            }
        }else{
            homes.push_back(now);
        }
    }
    for(i=0;i<homes.size();i++){
        double summj=0.0,sumtao=0.0;
        int siz = homes[i].size();
        for(auto z=homes[i].begin();z!=homes[i].end();z++){
            summj+=man[*z].mj;
            sumtao +=man[*z].tao;
        }
        home temp;
        temp.name = *homes[i].begin();
        temp.size = siz;
        temp.tao = sumtao/siz;
        temp.mj = summj/siz;
        ans.push_back(temp);
    }
    sort(ans.begin(),ans.end(),mcmp);
    cout<<ans.size()<<endl;
    for(i=0;i<ans.size();i++){
        printf("%04d %d %.3f %.3f\n",ans[i].name,ans[i].size,ans[i].tao,ans[i].mj);
    }
    return 0;
}