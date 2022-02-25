#include<stdio.h>
#include<string.h>

void rleZip(FILE *fp, FILE *rlep)
{
    int len;//储存重复出现的次数
	char c, equal;//储存每次获取的字符，用于比较的暂存点
	c=fgetc(fp);   //取得文件第一个字符
	equal=c;   //将第一个字符赋值给equal
	len=1;   //字符连续出现次数，长度初始化为1
	while(!feof(fp))
	{
		c=fgetc(fp);   // 取得文件的下一个字符
		if(c==equal)     // 文件上一个字符是否与当前字符相等
		    len++;            // 相等则连续长度加一
		else
		{
			fputc(len,rlep);
			fputc(equal,rlep); // 不相等，则输出连续的长度和对应字符
			equal=c;       // 将不相等的第一个字符赋值给seq，开始下次长度计算
			len=1;              // 长度归于一
		}
	}
}

void unzip(FILE *rlep,FILE *fp)
{
	int len,i;
	char c;
	while(!feof(rlep))		   
	{
		len=fgetc(rlep);//读取字符出现的次数
		c=fgetc(rlep);  //读取需要重复的字符
		for(i=0;i<len;i++)
			fputc(c,fp);//循环输出当前字符
	}
}

int main(int argc, char *argv[])
{
    char *func1 = "-c";//压缩功能
    char *func2 = "-d";//解压缩功能
    if(strcmp(argv[2], func1)==0)
    {
        FILE *fp = fopen(argv[1], "rb");//打开需要压缩的文件
        if (fp == NULL)
        {
            printf("无法打开文件！");
		    return 0;
        }
        FILE *rlep = fopen(argv[3], "wb");//新建储存压缩内容的文件
        rleZip(fp, rlep);
        printf("压缩成功！");
    }
    else if(strcmp(argv[2], func2)==0)
    {
        FILE *rlep = fopen(argv[1], "rb");//打开需要解压的文件
        if (rlep == NULL)
        {
            printf("无法打开文件！");
		    return 0;
        }
        FILE *fp = fopen(argv[3], "wb");//新建文件存储解压后的文件
        unzip(rlep, fp);
        printf("解压成功！");
    }
    else
    {
        printf("您输入的格式有误，请重新输入！");
        return 0;
    }
    return 0;
}

