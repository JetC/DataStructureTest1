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
}LNode, *linkList;//LNode只是对此类的代称,linkList才是可方便地用做程序中的



linkList initListWithLength(int lengthOfTheCreatingList)
{
    
    
    linkList p, r, list;//p和r和list各是一个结构体
    //p负责建立新节点,r负责
    
    list = (linkList)malloc(sizeof(LNode));
    
    list->next = NULL;//建立了一个只有一个元素的list
    
    for (int i = 1; i <= lengthOfTheCreatingList; i++)
    {
        
        p = (linkList)malloc(sizeof(LNode));//每次循环都为p新分配一个空间,不再影响已被引用过的链表元素位置
        
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

void printLinkedList(linkList listToBePrinted)
{
    linkList p = NULL;
    
    while (listToBePrinted->next)
    {
        
        printf("%i\n",listToBePrinted->data);
        p = (linkList)malloc(sizeof(linkList));
        p = listToBePrinted->next;
        listToBePrinted = p;
        
    }
    
    printf("%i\n",listToBePrinted->data);
    
    free(p);
}


int main(int argc, char const *argv[])
{
    
    
    printLinkedList(initListWithLength(90));
    return 0;
    
    
    
    
}