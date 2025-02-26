/*

编写一个链队列，任意输入一串字符，以#作为结束标志，然后将队列中的元素显示到屏幕上

*/

#include<stdio.h>
#include<stdlib.h>

typedef char ElemType;

typedef char ElemType;
typedef struct QNode
{
    ElemType data;
    struct QNode *next;
}QNode;

typedef struct LinkQueue
{
    QNode *front,*rear;
}Queue;

void initQueue(Queue *q);
void InsertQuene(Queue *q, ElemType e);
void DeleteQuene(Queue *q, ElemType *e);
void DestoryQuene(Queue *q);

int main()
{
    Queue q;
    int count = 0;
    initQueue(&q);
    printf("请意输入一串字符，以#作为结束标志:\n");
    ElemType ch;
    scanf("%1c",&ch);

    while(ch != '#')
    {
        InsertQuene(&q, ch);
        count++;
        scanf("%1c",&ch);
    }
    
    for(int i = 0 ; i < count ; i++)
    {
        ElemType show;
        DeleteQuene(&q,&show);
        printf("%c",show);
    }


    return 0;
}

void initQueue(Queue *q)
{
    q->front = q->rear = (QNode *)malloc(sizeof(QNode));
    if(!q->front)
    {
        exit(0);
    }
    q->front->next = NULL;
}

void InsertQuene(Queue *q, ElemType e)
{
    QNode *p = (QNode *)malloc(sizeof(QNode));
    if(!p)
    {
        exit(0);
    }
    p->data = e;
    p->next = NULL;
    q->rear->next = p;  //更新队尾
    q->rear = p;    //等价于q->rear = q->rear->next
}

void DeleteQuene(Queue *q, ElemType *e)
{
    QNode *p;

    //如果队列只有一个元素
    if(q->front == q->rear)
    {
        return;
    }

    p = q->front->next;
    *e = p->data;       // 保存删除的元素的数据

    q->front->next = p->next;  // 更新队列头指针，跳过删除的元素

    // 如果删除的是队列的尾部元素，需要更新队列的尾指针
    if (q->rear == p) {
        q->rear = q->front;
    }

    free(p);  // 释放删除的节点内存
}

void DestoryQuene(Queue *q)
{
    while(q->front)
    {
        q->rear = q->front->next;
        free(q->front);
        q->front = q->rear;
    }
}
