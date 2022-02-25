#include<stdio.h>
int main()
{
    char n1[21], n2[20], sym;//sym：存储运算符号
    int i,l;//开辟内存空间。i：第一个数位数，l：第二个数位数
    printf("请输入您想要计算的算式：(如：1+1，数字在20位以内)\n");
    for(i = 0; i<20; i++)//利用循环进行输入
    {
        scanf("%c",&n1[i]);
        if(n1[i]>47&&n1[i]<58)//正常输入时对字符进行转化
            n1[i]-=48;
        else if (n1[i]==43)//输入符号后停止，开始第二个数输入
        {
            sym = 43;  //加号
            break;
        }
        else if (n1[i]==45)
        {
            sym = 45;  //减号
            break;
        }
        else//出现不符合格式的输入后停止输入
        {
            printf("您输入的格式有误，请重新开始！");
            return 0;
        }
    }
    for(l = 0; l<20; l++) //对第二个数的输入
    {
        scanf("%c",&n2[l]);       
        if(n2[l]>47&&n2[l]<58)
            n2[l]-=48;
        else if(n2[l]==10)  //输入回车停止输入
            break;
        else
        {
            printf("您输入的格式有误，请重新开始！");
            return 0;
        }
    }
    int biger = 0;//判断是否后数大于前数 若是则需要在结果前加负号
    if(l==i)//位数相同时判断是否第二数大于第一个数
    {
        for(int j = 0; j<l; j++)
            if(n1[j]<n2[j])
            {
                biger = 2;
                break;
            }
    }
    if(l>i||biger == 2)//当输入的第二个数大于第一个数时，将大数放在前面，便于计算   
    { 
        char n;//暂时存储数字
        for(int j = 0; j<l; j++)//进行转换
        {
            n = n1[j];
            n1[j] = n2[j];
            n2[j] = n;
        }
        int t;//两个字符数组的大小也进行交换
        t = i;
        i = l;
        l = t;
        biger = 1;
    }
    int up;//判断是否有进位
    switch (sym)//检测输入的符号，分别计算
    {
        case 43://是加号，进行加法运算
            for(int j=i-1, k=l-1; j>=0; j--,k--)//从末尾开始计算，模拟人工
            {
                up=n1[j]+n2[k];//储存相同位相加的数
                if(up>9)//大于9需要进位
                {
                    n1[j-1]++;
                    n1[j] = up-10;
                    if(j-1<0)
                        up=-1;
                }
                else//不大于9直接更改n1数组中的数
                    n1[j] = up;
            }
            break;
        case 45://执行减法
            for(int j=i-1, k=l-1; j>=0; j--,k--)//从末尾开始计算
            {
                if(n1[j]-n2[k]<0)//当不够减时从前一位借10
                {
                    n1[j-1]--;
                    n1[j] = n1[j]+10-n2[k];
                }
                else//前数足够大直接减
                    n1[j] = n1[j]-n2[k];
            }
            break;
    }
    printf("结果是：");
    if(sym==45&&biger==1)//当是减法且第二个数大于第一个数时输出负号
        printf("-");
    if(up==-1)//当第一位需要进位时输出第一位1
        printf("1");
    int none = 0;//判断首位是不是0，若是则不打印
    for(l = 0; l<i; l++)
    {   
        if(n1[l]!=0)//当出现不为0的数后开始打印
            none = 1;
        if(none==1)
            printf("%d",n1[l]);
    }
}