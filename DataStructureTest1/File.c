
#import <stdio.h>

#import <stdlib.h>



int num=4;

int factorialCaculation(int n)

{
    
    if (n<=1)
        
    {
        
        return 1;
        
    }
    
    else
        
    {
        
        return n*factorialCaculation(n-1);
        
    }
    
    
    
}



#pragma mark OnSortingArray

void bubble(int *a,int n)

{
    
    int i,j,temp;
    
    for (i=0; i<n-1; i++)
        
    {
        
        for (j=i+1;j<n;j++)
            
        {
            
            if (a[i]>a[j])
                
            {
                
                temp=a[i];
                
                a[i]=a[j];
                
                a[j]=temp;
                
            }
            
            
            
        }
        
    }
    
    
    
}



#pragma mark LinkedList

void printArray(int *a,int n)

{
    
    int i;
    
    for(i=0;i<n;i++)
        
    {
        
        printf("%5d",a[i]);
        
    }
    
    printf("\n");
    
}







void display(int a[])

{
    
    for (int i=0 ;i<num;i++) {
        
        printf("%d",a[i]);
        
    }
    
    
    
}



typedef struct node{
    
    int data;
    
    struct node *next;
    
}LNode, *LinkList;





LinkList init( int len ) {
    
    int i;
    
    LinkList p = NULL, r = NULL, list = NULL;//p和r和list各是一个结构体
    
    list = (LinkList)malloc(sizeof(LNode));//初始化list
    
    //    list->next = NULL;
    
    for ( i = 0; i < len; i++ ) {
        
        p = (LinkList)malloc(sizeof(LNode));//为p分配一个元素的空间,p负责找单个元素
        
        p->data = i+1;//指定p内的内容
        
        //p->next = NULL;//p指向下一个的指针为空
        
        if ( !list->next )//list中的下一个节点未指定时
        {
            
            list->next = p;//居然只改变了next!
            
        }
        
        else {
            
            r->next = p;
            
        }
        
        r = p;	//移动r指针,指向下一个节点
        
    }
    
    return list;
    
}





void insertEle( LinkList l, int n, int e ) {
    
    LinkList p, q, ele;
    
    int i = 1;
    
    ele = (LinkList)malloc(sizeof(LNode));
    
    ele->data = e;
    
    ele->next = NULL;
    
    p = q = l->next;
    
    
    
    if ( n == 1 ) {	 //将元素添加到链表头
        
        l->next = ele;
        
        ele->next = q;
        
        return;
        
    }
    
    while ( i != n && q->next != NULL ) {
        
        p = q;
        
        q = q->next;
        
        i++;
        
    }
    
    if ( i == n ) {
        
        p->next = ele;
        
        ele->next = q;
        
    } else if( i < n ) {	//将元素添加到链表尾
        
        q->next = ele;
        
    }
    
}





void delNode( LinkList l, int n ) {
    
    LinkList p, q;
    
    int i = 1;
    
    p = q = l->next;
    
    if ( n == 1 ) {
        
        l->next = q->next;
        
    } else {
        
        while ( i != n && q->next != NULL ) {
            
            p = q;
            
            q = q->next;
            
            i++;
            
        }
        
        if ( i == n ) {
            
            p->next = q->next;
            
        }
        
    }
    
}





void printLink( LinkList l ) {
    
    LinkList q;
    
    q = l->next;
    
    while ( q->next != NULL ) {
        
        printf("%d ", q->data);
        
        q = q->next;
        
    }
    
    printf("%d\n", q->data);	//打印最后一个元素
    
}



#pragma mark Main

int main(int argc, const char * argv[])

{
    
    
    
    
    
    int a1[]={13,0,5,8,1,7,21,50,9,2};
    
    
    
    int a[num];
    
    //        int count=0;
    
    
    
    
    
    for (int i=0; i<num-1; i++) {
        
        for (int j=0; j<num-i-1; j++) {
            
            if (a[j]>a[j+1])
                
            {
                
                int tmp=a[j];
                
                a[j]=a[j+1];
                
                a[j+1]=tmp;
                
            }
            
        }
        
    }
    
    
    
    
    
    
    
    
    
    printf("The result of factorial caculation is:%d\n",factorialCaculation(6));
    
    
    
    printf("\nThe Origonal is:\n");
    
    printArray(a1, 10);
    
    
    
    printf("The sorted Array:\n");
    
    bubble(a1, 10);
    
    printArray(a1, 10);
    
    
    
    LinkList l;
    
    l = init(5);
    
    printf("\nThe Original list:\n");
    
    printLink(l);
    
    insertEle(l, 6, 10);
    
    printf("Inserted at end:\n");
    
    printLink(l);
    
    
    
    insertEle(l, 1, 0);
    
    printf("Inserted at start:\n");
    
    printLink(l);
    
    
    
    insertEle(l, 4, 2);
    
    printf("Inserted at middle:\n");
    
    printLink(l);
    
    
    
    delNode(l, 2);
    
    printf("The second num deleted:\n");
    
    printLink(l);
    
    
    
    
    
    
    
    
    
    return 0;
    
}