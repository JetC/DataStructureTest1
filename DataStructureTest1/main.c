#include <stdio.h>
#include <stdlib.h>

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode;

LNode initLinkedList(int lenthOfTheCreatingList)
{
    LNode *p = NULL, *q = NULL, *linkedList = NULL;
    
    for (int i=1; i <= lenthOfTheCreatingList; i++)
    {
        p = (LNode *)malloc(sizeof(LNode));
        

        p->data = i;
        p->next = NULL;
        if (i == 1)
        {
            linkedList = (LNode *)malloc(sizeof(LNode));
            linkedList = p;
        }
        else
        {
            linkedList->next = (LNode *)malloc(sizeof(LNode));
            q = linkedList->next;
            q = p;
            linkedList->next = q;
            q = q->next;
            
#pragma mark 怎么把linkedlist转到下一个节点???
        }
        //p = p->next;
        //linkedList = linkedList->next;
        
    }
    
    return *linkedList;
}

int main(int argc, char const *argv[])
{
    initLinkedList(10);
    return 0;
}
