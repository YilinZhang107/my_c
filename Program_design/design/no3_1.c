#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	FILE *fp1, *fp2;
	char c;//存储每一次读到的字符 
    int lineNum = 1;//添加的行号
	fp1 = fopen("d:/test.c", "r");//打开需要更改的测试文件
	fp2 = fopen("d:/test1.c", "w");//新建一个文件存储	 
	while(!feof(fp1))//逐个读取字符
    {   
		c = fgetc(fp1);
		if(c == EOF)
			continue;
		if(c == '/')
        {
			c = fgetc(fp1);//遇到换行符结束，结束后需输出换行符 
			if(c == '/')
            {
				while(c != '\n' && c != EOF)
                {
					c = fgetc(fp1);
				}
				fputc('\n',fp2);
			}
			else//不是注释符，只是单纯的'/'符号，则退回两个字符
            {
				fseek(fp1, -2L, SEEK_CUR);
				c = fgetc(fp1);
				fputc(c, fp2);
			}			
		}
		else
            fputc(c,fp2);
	} 	 
	fclose(fp1);
	fclose(fp2);
    
    //开始添加行号
    FILE *fp3, *fp4; //刚才暂时存储的文件 和 给文件添加行号并输出
    char str[110]; // 存储每一行字符
    fp3 = fopen("d:/test1.c", "r"); //  打开刚才展暂时存储的文件
    fp4 = fopen("d:/test.c", "w"); // 以写入方式打开需要被更改的文件
    fgets(str, 100, fp3); // 从文件中读取一行信息，保存到str数组中
    while(!feof(fp3)) 
    {
        fprintf(fp4, "%d %s", lineNum, str); //按行进行输出
        lineNum++; // 行号加一
        fgets(str, 100, fp3); // 读取下一行
    }
    fclose(fp3); // 关闭文件
    fclose(fp4);
    remove("d:/test1.c");
	printf("添加成功！\n");
	return 0;
} 
