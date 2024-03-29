//
//  main.c
//  DataStructureTest1
//
//  Created by 孙培峰 on 13-11-26.
//  Copyright (c) 2013年 孙培峰. All rights reserved.
//
//#define lengthOfTheCreatingList 8

#include <stdio.h>
#include <stdlib.h>


//node为节点
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode, *OneWaylinkList;//LNode只是对此类的代称,linkList才是可方便地用做程序中的


typedef struct TWNode{
    int data;
    struct TWNode *next;
    struct TWNode *prev;
}TWNode, *TwoWayLinkedList;//双向链表


OneWaylinkList initOneWayListWithLength(int lengthOfTheCreatingList)
{
    
    
    OneWaylinkList p, r, list;//p和r和list各是一个结构体
    //p负责建立新节点,r负责
    
    list = (OneWaylinkList)malloc(sizeof(LNode));
    
    list->next = NULL;//建立了一个只有一个元素的list
    
    for (int i = 1; i <= lengthOfTheCreatingList; i++)
    {
        
        p = (OneWaylinkList)malloc(sizeof(LNode));//每次循环都为p新分配一个空间,不再影响已被引用过的链表元素位置
        
        p->data = i;//指定p内的内容
        
        p->next = NULL;//p指向下一个的指针为空
        
        if ( !list->next )
        {
            
            list->next = p;//这里是指针(地址)传递!两处指向的地址是一致的!
            
            //在第一次循环中,list的next被指向了刚创建的数据p的位置,在此语句完成赋值
        }
        
        else
        {
            
            r->next = p;//指针传递!两处指向的地址是一致的!
            
            //第二次循环中,r的next被指向了刚创建的数据p的位置,同时指定了list->next->next的地址,即在此处完成赋值
            //每次循环中p都是新的,即是在第二次循环中,本语句指出了list->next->next的位置
        }
        
        r = p;	//p的地址传给r,r中含有本次循环赋来的数据,第一次循环时即为list->next的地址传入了r中
        //上条else语句中p的地址给了r->next,本句中把p的地址给了r而不是它的子节点,相当于把r向下一个节点推进了(待修正)
    }
    return list;
    free(p);
    free(r);
    free(list);
}

TwoWayLinkedList initTwoWayListWithLength(int lengthOfTheCreatingList)
{
    TwoWayLinkedList p = NULL, r = NULL, list = NULL,q = NULL;//p和r和list各是一个结构体
    //p负责建立新节点,r负责
    
    list = (TwoWayLinkedList)malloc(sizeof(TwoWayLinkedList));
    
    list->next = NULL;//建立了一个只有一个元素的list
    
    for (int i = 1; i <= lengthOfTheCreatingList; i++)
    {
        
        p = (TwoWayLinkedList)malloc(sizeof(TWNode));//每次循环都为p新分配一个空间,不再影响已被引用过的链表元素位置
#pragma warning (error:123)
        /* FIXME: xxxx */
        // MARK: sss
        /* !!!: ssss */

        //要再熟悉sizeof的用法！
        p->data = i;//指定p内的内容
        p->prev = NULL;
        p->next = NULL;//p指向下一个的指针为空
        list->prev = NULL;
        
        
        if (i == 1)
        {
            
            list->next = p;//这里是指针(地址)传递!两处指向的地址是一致的!
            list->prev = NULL;
            //在第一次循环中,list的next被指向了刚创建的数据p的位置,在此语句完成赋值
        }
        
        else if(i >= 2)
        {
#pragma mark !!!NextError!
            
            r->prev = q;
            r->next = p;//指针传递!两处指向的地址是一致的!
            
            //第二次循环中,r的next被指向了刚创建的数据p的位置,同时指定了list->next->next的地址,即在此处完成赋值
            //每次循环中p都是新的,即是在第二次循环中,本语句指出了list->next->next的位置
        }
        q = p;  //q负责记录上一个指针的位置
        r = p;	//p的地址传给r,r中含有本次循环赋来的数据,第一次循环时即为list->next的地址传入了r中
        //上条else语句中p的地址给了r->next,本句中把p的地址给了r而不是它的子节点,相当于把r向下一个节点推进了(待修正)
    }
    return list;
}

void printLinkedList(OneWaylinkList listToBePrinted)
{
    OneWaylinkList p = NULL;
    
    while (listToBePrinted->next)
    {
        
        printf("%i\n",listToBePrinted->data);
        p = (OneWaylinkList)malloc(sizeof(OneWaylinkList));
        p = listToBePrinted->next;
        listToBePrinted = p;
        
    }
    
    printf("%i\n",listToBePrinted->data);
    
    free(p);
}

void printTwoWayLinkedList(TwoWayLinkedList listToBePrinted)
{
    TwoWayLinkedList p = NULL;
    
    while (listToBePrinted->next)
    {
        
        printf("%i\n",listToBePrinted->data);
        p = (TwoWayLinkedList)malloc(sizeof(TwoWayLinkedList));
        p = listToBePrinted->next;
        listToBePrinted = p;
        
    }
    
    printf("%i\n",listToBePrinted->data);
    
    free(p);
}

int main(int argc, char const *argv[])
{
    
    
    //printLinkedList(initOneWayListWithLength(900));
    printTwoWayLinkedList(initTwoWayListWithLength(900));
    
    return 0;
    
    
    
    
}