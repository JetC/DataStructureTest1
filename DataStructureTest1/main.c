#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0

//定义双向链表

typedef struct DNode
{
    char data;
    struct DNode *piror;
    struct DNode *next;
}DNode,*Doublelist;

void DInit(Doublelist *L)
{
    *L=(DNode *)malloc(sizeof(DNode));
    (*L)->next=NULL;
    (*L)->piror=NULL;
}
void DCreate(Doublelist L)
{
    int i;
    char c;
    DNode *p;
    p=L;
    //p=(DNode *)malloc(sizeof(DNode));
    printf("please input the string you want:");
    while(1)
    {
//        c=getchar();
//        if(c=='$')
//            break;
        c = 's';
        p->data=c;
        p->next=(DNode *)malloc(sizeof(DNode));
        p->next->piror=p;//指明前趋与后继的关系
        p=p->next;
        //    c=getchar();
    }
    printf("创建完成后的链表输出：");
    //    p->next=q;
    //    q->piror=p;
}
//双向链表的插入操作

int DInsert(Doublelist L,int i,char c)
{
    DNode *s=NULL;
    DNode *p=NULL;
    int j=0;
    p=L->next;
    s=(DNode *)malloc(sizeof(DNode));
    s->piror=NULL;
    s->next=NULL;
    printf("插入后的链表输出:");
    
    if(s==NULL)
        exit(1);
    while(j<i&&p)
    {
        p=p->next;
        j++;
    }
    if(j==i&&i!=0)
    {
        s->data=c;
        s->piror=p->piror;
        s->next=p;
        p->piror->next=s;
        p->piror=s;
        return TRUE;
    }
    return FALSE;
}
//双向链表的删除
int DDelet(Doublelist L,int i,char c)
{
    DNode *p;
    int j=0;
    int flag=1;
    p=L->next;
    printf("删除后的链表输出:");
    while(flag)
    {
        if(p&&j<i)
        {
            p=p->next;
            j++;
        }
        else
            flag=0;
    }
    if(p&&j==i)
    {
        p->piror->next=p->next;
        p->next->piror=p->piror;
        free(p);
        return TRUE;
    }
    return FALSE;
    
}
void DPrint(Doublelist L)
{
    DNode *p;
    p=L;
    while(p)
    {
        printf("%c",p->data);
        p=p->next;
    }
    printf("\n");
}
int main()
{
    Doublelist L;
    char c;
    int i,k;
    DInit(&L);
    DCreate(L);
    DPrint(L);
    printf("请输入想插入字符的位置和相插入的字符值：");
//    scanf("%d %c",&i,&c);
    i = 0;
    c = 4;
    DInsert(L,i,c);
    DPrint(L);
    i=0;
    c=0;
    printf("请输入想要删除字符的位置和相应的字符值：");
//    scanf("%d %c",&i,&c);
    DDelet(L,i,c);
    DPrint(L);
    return 0;
}