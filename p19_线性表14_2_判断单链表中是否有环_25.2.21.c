/*
题目:判断单链表中是否有环
方法一:使用p、q两个指针，p总是向前走，但q每次都从头开始走，对于每个节点，看p走的步数是否和q一样

          ---<--<--<--<---
          |              |
1 -> 2 -> 3 -> 4 -> 5 -> 6
p
q

如上图当p从6走到3时，用了6步
此时若q从head出发，则只需两步就到3，因而步数不等，出现矛盾，存在环
*/

#include<stdio.h>

int isCircle = 0;

typedef struct List
{
    int num;
    struct List *next;
}List;

List *head = NULL;
List *tail = NULL;

//定义循环点
List *target = NULL;

int main()
{
    for(int i = 1 ; i < 7 ; i++)
    {
        List *new = (List *)malloc(sizeof(List));
        if(!new)
        {
            printf("内存分配失败!");
            return;
        }

        new->num = i;

        if(new->num == 3)
        {
            target = new;
        }

        if(!head)
        {
            head = new;
            tail = new;
        }
        else
        {
            tail->next = new;
            tail = tail->next;
        }
        tail->next = NULL;
    }

    tail->next = target;

    int countA = 0;
    printf("原列表：\n");
    for(List *p = head; p != NULL; p = p->next)
    {
        if(countA > 14) break;
        printf("%d->",p->num);
        countA++;
    }

    printf("\n\n判断是否有环中……\n\n");

    List *p = head;//总是往前走
    int stepP = 0;


    for(int i = 0 ; i < 20 && p->next != NULL; i++)
    {
        List *q = head;//总是从头开始走
        int stepQ = 0;

        if(p != NULL)
        {
            p = p->next;
            stepP++;
            printf("%d ",p->num);
        }

        for(int j = 0 ; j < i && q->next != NULL; j++)
        {
            if(p->num == q->num && stepP != stepQ)
            {
                isCircle = 1;
                break;
            }
            q = q->next;
            stepQ++;
            printf("%d",q->num);
        }
        printf("\n");
        
        if(isCircle)
        {
            printf("此处发现循环点为%d!\n",p->num);
            break;
        }
    }

    if(isCircle) 
    {
        printf("\n此单链表有环!!!\n");
    }
    else 
    {
        printf("\n此单链表无环!!!\n");
    }

    return 0;
}