/*
拉丁方阵是一种nxn的方阵，方阵中恰有n种不同的元素，每种元素恰有n个，并且每种元素在一行和一列中 恰好出现一次
著名数学家和物理学家欧拉使用拉丁字母来作为拉丁方阵里元素的符号拉丁方阵因此而得名

例如下图是一个3x3的拉丁方阵:

    1   2   3
    2   3   1
    3   1   2

*/

#include<stdio.h>
#include<stdlib.h>

typedef struct List
{
    int num;
    struct List *next;
}List;

//创建循环链表
List createList(N);

List *head = NULL;
List *tail = NULL;

int main()
{
    int N;
    printf("请输入需要生成拉丁方阵的行列数N:\n");
    scanf("%d",&N);

    createList(N);

    for(int i = 0 ; i < N ; i++)
    {
        int current = 0;
        for(List *p = head; current < N; p = p->next)
        {
            printf("%d ",p->num);
            current++;
        }

        //每打印一行后循环链表的头节点往后一位
        head = head->next;
        
        printf("\n");
    }

    return 0;
}

List createList(N)
{   
    for(int i = 1; i <= N; i++)
    {
        List *new = (List *)malloc(sizeof(List));
        if(!new)
        {
            printf("内存分配失败!");
            return;
        }
        new->num = i;

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
    tail->next = head;

    return *head;
}