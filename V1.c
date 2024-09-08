#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*1.FindNum函数，求出满足以下等式的数字，
   3 □* 6237 = □3 * 3564
*/
void FindNum()
{
    int i, find = 0;
    for (i = 0; i <= 9; i++)
    {
        if ((30 + i) * 6237 == (i * 10 + 3) * 3564)
        {
            printf("所求的数字为 %d, 3%d*6237 = %d3*3564\n", i, i, i);
            find = 1;
        }
    }
    if (!find)
        printf("找不到满足等式的数字。\n");
}

/* 一元二次方程求根 */
void FindRoot()
{
    int ch;
    double a, b, c, x1, x2;
    while (1)
    {
        printf("按1继续，按0退出：\n");
        scanf_s("%d", &ch);
        if (ch == 0)
            break;
        else if (ch == 1)
        {
            printf("请分别输入a,b,c的值，以空格键分隔：\n");
            scanf_s("%lf %lf %lf", &a, &b, &c);

            //第一种情况：系数a为0，不是二次方程
            if (a == 0)
            {
                if (b != 0) {
                    x1 = -(c / b);
                    printf("系数a为0，不是二次方程，方程的解为：%.2lf.\n", x1);
                }
                else {
                    printf("a和b都为0，不是方程。\n");
                }
            }

            //第二种情况：方程有两个不同的实根 
            else if ((b * b - 4 * a * c) > 0)
            {
                x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
                x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
                printf("方程有两个不同的实根，x1 = %.2lf, x2 = %.2lf. \n", x1, x2);
            }

            //第三种情况：方程有两个相同的实根 
            else if ((b * b - 4 * a * c) == 0)
            {
                x1 = (-b) / (2 * a);
                printf("方程有两个相同的实根, x1 = x2 = %.2lf.\n", x1);
            }

            //第四种情况：方程有两个虚根 
            else
                printf("方程有两个虚根, x1 = %.2lf + %.2lfi, x2 = %.2lf - %.2lfi\n",
                    (-b) / (2 * a), sqrt(4 * a * c - b * b) / (2 * a), (-b) / (2 * a), sqrt(4 * a * c - b * b) / (2 * a));
        }
    }
}

/*求出逃逸司机的车牌号，31XXXX，三、四位相同，五、六位相同，三~六位是一个整数的平方。
由于1000的平方根大于31，所以穷举循环从31开始。*/
void Detective()
{
    int i, num;
    int third, fourth, fifth, sixth;
    for (i = 31; i < 100; i++)
    {
        num = i * i;
        third = num / 1000;
        fourth = (num / 100) % 10;
        fifth = (num / 10) % 10;
        sixth = num % 10;

        if (third == fourth && fifth == sixth) {
            printf("车牌号为%d。\n", 310000 + num);
            return;
        }
    }
    printf("未找到符合条件的车牌号。\n");
}

/*猴子吃桃问题，每天早上吃了前一天剩下的一半零一个桃子。
求第一天摘的桃子数*/
void Monkey()
{
    int day = 10;
    int peach = 1;
    while (day > 1)
    {
        day--;
        peach = (peach + 1) * 2;
    }
    printf("第一天猴子共摘了%d个桃子。\n", peach);
}

/*打印钻石被调用函数，根据图案规则套用循环*/
void Print_Diamond(int lines)
{
    int i, j;
    for (i = 1; i <= lines; i++)
    {
        printf("                                  ");
        for (j = 1; j <= abs(lines / 2 + 1 - i); j++)
            printf(" ");
        for (j = 1; j <= lines - 2 * (abs(lines / 2 + 1 - i));j++)
            printf("*");
        printf("\n");
    }
}

/*打印钻石图案，调用Print_Diamond函数，参数为行数*/
void Diamond()
{
    int lines;
    printf("请输入打印的钻石的行数(必须为奇数): ");
    scanf_s("%d", &lines);
    Print_Diamond(lines);
}

/*计算器，输入文件为express.txt，输出文件为result.txt*/
void Calculator()
{
    FILE* fin, * fout;
    int oprand1, oprand2, result;
    char oprator;
    fin = fopen("express.txt", "r");
    fout = fopen("result.txt", "w");
    if (!fin)
    {
        printf("读入文件出错！\n");
        system("pause");
        exit(0);
    }
    if (!fout)
    {
        printf("写入文件出错！\n");
        system("pause");
        exit(0);
    }
    while ((fscanf(fin, "%d %c %d", &oprand1, &oprator, &oprand2)) != EOF)
    {
        switch (oprator)
        {
        case '+':
            result = oprand1 + oprand2;
            fprintf(fout, "%d %c %d = %d\n", oprand1, oprator, oprand2, result);
            break;
        case '-':
            result = oprand1 - oprand2;
            fprintf(fout, "%d %c %d = %d\n", oprand1, oprator, oprand2, result);
            break;
        case '*':
            result = oprand1 * oprand2;
            fprintf(fout, "%d %c %d = %d\n", oprand1, oprator, oprand2, result);
            break;
        case '/':
            if (oprand2 != 0) {
                result = oprand1 / oprand2;
                fprintf(fout, "%d %c %d = %d\n", oprand1, oprator, oprand2, result);
            }
            else {
                fprintf(fout, "%d %c %d = 错误（除以0）\n", oprand1, oprator, oprand2);
            }
            break;
        default:
            fprintf(fout, "未知的操作符: %c\n", oprator);
            break;
        }
    }
    fclose(fin);
    fclose(fout);
}

int main()
{
    int choice;

    while (1)
    {
        printf("------------MENU----------------\n");
        printf("           1.FindNum            \n");
        printf("           2.FindRoot           \n");
        printf("           3.Detective          \n");
        printf("           4.Monkey             \n");
        printf("           5.Diamond            \n");
        printf("           6.Calculator         \n");
        printf("           0.GoodBye!           \n");
        printf("Please input your choice: ");
        scanf_s("%d", &choice);
        switch (choice)
        {
        case 1:
            FindNum();
            break;
        case 2:
            FindRoot();
            break;
        case 3:
            Detective();
            break;
        case 4:
            Monkey();
            break;
        case 5:
            Diamond();
            break;
        case 6:
            Calculator();
            break;
        case 0:
            printf("再见，谢谢使用！\n");
            system("pause");  //加这个
            exit(0);
        default:
            printf("无效的选择，请重新输入。\n");
            break;
        }
    }

    return 0;
}
