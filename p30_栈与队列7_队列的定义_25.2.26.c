/*

��дһ�������У���������һ���ַ�����#��Ϊ������־��Ȼ�󽫶����е�Ԫ����ʾ����Ļ��

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