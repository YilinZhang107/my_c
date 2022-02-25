#include<stdio.h>

struct point//存放各城市的数据
{
    char name[10];//城市名字
    int much[9];//到各城市的旅费(四舍五入为整数)
    int reach;//判断是否已经去过了
};

int main()
{
    struct point city[9]=//九个城市的数据
    {
        {"北京",0,293,423,662,409,483,292,560,339,1},
        {"西安",293,0,334,528,203,275,230,290,570,0},
        {"兰州",423,334,0,435,249,290,205,130,360,0},
        {"武汉",662,528,435,0,275,360,650,133,425,0},
        {"杭州",409,203,249,275,0,198,70,213,300,0},
        {"深圳",483,275,290,360,198,0,390,349,280,0},
        {"上海",292,230,205,650,70,390,0,303,99,0},
        {"郑州",560,290,130,133,213,349,303,0,345,0},
        {"哈尔滨",339,570,360,425,300,280,99,345,0,0}
    };
    int fee1 = 0,fee2 = 0,fee3 = 0,fee4 = 0,fee5 = 0,fee6 = 0,fee7 = 0,fee8 = 0,fee9 = 0;//记录当前总费用
    int minFee = 9999;//当前最低总费用
    int travel[9];//记录旅程
    int i,j,k,l,o,p,m,n;
    for(i = 1; i<9; i++)//从北京出发
    {
        fee1 = city[0].much[i];//第一次费用计算，都是从北京出发的
        city[i].reach=1;
        for(j = 0; j<9; j++)//到第二个城市
        {
            if(city[j].reach==1)//若已经到达过这个城市则不去
                continue;
            fee2 = fee1 + city[i].much[j];
            city[j].reach=1;
            for(k = 0; k<9; k++)//第三个城市
            {
                if(city[k].reach==1)//若已经到达过这个城市则不去
                    continue;
                fee3 = fee2 + city[j].much[k];
                city[k].reach=1;
                for(l = 0; l<9; l++)//第四个城市
                {
                    if(city[l].reach==1)//若已经到达过这个城市则不去
                        continue;
                    fee4 = fee3 + city[k].much[l];
                    city[l].reach=1;
                    for(o = 0; o<9;o++)//第五个城市
                    {
                        if(city[o].reach==1)//若已经到达过这个城市则不去
                            continue;
                        fee5 = fee4 + city[l].much[o];
                        city[o].reach=1;
                        for(p = 0; p<9; p++)//第六个城市
                        {
                            if(city[p].reach==1)//若已经到达过这个城市则不去
                                continue;
                            fee6 = fee5 + city[o].much[p];
                            city[p].reach=1;
                            for(m = 0; m<9; m++)//第七个城市
                            {
                                if(city[m].reach==1)//若已经到达过这个城市则不去
                                    continue;
                                fee7 = fee6 + city[p].much[m];
                                city[m].reach=1;
                                for(n = 0; n<9; n++)
                                {
                                    if(city[n].reach==1)//若已经到达过这个城市则不去
                                        continue;
                                    fee8 = fee7 + city[m].much[n];
                                    fee9 = fee8 + city[n].much[0];//返回北京的费用
                                    if(minFee>fee9)//当此次费用比记录的路程费用更低时，修改最优解
                                    {
                                        minFee = fee9;
                                        travel[1] = i;//记录路线
                                        travel[2] = j;
                                        travel[3] = k;
                                        travel[4] = l;
                                        travel[5] = o;
                                        travel[6] = p;
                                        travel[7] = m;
                                        travel[8] = n;
                                    }
                                    fee8 = 0;
                                    fee9 = 0;
                                }
                                fee7 = 0;
                                city[m].reach=0;//下一轮循环前的准备
                            }
                            fee6 = 0;
                            city[p].reach=0;
                        }
                        fee5 = 0;
                        city[o].reach=0;
                    }
                    fee4 = 0;
                    city[l].reach=0;   
                }
                fee3 = 0;
                city[k].reach=0;
            }
            fee2 = 0;
            city[j].reach=0;
        }
        fee1 = 0;
        city[i].reach=0;
    }
    printf("最优路径是：北京");
    for(i = 1; i<9; i++)
    {
        printf("-");
        for(l = 0; l<10; l++)
        {
            if(city[travel[i]].name[l]==0)
                break;
            printf("%c",city[travel[i]].name[l]);

        }
    }
    printf("-北京\n");
    printf("总花费：%d",minFee);
    return 0;
}

