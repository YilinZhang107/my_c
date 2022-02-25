#include<stdio.h>
#include<stdlib.h>

struct Student  //用于储存数据构建动态链表的结构体
{
    long num;
    float score;
    struct Student*next;
};

int n=0;//n为全局变量录入的学生个数，各函数均可以使用
char enter;//接收回车，避免输入的不正常

struct Student * creat(void)//定义函数，此函数返回一个指向链表头的指针
{
    struct Student *head;
    struct Student *p1,*p2;
    n= 0;                                      //malloc返回*void未确定类型的指针，可以被强制转化为任意类型指针
    p1=p2=(struct Student*)malloc(sizeof(struct Student));//开辟第一个新单元 malloc:分配长度为（）字节的内存块
    scanf("%ld,%f",&p1->num,&p1->score);//输入第一个学生的学号和成绩
    head = NULL;
    while(p1->num!=0)
    {
        n++;
        if(n==1)   //确定头部指针
            head=p1;
        else
            p2->next=p1;  //向后延续
        p2=p1;
        p1=(struct Student *)malloc(sizeof(struct Student));
        scanf("%ld,%f%c",&p1->num,&p1->score,&enter);//输入其他学生的学号和成绩
    }
    p2->next=NULL;
    return(head);
}

//定义print函数
void print(struct Student * head)
{
    struct Student *p;
    
    p=head;
    if(head!=NULL&&n>0)
    {
        printf("\n录入的 %d 个同学的学号和分数是:\n",n);
        do
        {
            printf("%ld %5.1f\n",p->num,p->score);
            p=p->next;
        } 
        while (p!=NULL);
    }
    else
    {
        printf("没有数据，请先建立数据表。\n");
    }
    
}

void ui()
{
    printf("请选择您想进行的操作：\n1.建立学生学号成绩表\n2.删除学生成绩\n3.查看学生成绩表\n4.结束程序\n");
}

//删除函数
struct Student * Delete(struct Student * head)
{
    struct Student *p,*q;
    long num;

    if(head==NULL||n<1)
    {
        printf("链表为空。\n");
        return (head);
    }
    int boo = 0;//判断是否第一位被删除
    printf("请输入要删除的学生的学号：");
    scanf("%ld%c",&num,&enter);
    for(p=head->next,q=head;p!=NULL;p=p->next,q=q->next)
    {
        if(q==head)
        {
            if(q->num==num)
            {
                head = q->next;
                boo = 1;
            }
        }
        if(p->num==num)
        {
            q->next=p->next;
            boo = 1;   
        }
    }
    if(q==NULL||boo==0)
        printf("要删除的学生不存在。\n");
    else
    {
        printf("删除成功！\n");
        n--;
    }
    free(p);
    return (head);
}

int main()
{
    struct Student *head = NULL;
    while(1)
    {
        ui();
        char menu;
        scanf("%c%c",&menu,&enter);
        switch (menu)
        {
        case '1':
            printf("请按此格式输入：学号,分数(以0，0结束输入)\n");
            head = creat();//函数返回链表第一个结点的地址
            break;
        case '2':
            head = Delete(head);
            break;
        case '3'://查看成绩
            print(head);
            break;
        case '4':
            printf("感谢您的使用，再见！");
            return 0;
        default:
            printf("您输入的格式有误，请重新输入!\n");
            break;
        }
    }
} 

