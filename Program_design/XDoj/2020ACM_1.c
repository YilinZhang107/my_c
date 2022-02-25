#include<stdio.h>
int main()
{
    int n;//同学个数
    scanf("%d",&n);
    char rans1[5], rans2[5];//甲乙两份题目的正确答案
    int i;
    char sc;
    for(i = 0; i<6 ;i++){
        scanf("%c",&sc);
        if(sc!=10) 
            rans1[i-1]=sc;
    }
    for(i = 0; i<6; i++){
        scanf("%c",&sc);
        if(sc!=10) 
            rans2[i-1]=sc;
    }
    char ans[n][5];
    for(i = 0; i<n; i++)
    {
        for(int j = 0; j<6; j++){
            scanf("%c",&sc);
            if(sc!=10)
                ans[i][j-1]=sc;
        }    
    }
    for(i = 0; i<n; i++)//循环各个答案，与标准答案比较
    {
        int rightN1 = 0,rightN2 = 0;
        for(int j = 0; j<5; j++)
        {
            if(rans1[j]==ans[i][j])
                rightN1++;
        }
        for(int j = 0; j<5; j++)
        {
            if(rans2[j]==ans[i][j])
                rightN2++;
        }
        if(rightN1>rightN2)
            printf("%d\n",rightN1);
        else
            printf("%d\n",rightN2);
    }
    return 0;
}