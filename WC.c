#include <stdio.h>
#include <stdilb.h> 
#define IN 1
#define OUT 0
int findchar(char*src,char ch)
{
    int c=0;
    while(*src!='\0')
    {
        if(*src==ch)
        c++;
        src++;   
     }
}
main()
{
    int c, nl, nw, nc, na, state;
    FILE *fp;
    char filename[];
    printf("请输入文件名:");
    scanf("%s",filename);
    if((fp=fopen(filename,"r"))==NULL)
    {
        printf("没有找到文件！\n");
        exit(0); 
     }
    state = OUT;
    nl = nw = nc = na = 0;
    /* 循环进行统计 */
    while (!feof(fp)) 
    {
        /* 统计字符 */
        ++nc;
        /* 统计注释 */
        if (c == '//'||c == '/*')
        ++na;
        /* 统计行数 */
        if (c == 'n')
        ++nl;
        /* 统计单词 */
        if (c == ' ' || c == '\n' || c == '\t')
        state = OUT;
        else if (state == OUT)
        {
            state = IN;
            ++nw;
         }
     }
     
     /* 统计某个字符数 */
     char fp,ch,count=0;
     printf("请输入查询的字符:\n");
     fgetc(fp);
     ch=fgetc();
     count=findchar(fp,ch);
     /* 输出结果 */
     printf("代码为%d行", nl);
     printf("代码有%d个字符", nc);
     printf("代码个%d单词", nw);
     printf("代码有%d条注释", na);
     printf("字符'%c'出现%d次。"ch,count);

     
}
