#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*1.FindNum����������������µ�ʽ�����֣�
   3 ��* 6237 = ��3 * 3564
*/
void FindNum()
{
    int i, find = 0;
    for (i = 0; i <= 9; i++)
    {
        if ((30 + i) * 6237 == (i * 10 + 3) * 3564)
        {
            printf("���������Ϊ %d, 3%d*6237 = %d3*3564\n", i, i, i);
            find = 1;
        }
    }
    if (!find)
        printf("�Ҳ��������ʽ�����֡�\n");
}

/* һԪ���η������ */
void FindRoot()
{
    int ch;
    double a, b, c, x1, x2;
    while (1)
    {
        printf("��1��������0�˳���\n");
        scanf_s("%d", &ch);
        if (ch == 0)
            break;
        else if (ch == 1)
        {
            printf("��ֱ�����a,b,c��ֵ���Կո���ָ���\n");
            scanf_s("%lf %lf %lf", &a, &b, &c);

            //��һ�������ϵ��aΪ0�����Ƕ��η���
            if (a == 0)
            {
                if (b != 0) {
                    x1 = -(c / b);
                    printf("ϵ��aΪ0�����Ƕ��η��̣����̵Ľ�Ϊ��%.2lf.\n", x1);
                }
                else {
                    printf("a��b��Ϊ0�����Ƿ��̡�\n");
                }
            }

            //�ڶ��������������������ͬ��ʵ�� 
            else if ((b * b - 4 * a * c) > 0)
            {
                x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
                x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
                printf("������������ͬ��ʵ����x1 = %.2lf, x2 = %.2lf. \n", x1, x2);
            }

            //�����������������������ͬ��ʵ�� 
            else if ((b * b - 4 * a * c) == 0)
            {
                x1 = (-b) / (2 * a);
                printf("������������ͬ��ʵ��, x1 = x2 = %.2lf.\n", x1);
            }

            //������������������������ 
            else
                printf("�������������, x1 = %.2lf + %.2lfi, x2 = %.2lf - %.2lfi\n",
                    (-b) / (2 * a), sqrt(4 * a * c - b * b) / (2 * a), (-b) / (2 * a), sqrt(4 * a * c - b * b) / (2 * a));
        }
    }
}

/*�������˾���ĳ��ƺţ�31XXXX��������λ��ͬ���塢��λ��ͬ����~��λ��һ��������ƽ����
����1000��ƽ��������31���������ѭ����31��ʼ��*/
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
            printf("���ƺ�Ϊ%d��\n", 310000 + num);
            return;
        }
    }
    printf("δ�ҵ����������ĳ��ƺš�\n");
}

/*���ӳ������⣬ÿ�����ϳ���ǰһ��ʣ�µ�һ����һ�����ӡ�
���һ��ժ��������*/
void Monkey()
{
    int day = 10;
    int peach = 1;
    while (day > 1)
    {
        day--;
        peach = (peach + 1) * 2;
    }
    printf("��һ����ӹ�ժ��%d�����ӡ�\n", peach);
}

/*��ӡ��ʯ�����ú���������ͼ����������ѭ��*/
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

/*��ӡ��ʯͼ��������Print_Diamond����������Ϊ����*/
void Diamond()
{
    int lines;
    printf("�������ӡ����ʯ������(����Ϊ����): ");
    scanf_s("%d", &lines);
    Print_Diamond(lines);
}

/*�������������ļ�Ϊexpress.txt������ļ�Ϊresult.txt*/
void Calculator()
{
    FILE* fin, * fout;
    int oprand1, oprand2, result;
    char oprator;
    fin = fopen("express.txt", "r");
    fout = fopen("result.txt", "w");
    if (!fin)
    {
        printf("�����ļ�����\n");
        system("pause");
        exit(0);
    }
    if (!fout)
    {
        printf("д���ļ�����\n");
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
                fprintf(fout, "%d %c %d = ���󣨳���0��\n", oprand1, oprator, oprand2);
            }
            break;
        default:
            fprintf(fout, "δ֪�Ĳ�����: %c\n", oprator);
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
            printf("�ټ���ллʹ�ã�\n");
            system("pause");  //�����
            exit(0);
        default:
            printf("��Ч��ѡ�����������롣\n");
            break;
        }
    }

    return 0;
}
