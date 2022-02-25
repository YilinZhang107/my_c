#include<stdio.h>
int main()
{
    double aver(int *x);
    int fail(int *y);
    int well(int *x);
    int stu[5][4];
    int i,j;
    for(i=0;i<5;i++)
     for(j=0;j<4;j++)
      scanf("%d",&stu[i][j]);
    int *pa=stu[0];
    double avarage;
    avarage=aver(pa);
    int n1,n2;
    n1=fail(pa);
    n2=well(pa);
    printf("%.1f %d %d",avarage,n1,n2);
    return 0;
    
}
double aver(int *x)           //计算第一门课的均分
{
    double sum=0,avarage;
    int i;
    for(i=0;i<5;x=x+4,i++)  //x=x+4关键
      sum=sum+*x;
    avarage=sum/5;
    return (avarage);
}
int fail(int *y)          //计算有几人两门课以上不及格
{
    int ke=0,n=0,i,j;
    for(i=0;i<5;i++)
    {
         for(j=0;j<4;j++,y++)
          if(*y<60)
          ke++;
        if(ke>=2)n++;
        ke=0;  
    }
    return (n);
}
int well(int *x)              //有几人均分90以上或全部85以上
{
    int i,j,n=0,sum=0,pan=1;
    for(i=0;i<5;i++)
    {
        for(j=0;j<4;j++,x++)
        {
          sum=sum+*x;
          if(*x<85)pan=0;
        }
        if(pan==1||sum/4>90)
        n++;
        pan=1;
        sum=0;
    }
    return (n);

}