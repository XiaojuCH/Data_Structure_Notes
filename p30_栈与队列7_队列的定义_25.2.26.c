/*

编写一个链队列，任意输入一串字符，以#作为结束标志，然后将队列中的元素显示到屏幕上

*/

#include<stdio.h>

typedef char ElemType;
typedef struct QNode
{
    ElemType data;
    struct QNode *next;
}QNode;

typedef struct LinkQueue
{
    QNode *front,*rear;
}LinkQueue;

void initQueue(LinkQueue *q);

int main()
{


    return 0;
}

void initQueue(LinkQueue *q)
{
    q->front = q->rear = (QNode *)malloc(sizeof(QNode));
    if(!q->front)
    {
        exit(0);
    }
    q->front->next = NULL;
}