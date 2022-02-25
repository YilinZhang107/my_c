#include<stdio.h>
#include<math.h>

int main()
{
    char str[50];
    int i = 0, num = 0; //开辟内存空间
    printf("请输入您想转换的2进制数：（50位以内）\n");//与用户交互，进行提示
    for(i=0; i<50; i++)//利用循环来进行输入
    {
        scanf("%c",&str[i]);
        if(str[i]==10)//输入回车终止输入
            break;
        else if(str[i]<48||str[i]>49)//当输入的不是0或1时，终止输入
        {
            printf("您输入的格式有误，请重新输入！");
            return 0;
        }
        str[i] = str[i]-48;//对ASCII码进行转换，便于下一步的计算
    }
    for(int l=i-1, j = 0; l>=0; l--, j++)//l：从小位向上计算。j：控制2的次方数
    {
        num = num + str[l]*(int)pow(2,j);//pow求幂运算后为浮点数，需转化为整形
    }
    printf("经转化的10进制整数是：%d",num);//进行输出
}