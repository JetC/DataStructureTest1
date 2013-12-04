//
//  main.c
//  DataStructureTest1
//
//  Created by 孙培峰 on 13-11-26.
//  Copyright (c) 2013年 孙培峰. All rights reserved.
//
#define lengthOfTheCreatingList 8

#include <stdio.h>
#include <stdlib.h>


//node为节点
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode, *linkedList;//LNode只是对此类的代称,linkedList才是可运用的表

//linkedList createLinkedListWithoutHeader(lengthOfTheCreatingList)
//{
//    linkedList p,q,r,listToBeCreated = NULL;//linkedList与pqr是同等的事物所有没有星号,p是辅助查找的指针
//    for (int i = 0; i < lengthOfTheCreatingList ; i++)
//    {
//        p = (linkedList)malloc(sizeof(linkedList));//申请了一个元素所占的空间
//
//        p->next = NULL;
//        p->data = i;
//        if (i != lengthOfTheCreatingList-1 && 0<= i <lengthOfTheCreatingList)//不是要创建尾节点
//        {
//            q = (linkedList)malloc(sizeof(linkedList));
//            listToBeCreated->data = p->data
//            listToBeCreated->next = q;
//        }
//        else if (i == lengthOfTheCreatingList-1)
//        {
//            listToBeCreated->next = NULL;
//        }
//    }
//    return listToBeCreated;
//
//}
void printLink( linkedList l ) {
    
    linkedList q;
    
    q = l->next;
    
    q = (linkedList)malloc(sizeof(linkedList));
    while ( q->next != NULL ) {
        
        printf("%d ", q->data);
        
        q = q->next;
        
    }
    
    printf("%d\n", q->data);	//打印最后一个元素
    
}


int main(int argc, char const *argv[])
{
	linkedList p,q = NULL,listToBeCreated = NULL;//linkedList与pqr是同等的事物所有没有星号,p是辅助查找的指针
    listToBeCreated = (linkedList)malloc(sizeof(linkedList));
    listToBeCreated ->next = NULL;
    
    
    for (int i = 1; i <= lengthOfTheCreatingList ; i++)
    {
        p = (linkedList)malloc(sizeof(linkedList));//申请了一个元素所占的空间
        p->data = i;
        if (i != lengthOfTheCreatingList-1)//不是要创建尾节点
        {
            q = (linkedList)malloc(sizeof(linkedList));
            listToBeCreated = (linkedList)malloc(sizeof(linkedList));
            listToBeCreated->data = p->data;
            p->next = NULL;
        }
        else if (i == lengthOfTheCreatingList)
        {
            listToBeCreated->next = NULL;
        }
        
        p = p->next;//负责寻找的p移到下一个
        
    }
    //    if ( !list->next ) {
    //
    //        list->next = p;	//赋值头节点用
    //
    //    }
    //
    //    else {
    //
    //        r->next = p;//赋值其他节点用
    //
    //    }
    //
    //    r = p;	//移动r指针,指向下一个节点
    //
    //}
    printLink(listToBeCreated);
    return 0;
    
}














