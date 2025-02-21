/*

题目:实现将两个线性表(a1，a2，…，an)和(b1，b2，…，bm)连接成一个线性表(a1，.an， b1，...bm)的运算

分析:
-若在单链表或头指针表示的单循环表上做这种链接操作，都需要遍历第一个链表，找到结点an，然后将结点b1链到an的后面，其执行时间是0(n)
-若在尾指针表示的单循环链表上实现，则只需修改指针，无须遍历，其执行时间是0(1)

*/

#include<stdio.h>

static int N = 5;
static int M = 5;

typedef struct List
{
    int num;
    char name;
    struct List *next;
}List;

List *head_A = NULL;
List *tail_A = NULL;

List *head_B = NULL;
List *tail_B = NULL;

int main()
{
    //构建链表A
    for(int i = 0 ; i < N ; i++)
    {
        List *newA = (List *)malloc(sizeof(List));
        if(!newA)
        {
            printf("内存分配错误!");
            break;
        }

        newA->num = i;
        newA->name = 'A';

        if(!head_A)
        {
            head_A = newA;
            tail_A = newA;
        }
        else
        {
            tail_A->next = newA;
            tail_A = tail_A->next;
        }
        tail_A->next = NULL;
    }

    //创建链表尾节点指针
    List *rearA = tail_A;

    tail_A->next = head_A;


    //构建链表B
    for(int i = 0 ; i < M ; i++)
    {
        List *newB = (List *)malloc(sizeof(List));
        if(!newB)
        {
            printf("内存分配错误!");
            break;
        }

        newB->num = i;
        newB->name = 'B';

        if(!head_B)
        {
            head_B = newB;
            tail_B = newB;
        }
        else
        {
            tail_B->next = newB;
            tail_B = tail_B->next;
        }
        tail_B->next = NULL;
    }

    List *rearB = tail_B;

    tail_B->next = head_B;

    int countA = 1;
    printf("线性表A:\n");
    for(List *p = head_A; p != NULL; p = p->next)
    {
        printf("%c%d->",p->name,p->num);
        countA++;
        if(countA > N) break;
    }
    int countB = 1;
    printf("\n线性表B:\n");
    for(List *p = head_B; p != NULL; p = p->next)
    {
        printf("%c%d->",p->name,p->num);
        countB++;
        if(countB > M) break;
    }

    //改变链表尾指针的指向，使其不再指向自己的头节点而是另一链表的头节点
    rearA->next = head_B;
    rearB->next = head_A;

    int countC = 0;
    printf("\n连接后:\n");
    for(List *p = head_A; p != NULL; p = p->next)
    {
        printf("%c%d->",p->name,p->num);
        countC++;
        if(0.5*countC > N + M) break;
    }

    return 0;
}
