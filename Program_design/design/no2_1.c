#include<stdio.h>

void putStack(int stack[16], int head)  //用于每次操作结束后输出栈中元素
{
    if(head==0)
        printf("栈中没有元素。");
    else
    {
        printf("栈中元素：");
        for(int i = head-1; i>=0; i--)
            printf("%d ",stack[i]);
    }
    printf("\n");
}

int main()
{
    void putStack(int stack[16], int head);
    int stack[16];//开辟一个数组作为栈
    int head = 0;//记录栈顶位置
    char function;//记录选择的功能
    char receiver;//接收输入进来的回车
    while(1)
    {
        printf("请输入您想进行的操作序号：\n1.进行入栈。\n2.进行出栈。\n3.返回栈顶元素。\n4.结束程序\n");
        scanf("%c%c",&function,&receiver);
        switch (function)
        {
        case '1':
            if(head==16)
            {
                printf("栈已满，无法继续添加元素！\n");
                break;
            }
            else
            {
                printf("请输入入栈的元素(整数)：");
                scanf("%d%c",&stack[head],&receiver);
                head++;
                break;
            }
        case '2':
            if(head==0)
            {
                printf("栈已空，无法继续取出元素！\n");
                break;
            }
            else
            {
                printf("取出元素：%d\n",stack[head-1]);
                head--;
                break;
            }
        case '3':
            if(head>0)
            {
                printf("栈顶元素是：%d\n",stack[head-1]);
                break;
            }
            else
            {
                break;
            }
        case '4':
            printf("再见！");
            return 0;
        default:
            printf("输入格式有误，请重新输入！\n");
            break;
        }
        putStack(stack,head);
    }
}

