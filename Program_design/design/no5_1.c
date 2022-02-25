/*
管理员名：zhangyl
*/
#include<stdio.h>
#include <io.h>

int bookNumber = 1;  //全局变量 表示图书的序号
int usersNumber = 1;  //表示读者编号
char enter;  //接收换行符

//添加图书的函数
void addBook(FILE *Book)  
{
    FILE *Book1;  //当文件和书本都存在时需要新建文件来更改信息
    int judgeName = 0;  //判断此书是否已经被存放
    int num = 1, readNum, readNumber;  //书本的数量  存放读到的书本数量  读到的书本序号
    char name[20] = {0}, readName[20] = {0};  //存放图书名字  暂时存放读到的字符串名
    printf("请输入要添加的图书名：");
    for(int i = 0; i<20; i++)  //从输入流取得需要添加的书本名字
    {
        if(i==0)
            scanf("%c%c", &enter,&name[i]);
        else
            scanf("%c",&name[i]);
        if(name[i]==10)  //将最后的换行符改为空
        {
            name[i]=0;
            break;
        }
    }  
    if(access("d:/Book.txt",F_OK)==0)  //access函数判断文件是否存在，存在返回值为0 使用的头文件为io
    {
        judgeName = 1;
        FILE *judge = fopen("d:/Book.txt", "r");  //读取数据文件，查找是否已经存在此书
        while(!feof(judge))
        {
            fscanf(judge, "%d %s %d", &readNumber, readName, &readNum); //由于readName已经表示地址，不需要取地址符
            fscanf(judge,"\n");  //读入换行符，准备下一行的读取
            if(strcmp(name, readName)==0)  //发现已经存在此书后跳出循环
            {
                judgeName = 2;  //为2时表示已经存在此书，需要新建一个文件来更改信息
                break;
            }
        }
        fclose(judge);  //关闭用于判断而打开的文件
        bookNumber = readNumber+1;
        if(judgeName==1)
            Book = fopen("d:/Book.txt", "a");  //文件存在 且不存在相同书名时向后追加内容
        else if(judgeName==2)
        {
            Book1 = fopen("d:/Book1.txt", "w");  //新建一个文件暂存Book中的信息，最后再返回源文件中
            Book = fopen("d:/Book.txt","r");  //只读打开原本的文件
        }
    }
    else
        Book = fopen("d:/Book.txt","w");  //文件不存在时新建一个文件
    if (judgeName<2)
    {  
        fprintf(Book, "%d %s %d\n", bookNumber, name, num);  //写入序号 书名 数量和换行符
        bookNumber++; 
        fclose(Book);
    }
    else
    {
        while(!feof(Book))
        {
            fscanf(Book, "%d %s %d\n", &readNumber, readName, &readNum);
            if(strcmp(name, readName)==0)
                fprintf(Book1, "%d %s %d\n", readNumber, readName, readNum+1);  //写入序号 书名 数量+1和换行符
            else
                fprintf(Book1, "%d %s %d\n", readNumber, readName, readNum);  //写入序号 书名 数量和换行符            
        }
        bookNumber++;
        fclose(Book);  //关闭文件
        fclose(Book1);

        Book1 = fopen("d:/Book1.txt", "r");
        Book = fopen("d:/Book.txt", "w+");   //刷新原文件，再次写入正确数据
        while(!feof(Book1))
        {
            fscanf(Book1, "%d %s %d\n", &readNumber, readName, &readNum);
            fprintf(Book, "%d %s %d\n", readNumber, readName, readNum);
        }
        fclose(Book);
        fclose(Book1);
        remove("d:/Book1.txt");  //删除原文件              
        //rename("d:/Book1.txt", "d:/Book.txt");  //将更改后的文件改名为原数据文件
    }
    printf("添加成功！\n");
}

//修改图书信息函数
void changeBook(FILE *Book)  
{
    while(1)
    {
        char name[20] = {0}, readName[20] = {0};
        printf("           Edit Book Information            \n");
        printf("[------------------------------------------]\n");
        printf("\t请选择需要修改的信息：\n  1.修改图书名称\n  2.修改图书数量\n  3.返回主菜单\n");
        printf("[------------------------------------------]\n");
        int function, readNumber, readNum, find = 0;  //功能选择 读取到的序号 读取到的数量 是否找到此书
        
        //判断修改后的书名是否和原有的重复
        Book = fopen("d:/Book.txt","r");  //只读打开原文件
        int ifNumber, ifNum;
        char ifName[20] = {0};
        FILE *ifUserExisted = fopen("d:/Users1.txt","w");
        while(!feof(Book))
        {
            fscanf(Book, "%d %s %d\n", &ifNumber, ifName, &ifNum);
            fprintf(ifUserExisted, "%d %s %d\n", &ifNumber, ifName, ifNum);  
        }
        fclose(ifUserExisted);
        fclose(Book);
   
        scanf("%d",&function);
        if(function == 3)
        {
            remove("d:/Book1.txt");  //有时会多余创造了文件，需要删除 
            return;
        }
        Book = fopen("d:/Book.txt","r");  //只读打开原文件
        FILE *Book1 = fopen("d:/Book1.txt", "w");  //先新建一个文件存储更改后的信息
        printf("请输入需要更改的图书名：");
        for(int i = 0; i<20; i++)  //从输入流取得需要添加的书本名字
        {
            if(i==0)
                scanf("%c%c", &enter,&name[i]);
            else
                scanf("%c",&name[i]);
            if(name[i]==10)  //将最后的换行符改为空
            {
                name[i]=0;
                break;
            }
        }
        if(function==1)
        {
            while(!feof(Book))
            {
                fscanf(Book, "%d %s %d\n", &readNumber, readName, &readNum);
                if(strcmp(name, readName)==0)
                {  
                    find = 1;  //找到了此书
                    printf("您要将书名%s更改为：", name);
                    char changeName[20] = {0};
                    for(int i = 0; i<20; i++)  //从输入流取得需要更改的书本名字
                    {
                        if(i==0)
                            scanf("%c",&changeName[i]);
                        else
                            scanf("%c",&changeName[i]);
                        if(changeName[i]==10)  //将最后的换行符改为空
                        {
                            changeName[i]=0;
                            break;
                        }
                    }
                    
                    ifUserExisted = fopen("d:/Users1.txt","r");   //判断更改后的名字是否会和已存在的书名冲突
                    while(!feof(ifUserExisted))
                    {
                        fscanf(ifUserExisted, "%d %s %d\n", &ifNumber, ifName, &ifNum);
                        if (strcmp(changeName, ifName)==0)
                        {
                            printf("更改失败：已存在名称为%s的图书\n", changeName);
                            fclose(ifUserExisted);
                            fclose(Book);  //关闭文件
                            fclose(Book1);
                            return;
                        }
                    }

                    fprintf(Book1, "%d %s %d\n", readNumber, changeName, readNum);  //写入序号 更改后的书名 数量和换行符
                }
                else
                    fprintf(Book1, "%d %s %d\n", readNumber, readName, readNum);  //写入序号 书名 数量和换行符            
            }
            if(find==0)  //若没找到此书
            {
                printf("没有找到此书！请重新输入\n");
                break;
            }
            fclose(Book);  //关闭文件
            fclose(Book1);

            Book1 = fopen("d:/Book1.txt", "r");
            Book = fopen("d:/Book.txt", "w+");   //刷新原文件，再次写入正确数据
            while(!feof(Book1))
            {
                fscanf(Book1, "%d %s %d\n", &readNumber, readName, &readNum);
                fprintf(Book, "%d %s %d\n", readNumber, readName, readNum);
            }
            fclose(Book);
            fclose(Book1);

            remove("d:/Book1.txt");  //删除原文件              
            //rename("d:/Book1.txt", "d:/Book.txt");  //将更改后的文件改名为原数据文件  此方法成功率低！！！
            printf("更改成功!\n");
        }
        else if(function == 2)
        {
            while(!feof(Book))
            {
                fscanf(Book, "%d %s %d\n", &readNumber, readName, &readNum);
                if(strcmp(name, readName)==0)
                {  
                    find = 1;  //找到了此书
                    printf("您要将数量%d更改为：", readNum);
                    int newNum = 0;
                    scanf("%d",&newNum);
                    fprintf(Book1, "%d %s %d\n", readNumber, readName, newNum);  //写入序号 书名 更改后的数量和换行符
                }
                else
                    fprintf(Book1, "%d %s %d\n", readNumber, readName, readNum);  //写入序号 书名 数量和换行符            
            }
            if(find==0)  //若没找到此书
            {
                printf("没有找到此书！请重新输入");
                break;
            }
            fclose(Book);  //关闭文件
            fclose(Book1);

            Book1 = fopen("d:/Book1.txt", "r");
            Book = fopen("d:/Book.txt", "w+");   //刷新原文件，再次写入正确数据
            while(!feof(Book1))
            {
                fscanf(Book1, "%d %s %d\n", &readNumber, readName, &readNum);
                fprintf(Book, "%d %s %d\n", readNumber, readName, readNum);
            }
            fclose(Book);
            fclose(Book1);

            remove("d:/Book1.txt");  //删除原文件              
            //rename("d:/Book1.txt", "d:/Book.txt");  //将更改后的文件改名为原数据文件  此方法易出现问题！！！
            printf("更改成功!\n");
        }
        else
        {
            printf("输入格式有误，请重新输入！");
            break;
        }
    }
}

//删除书籍的函数
void delBook(FILE *Book)
{
    while(1)
    {
        printf("请输入您想删除的图书名：(输入\"-r\"返回上一级)");
        char delName[20] = {0};
        for(int i = 0; i<20; i++)  //从输入流取得需要删除的书本名字
        {
            //if(i==0)
              //  scanf("%c%c", &enter,&delName[i]);
            //else
                scanf("%c",&delName[i]);
            if(delName[i]==10)  //将最后的换行符改为空
            {
                delName[i]=0;
                break;
            }
        }
        if(strcmp(delName, "-r")==0)  //输入返回上一级的指示后返回
            return;
        int readNumber, readNum, find = 0;
        char readName[20] = {0};
        Book = fopen("d:/Book.txt","r");
        FILE *Book1 = fopen("d:/Book1.txt","w");
        while (!feof(Book))
        {
            fscanf(Book, "%d %s %d\n", &readNumber, readName, &readNum);
            if(strcmp(delName, readName)==0)
            {  
                find = 1;  //找到了此书
                //因为要删除此条信息，所以不再向新文件中输出它
            }
            else
            {
                if(find==1)
                    fprintf(Book1, "%d %s %d\n", readNumber-1, readName, readNum);  //排在删除后的写入-1的序号 书名 数量和换行符            
                else
                    fprintf(Book1, "%d %s %d\n", readNumber, readName, readNum);  //删除前的写入的序号 书名 数量和换行符            
            }            
        }
        if(find==0)  //若没找到此书
        {
            printf("没有找到此书！请重新输入\n");
            continue;
        }
        fclose(Book);
        fclose(Book1);

        Book1 = fopen("d:/Book1.txt", "r");
        Book = fopen("d:/Book.txt", "w+");   //刷新原文件，再次写入正确数据
        while(!feof(Book1))
        {
            fscanf(Book1, "%d %s %d\n", &readNumber, readName, &readNum);
            fprintf(Book, "%d %s %d\n", readNumber, readName, readNum);
        }
        fclose(Book);
        fclose(Book1);

        remove("d:/Book1.txt");  //删除原文件              
        printf("删除成功!\n");
    }
}

//展示全部图书的函数
void showBook(FILE *Book)
{
    printf("                  Library                   \n");
    printf("[------------------------------------------]\n");
    printf("\t序号\t书名\t\t数量\n");
    char readName[20] = {0};
    int readNumber, readNum;
    Book = fopen("d:/Book.txt", "r");
    while(!feof(Book))
    {
        fscanf(Book, "%d %s %d\n", &readNumber, readName, &readNum);
        printf("\t%d\t%s\t\t%d\n",readNumber, readName, readNum);           
    }
    fclose(Book);
    printf("[------------------------------------------]\n");
}

//向管理员展示全部用户的函数
void showUsers(FILE *Users)
{
    printf("                   Users                    \n");
    printf("[------------------------------------------]\n");
    printf("\t序号\t姓名\t所借阅图书\n");
    char readName[20] = {0}, borrowBook[20] = {0};
    int readNumber;
    Users = fopen("d:/Users.txt", "r");
    while(!feof(Users))
    {
        fscanf(Users, "%d %s %s\n", &readNumber, readName, borrowBook);
        printf("\t%d\t%s\t%s\n",readNumber, readName, borrowBook);           
    }
    fclose(Users);
    printf("[------------------------------------------]\n");
}

//添加用户函数   
void addUsers(FILE *Users)
{
    FILE *Users1;  //当文件和用户都存在时需要新建文件来更改信息
    int judgeName = 0;  //判断此用户是否已经存在
    int num = 1, readNumber;  //  存放读到的书本数量  读到的用户序号
    char name[20] = {0}, readName[20] = {0}, borrowBook[20] = {"None"},readBorrowBook[20] = {"None"};  //存放用户名字  暂时存放读到的字符串名
    printf("请输入要添加的用户名：");
    for(int i = 0; i<20; i++)  //从输入流取得需要添加的用户名
    {
        if(i==0)
            scanf("%c%c", &enter,&name[i]);
        else
            scanf("%c",&name[i]);
        if(name[i]==10)  //将最后的换行符改为空
        {
            name[i]=0;
            break;
        }
    }  
    if(access("d:/Users.txt",F_OK)==0)  //access函数判断文件是否存在，存在返回值为0 使用的头文件为io
    { 
        judgeName = 1;
        FILE *judge = fopen("d:/Users.txt", "r");  //读取数据文件，查找是否已经存在此用户
        while(!feof(judge))
        {
            fscanf(judge, "%d %s %s", &readNumber, readName, readBorrowBook); //由于readName已经表示地址，不需要取地址符
            fscanf(judge,"\n");  //读入换行符，准备下一行的读取
            if(strcmp(name, readName)==0)  //发现已经存在此用户后跳出循环
            {
                printf("已经存在此用户，无法添加。");  //已经存在此用户，返回
                return;
            }
        }
        fclose(judge);  //关闭用于判断而打开的文件
        usersNumber = readNumber+1;
        if(judgeName==1)
            Users = fopen("d:/Users.txt", "a");  //文件存在 且不存在相同用户时向后追加内容
    }
    else
        Users = fopen("d:/Users.txt","w");  //文件不存在时新建一个文件
    fprintf(Users, "%d %s %s\n", usersNumber, name, borrowBook);  //写入序号 用户名 所借书和换行符
    usersNumber++; 
    fclose(Users);
    printf("添加成功！\n");
}

//修改读者信息函数
void changeUsers(FILE *Users)  
{
    while(1)
    {
        char name[20] = {0}, readName[20] = {0}, borrowBook[20] = {"None"};
        printf("              Edit Reader Name              \n");
        printf("[------------------------------------------]\n");
        printf("\t请选择需要修改的信息：\n  1.修改读者名称\n  2.返回主菜单\n");
        printf("[------------------------------------------]\n");
        int function, readNumber, find = 0;  //功能选择 读取到的序号  是否找到此书
        Users = fopen("d:/Users.txt","r");  //只读打开原文件  
        
        //此处创建ifUserExisted，一会用于查找是否存在相同的名字
        int ifNumber;
        char ifName[20] = {0}, ifBorrow[20] = {0};
        FILE *ifUserExisted = fopen("d:/Book1.txt","w");
        while(!feof(Users))
        {
            fscanf(Users, "%d %s %s\n", &ifNumber, ifName, ifBorrow);
            fprintf(ifUserExisted, "%d %s %s\n", &ifNumber, ifName, ifBorrow);  
        }
        fclose(ifUserExisted);
        fclose(Users);
         
        Users = fopen("d:/Users.txt","r");  //只读打开原文件
        scanf("%d",&function);
        if(function == 2)
        {
            remove("d:/Users1.txt");  //有时会多余创造了文件，需要删除 
            return;
        }
        FILE *Users1 = fopen("d:/Users1.txt", "w");  //先新建一个文件存储更改后的信息
        printf("请输入需要更改的用户名：");
        for(int i = 0; i<20; i++)  //从输入流取得需要更改的读者名字
        {
            if(i==0)
                scanf("%c%c", &enter,&name[i]);
            else
                scanf("%c",&name[i]);
            if(name[i]==10)  //将最后的换行符改为空
            {
                name[i]=0;
                break;
            }
        }
        if(function==1)
        {
            while(!feof(Users))
            {
                fscanf(Users, "%d %s %s\n", &readNumber, readName, borrowBook);
                if(strcmp(name, readName)==0)
                {  
                    find = 1;  //找到了此读者
                    printf("您要将读者名\"%s\"更改为：", name);
                    char changeName[20] = {0};
                    for(int i = 0; i<20; i++)  //从输入流取得需要更改的用户名字
                    {
                        if(i==0)
                            scanf("%c",&changeName[i]);
                        else
                            scanf("%c",&changeName[i]);
                        if(changeName[i]==10)  //将最后的换行符改为空
                        {
                            changeName[i]=0;
                            break;
                        }
                    }
                    ifUserExisted = fopen("d:/Book1.txt","r");   //判断更改后的名字是否会和存在的用户名冲突
                    while(!feof(ifUserExisted))
                    {
                        fscanf(ifUserExisted, "%d %s %s\n", &ifNumber, ifName, ifBorrow);
                        if (strcmp(changeName, ifName)==0)
                        {
                            printf("更改失败：已存在名称为%s的读者\n", changeName);
                            fclose(ifUserExisted);
                            fclose(Users);  //关闭文件
                            fclose(Users1);
                            return;
                        }
                    }

                    fprintf(Users1, "%d %s %s\n", readNumber, changeName, borrowBook);  //写入序号 更改后的读者名 所借书籍和换行符
                }
                else
                    fprintf(Users1, "%d %s %s\n", readNumber, readName, borrowBook);  //写入序号 书名 数量和换行符            
            }
            if(find==0)  //若没找到此读者
            {
                printf("没有找到此读者！请重新输入\n");
                break;
            }
            fclose(Users);  //关闭文件
            fclose(Users1);

            Users1 = fopen("d:/Users1.txt", "r");
            Users = fopen("d:/Users.txt", "w+");   //刷新原文件，再次写入正确数据
            while(!feof(Users1))
            {
                fscanf(Users1, "%d %s %s\n", &readNumber, readName, borrowBook);
                fprintf(Users, "%d %s %s\n", readNumber, readName, borrowBook);
            }
            fclose(Users);
            fclose(Users1);

            remove("d:/Users1.txt");  //删除原文件              
            //rename("d:/Book1.txt", "d:/Book.txt");  //将更改后的文件改名为原数据文件  此方法成功率低！！！
            printf("更改成功!\n");
        }
        else
        {
            printf("输入格式有误，请重新输入！\n");
            break;
        }
    }
}

//删除用户的函数
void delUsers(FILE *Users)
{
    while(1)
    {
        printf("请输入您想删除的读者名：(输入\"-r\"返回上一级)");
        char delName[20] = {0};
        for(int i = 0; i<20; i++)  //从输入流取得需要删除的用户名字
        {
            //if(i==0)
              //  scanf("%c%c", &enter,&delName[i]);
            //else
                scanf("%c",&delName[i]);
            if(delName[i]==10)  //将最后的换行符改为空
            {
                delName[i]=0;
                break;
            }
        }
        if(strcmp(delName, "-r")==0)  //输入返回上一级的指示后返回
            return;
        int readNumber, find = 0;
        char readName[20] = {0}, borrowBook[20] = {"None"};
        Users = fopen("d:/Users.txt","r");
        FILE *Users1 = fopen("d:/Users1.txt","w");
        while (!feof(Users))
        {
            fscanf(Users, "%d %s %s\n", &readNumber, readName, borrowBook);
            if(strcmp(delName, readName)==0)
            {  
                find = 1;  //找到了此读者
                //因为要删除此条信息，所以不再向新文件中输出它
            }
            else
            {
                if(find==1)
                    fprintf(Users1, "%d %s %s\n", readNumber-1, readName, borrowBook);  //排在删除后的写入-1的序号 读者名 所借书和换行符            
                else
                    fprintf(Users1, "%d %s %s\n", readNumber, readName, borrowBook);  //删除前的写入的序号 读者名 所借书和换行符            
            }            
        }
        if(find==0)  //若没找到此读者
        {
            printf("没有找到此读者！请重新输入\n");
            continue;
        }
        fclose(Users1);
        fclose(Users);

        Users1 = fopen("d:/Users1.txt", "r");
        Users = fopen("d:/Users.txt", "w+");   //刷新原文件，再次写入正确数据
        while(!feof(Users1))
        {
            fscanf(Users1, "%d %s %s\n", &readNumber, readName, borrowBook);
            fprintf(Users, "%d %s %s\n", readNumber, readName, borrowBook);
        }
        fclose(Users1);
        fclose(Users);

        remove("d:/Users1.txt");  //删除原文件              
        printf("删除成功!\n");
    }
}

//借阅函数
void borrowBooking(char readerName[])
{
    printf("请输入您想借阅的图书名：");
    char name[20] = {0};
    for(int i = 0; i<20; i++)  //从输入流取得图书名
    {
        if(i==0)
            scanf("%c%c", &enter,&name[i]);
        else
            scanf("%c",&name[i]);
        if(name[i]==10)  //将最后的换行符改为空
        {
            name[i]=0;
            break;
        }
    }
    char readName[20] = {0};
    int readNumber, readNum, find = 0;
    //更改被借阅的图书的信息
    FILE *Book = fopen("d:/Book.txt", "r");
    FILE *Book1 = fopen("d:/Book1.txt", "w");
    while (!feof(Book))
    {
        fscanf(Book, "%d %s %d\n", &readNumber, readName, &readNum);
        if(strcmp(name, readName)==0)
        {  
            find = 1;
            if(readNum<1)
            {
                printf("借阅失败:无剩余可借阅的%s！\n", readName);
                return;
            }
            fprintf(Book1, "%d %s %d\n", readNumber, readName, readNum-1); //若找到需要借阅的图书，则在此书数量上减1 
        } 
        else
            fprintf(Book1, "%d %s %d\n", readNumber, readName, readNum);  //删除前的写入的序号 读者名 所借书和换行符 
    }
    if(find==0)  //若没找到此书
    {
        printf("借阅失败:没有找到此书！\n");
        return;
    }
    fclose(Book);
    fclose(Book1);
    Book1 = fopen("d:/Book1.txt", "r");
    Book = fopen("d:/Book.txt", "w+");   //刷新原文件，再次写入正确数据
    while(!feof(Book1))
    {
        fscanf(Book1, "%d %s %d\n", &readNumber, readName, &readNum);
        fprintf(Book, "%d %s %d\n", readNumber, readName, readNum);
    }
    fclose(Book1);
    fclose(Book);
    remove("d:/Book1.txt");  //删除原文件 
    //更改读者的信息
    FILE *Users = fopen("d:/Users.txt", "r");
    FILE *Users1 = fopen("d:/Users1.txt", "w");
    char borrowBook[20] = {"None"};
    while (!feof(Users))
    {
        fscanf(Users, "%d %s %s\n", &readNumber, readName, borrowBook);
        if(strcmp(readerName, readName)==0)
            fprintf(Users1, "%d %s %s\n", readNumber, readName, name); //在读者的借阅图书上写上所借阅的图书名 
        else
            fprintf(Users1, "%d %s %s\n", readNumber, readName, borrowBook); 
    }
    fclose(Users1);
    fclose(Users);
    Users1 = fopen("d:/Users1.txt", "r");
    Users = fopen("d:/Users.txt", "w+");   //刷新原文件，再次写入正确数据
    while(!feof(Users1))
    {
        fscanf(Users1, "%d %s %s\n", &readNumber, readName, borrowBook);
        fprintf(Users, "%d %s %s\n", readNumber, readName, borrowBook);
    }
    fclose(Users1);
    fclose(Users);
    remove("d:/Users1.txt");  //删除原文件  有时候还是删不掉
    printf("借阅成功！\n"); 
}

//还书函数
void returnBooking(char readerName[], char borrowBook[])
{
    char readName[20] = {0};
    int readNumber, readNum, find = 0;
    //更改被还回的图书的信息
    FILE *Book = fopen("d:/Book.txt", "r");
    FILE *Book1 = fopen("d:/Book1.txt", "w");
    while (!feof(Book))
    {
        fscanf(Book, "%d %s %d\n", &readNumber, readName, &readNum);
        if(strcmp(borrowBook, readName)==0)
        {
            fprintf(Book1, "%d %s %d\n", readNumber, readName, readNum+1); //若找到被还的图书，则在此书数量上加1  
            find = 1;
        }
        else
            fprintf(Book1, "%d %s %d\n", readNumber, readName, readNum); //不是还回的书 
    }
    fclose(Book);
    fclose(Book1);
    Book1 = fopen("d:/Book1.txt", "r");
    Book = fopen("d:/Book.txt", "w+");   //刷新原文件，再次写入正确数据
    while(!feof(Book1))
    {
        fscanf(Book1, "%d %s %d\n", &readNumber, readName, &readNum);
        fprintf(Book, "%d %s %d\n", readNumber, readName, readNum);
    }
    bookNumber = readNumber+1;
    fclose(Book1);
    fclose(Book);
    remove("d:/Book1.txt");  //删除原文件
    if(find==0)  //还书时没有书城中没有此书，直接添加一本
    {
        FILE *Book;
        Book = fopen("d:/Book.txt", "a");  
        fprintf(Book, "%d %s 1\n", bookNumber, borrowBook);  //写入序号 书名 数量和换行符
        bookNumber++; 
        fclose(Book);
    }
    //更改读者的信息
    FILE *Users = fopen("d:/Users.txt", "r");
    FILE *Users1 = fopen("d:/Users1.txt", "w");
    char rborrowBook[20] = {"None"};
    while (!feof(Users))
    {
        fscanf(Users, "%d %s %s\n", &readNumber, readName, rborrowBook);
        if(strcmp(readerName, readName)==0)
            fprintf(Users1, "%d %s %s\n", readNumber, readName, "None"); //还回书后所借阅图书变为"None" 
        else
            fprintf(Users1, "%d %s %s\n", readNumber, readName, rborrowBook); 
    }
    fclose(Users1);
    fclose(Users);
    Users1 = fopen("d:/Users1.txt", "r");
    Users = fopen("d:/Users.txt", "w+");   //刷新原文件，再次写入正确数据
    while(!feof(Users1))
    {
        fscanf(Users1, "%d %s %s\n", &readNumber, readName, rborrowBook);
        fprintf(Users, "%d %s %s\n", readNumber, readName, rborrowBook);
    }
    fclose(Users1);
    fclose(Users);
    remove("d:/Users1.txt");  //删除原文件  有时候还是删不掉
    printf("成功还回%s\n", borrowBook);
}

//单独查询功能，根据编号或书名查询书被哪些人借走
void searchBook()
{
    while (1)
    {
        int function = 0;
        FILE *Book = fopen("d:/Book.txt", "r");
        FILE *Users = fopen("d:/Users.txt", "r");
        char readerName[20] = {0}, bookName[20] = {0}, borrowBook[20] = {0}, name[20] = {0};
        int bookNumber, bookNum, find = 0, readerNumber;
        printf("                   Search                   \n");
        printf("[------------------------------------------]\n");
        printf("\t\t请选择查询功能：\n\t1.根据编号查询\n\t2.根据书名查询\n\t3.返回主界面\n");
        printf("[------------------------------------------]\n");
        scanf("%d",&function); // 输入需要的功能
        switch (function)
        {
            case 1:
                printf("您要查找的书序号是：");
                scanf("%d",&function); // 输入需要查找的图书编号
                while(!feof(Book))
                {
                    fscanf(Book, "%d %s %d\n", &bookNumber, bookName, &bookNum); //由于bookName已经表示地址，不需要取地址符
                    if(bookNumber==function)  //发现查找的书后跳出循环
                    {
                        find = 1;//找到书
                        break;
                    }
                }
                if(find==0)
                {
                    printf("没有找到编号为%d的图书。\n",function);
                    break;
                }
                printf("               Search Result                \n");
                printf("[------------------------------------------]\n");
                find = 0;//需要在查找谁借阅时再次使用
                printf("\t编号：\t\t%d\n\t书名：\t\t%s\n\t剩余数量：\t%d\n\t",bookNumber, bookName, bookNum);
                while (!feof(Users))
                {
                    fscanf(Users, "%d %s %s\n", &readerNumber, readerName, borrowBook);//遍历读者查找谁借阅了这本书   
                    if (strcmp(borrowBook, bookName)==0)
                    {
                        if(find==0)
                        {
                            find = 1;
                            printf("借阅此书的读者：");
                            printf("%s",readerName);
                        }
                        else
                            printf(" ,%s",readerName);
                    }
                }
                if(find==0)
                    printf("还没有读者借阅此书。\n");
                else
                    printf("\n");
                printf("[------------------------------------------]\n");
                printf("输入回车返回...\n");
                enter = getchar();
                enter = getchar();
                break;
            case 2:
                printf("您要查找的书名是：");
                scanf("%s",name); // 输入需要查找的图书名
                while(!feof(Book))
                {
                    fscanf(Book, "%d %s %d\n", &bookNumber, bookName, &bookNum); //由于bookName已经表示地址，不需要取地址符
                    if(strcmp(bookName, name)==0)  //发现查找的书后跳出循环
                    {
                        find = 1;//找到书
                        break;
                    }
                }
                if(find==0)
                {
                    printf("没有找到名称为%s的图书。\n",name);
                    break;
                }
                printf("               Search Result                \n");
                printf("[------------------------------------------]\n");
                find = 0;//需要在查找谁借阅时再次使用
                printf("\t编号：\t\t%d\n\t书名：\t\t%s\n\t剩余数量：\t%d\n\t",bookNumber, bookName, bookNum);
                while (!feof(Users))
                {
                    fscanf(Users, "%d %s %s\n", &readerNumber, readerName, borrowBook);//遍历读者查找谁借阅了这本书   
                    if (strcmp(borrowBook, bookName)==0)
                    {
                        if(find==0)
                        {
                            find = 1;
                            printf("借阅此书的读者：");
                            printf("%s",readerName);
                        }
                        else
                            printf(" ,%s",readerName);
                    }
                }
                if(find==0)
                    printf("还没有读者借阅此书。\n");
                else
                    printf("\n");
                printf("[------------------------------------------]\n");
                printf("输入回车返回...\n");
                enter = getchar();
                enter = getchar();
                break;
            case 3:
                return;
            default:
                printf("您输入的格式有误，请重新输入\n");
                break;
        }
        fclose(Book);
        fclose(Users);
    }
}

int main(int argc, char *argv[])  //需要从命令行读入参数
{
    char identity1[] = "-u";  //读者身份
    char identity2[] = "-a";  //管理员身份
    FILE *Book, *Users;  //两个文件分别存储图书信息和读者信息。
	int function1, function2; //功能选项
    /*调试用
    char readerName[20] = {0};
    int test = 0;
    scanf("%d %s",&test, readerName);
    if(test==1)
    */
    if(strcmp(argv[1], identity2)==0)  //管理员操作界面
    {
        char Administrator[20] = "Zhang";
        if(strcmp(Administrator, argv[2])==0)
        {    
            while(1)
            {   
                printf("                    menu                    \n");
                printf("[------------------------------------------]\n");
                printf("     管理员您好！请选择您要使用的功能:\n  1.新增或修改图书信息\n  2.新增或修改读者信息\n  3.查看全部馆藏书籍\n  4.查看全部读者及其借阅信息\n  5.图书详情查询\n  6.结束程序\n");
                printf("[------------------------------------------]\n");
                scanf("%d",&function1);  
                switch (function1)
                {
                    case 1:  //更改图书信息
                        printf("                  Books                     \n");
                        printf("[------------------------------------------]\n");
                        printf("\t请选择要对图书进行的操作：\n  1.添加图书信息\n  2.修改图书信息\n  3.删除图书信息\n  4.返回主菜单\n");
                        printf("[------------------------------------------]\n");
                        scanf("%d",&function2);  //输入第二级操作指令
                        switch (function2)
                        {
                            case 1:
                                addBook(Book);  //调用添加图书函数
                                
                                break;
                            case 2:
                                changeBook(Book);  //修改函数
                                break;
                            case 3:
                                scanf("%c",&enter);
                                delBook(Book);  //删除函数
                                break;
                            case 4:
                                break;
                            default:
                                printf("输入的值令有误，请重新输入");
                                break;
                        }
                        break;
                    case 2:  //更改读者信息
                        printf("                  Readers                   \n");
                        printf("[------------------------------------------]\n");
                        printf("\t请选择要对用户进行的操作：\n  1.添加用户信息\n  2.修改用户信息\n  3.删除用户信息\n");
                        printf("[------------------------------------------]\n");
                        scanf("%d",&function2);  //输入第二级操作指令
                        switch (function2)
                        {
                            case 1:
                                addUsers(Users);  //添加用户信息
                                break;
                            case 2:
                                changeUsers(Users);  //修改用户信息
                                break;
                            case 3:
                                scanf("%c",&enter);
                                delUsers(Users);  //删除用户信息
                                break;
                            default:
                                printf("输入的值令有误，请重新输入");
                                break;
                        }
                        break;
                    case 3:
                        showBook(Book);
                        printf("输入回车返回...\n");
                        enter = getchar();
                        enter = getchar();
                        break;
                    case 4:
                        showUsers(Users);
                        printf("输入回车返回...\n");
                        enter = getchar();
                        enter = getchar();
                        break;
                    case 5:
                        searchBook();
                        break;
                    case 6:
                        printf("感谢您的使用，再见！");
                        return 0;
                    default:
                        printf("输入格式有误，请重新输入!");
                        break;
                }
            }
        }
        else
            printf("管理员名有误，请重新输入！");
    }
    /*
    else if(test == 2)
    */                       
    else if (strcmp(argv[1], identity1)==0)  //读者的操作界面
    {
        char readName[20] = {0}, borrowBook[20] = {"None"};
        int readNumber,find = 0;
        FILE *Users = fopen("d:/Users.txt","r");  //需要判断是否存在此用户
        while (!feof(Users))
        {
            fscanf(Users, "%d %s %s\n", &readNumber, readName, borrowBook);
            if(strcmp(argv[2], readName)==0)
            {   
                find = 1;
                break;
            }
        }
        fclose(Users);
        if(find==0)
        {
            printf("不存在用户名为%s的读者！", argv[2]);
            return 0;
        }
        while (1)
        {
            FILE *Users = fopen("d:/Users.txt","r");  //刷新用户的借阅信息
            while (!feof(Users))
            {
                fscanf(Users, "%d %s %s\n", &readNumber, readName, borrowBook);
                if(strcmp(argv[2], readName)==0)
                    break;
            }
            fclose(Users);

            printf("                    menu                    \n");
            printf("[------------------------------------------]\n");
            printf("\t读者%s您好！请选择您要使用的功能:\n  1.借阅图书\n  2.还回图书\n  3.查看全部馆藏书籍\n  4.结束程序\n", argv[2]);
            printf("[------------------------------------------]\n");
            scanf("%d",&function1);  
            switch (function1)
            {
                case 1:  //借阅图书
                    if(strcmp(borrowBook, "None")==0)
                        borrowBooking(argv[2]);
                    else
                        printf("您已经借阅图书，请先还书再进行借阅操作。\n");
                    printf("输入回车返回...\n");
                    enter = getchar();
                    enter = getchar();
                    break;
                case 2:  //还书
                    if(strcmp(borrowBook, "None")!=0)
                        returnBooking(argv[2], borrowBook);
                    else
                        printf("您当前还没有借阅图书。\n");
                    printf("输入回车返回...\n");
                    enter = getchar();
                    enter = getchar();
                    break;
                case 3:
                    showBook(Book);
                    printf("输入回车返回...\n");
                    enter = getchar();
                    enter = getchar();
                    break;
                case 4:
                    printf("感谢您的使用，再见！");
                    return 0;
                default:
                    printf("输入格式有误，请重新输入!");
                    break;
            }
        }
    }
    else
        printf("您输入的格式有误，请重新输入!");
    return 0;
}
