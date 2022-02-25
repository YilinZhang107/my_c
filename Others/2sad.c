#include<stdio.h>
int main()
{
    struct students
    {
        int number[8] = {0};
        int sex = 0;
        int height = 0;
    };
    int num;
    scanf("%d",&num);
    struct students n[num];
    int i;
    for(i = 0; i< num; i++){
        for(int j = 0; j<8; j++){
            scanf("%c",&n[i].numberp[j]);
        }
        char ch;
        scnaf(" %d %d",&n[i].sex,&n[i].height);
    }
    struct students woman[num];
    int m = 0;
    for(i = 0;i<num;i++){
        if(n[i].sex==0){
            woman[m].number[]=n[i].number[];
             woman[m].sex=n[i].sex;
              woman[m].height=n[i].height;
            m++;
        }
    }
    for(i = 0; i<num-m;i++)
    for(i=0; i<num-n-1; i++)
    {
        //每一轮比较前n-1-i个，即已排序好的最后i个不用比较
        for(int j=0; j<n-1-i; j++)
        {
            if(n[j].height > n[j+1].height)
            {
                struct students temp;
                temp = n[j];
                n[j] = n[j+1];
                n[j+1]=temp;
            }
        }
    }
    
}