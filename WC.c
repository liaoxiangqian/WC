#include <stdio.h> 
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
    state = OUT;
    nl = nw = nc = na = 0;
    /* ѭ������ͳ�� */
    while ((c = getchar()) != EOF) 
    {
        /* ͳ���ַ� */
        ++nc;
        /* ͳ��ע�� */
        if (c == '//'||c == '/*')
        ++na;
        /* ͳ������ */
        if (c == 'n')
        ++nl;
        /* ͳ�Ƶ��� */
        if (c == ' ' || c == '\n' || c == '\t')
        state = OUT;
        else if (state == OUT)
        {
            state = IN;
            ++nw;
         }
     }
     /* ������ */
     printf("����Ϊ%d��", nl);
     printf("������%d���ַ�", nc);
     printf("�����%d����", nw);
     printf("������%d��ע��", na);

     /* ͳ��ĳ���ַ��� */
     char str[],ch,count=0;
     printf("�������ѯ���ַ�:\n");
     gets(str);
     ch=getchar();
     count=findchar(str,ch);
     printf("�ַ�'%c'����%d�Ρ�"ch,count);
}
