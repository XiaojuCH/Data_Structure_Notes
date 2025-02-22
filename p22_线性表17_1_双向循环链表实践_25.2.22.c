/*

课堂演示题目:
-要求实现用户输入一个数使得26个字母的排列发生变化，例如用户输入3，输出结果:
-DEFGHIJKLMNOPORSTUVWXYZABC
-同时需要支持负数，例如用户输入-3，输出结果:
-XYZABCDEFGHIJKLMNOPORSTUVW

*/

#include<stdio.h>
#include<stdlib.h>

typedef struct List
{
    char data;
    struct List *prior;//指向上一个节点
    struct List *next;//指向下一个节点
}List;

List *head;
List *tail;

List createList();
void readList(List *Head);

int main()
{
    int N;
    printf("请输入需要移动的数:\n");
    scanf("%d",&N);

    createList();
    printf("原来的排序:\n");
    readList(head);

    printf("移动后的排序:\n");
    if(N > 0)
    {
        int count = 0;

        //正着开
        for(int i = 0 ; i < N ; i++)
        {
            head = head->next;
        }

        for(List *p = head; count++ < 26; p = p->next)
        {
            printf("%c ",p->data);
        }
        printf("\n");
    }
    else
    {
        int count = 0;

        //倒着开
        for(int i = 0 ; i > N ; i--)
        {
            head = head->prior;
        }

        for(List *p = head; count++ < 26; p = p->next)
        {
            printf("%c ",p->data);
        }
        printf("\n");
    }

    return 0;
}

List createList()
{   
    for(int i = 0 ; i < 26 ; i++)
    {
        List *new = (List *)malloc(sizeof(List));
        new->data = 'A' + i;

        if(!head)
        {
            head = new;
            tail = new;
        }
        else
        {
            tail->next = new;
            new->prior = tail;
            tail = tail->next;
        }
        tail->next = NULL;
    }
    tail->next = head;
    head->prior = tail;

    return *head;
}

void readList(List *Head)
{
    int count = 0;
    for(List *p = Head; count++ < 26; p = p->next)
    {
        printf("%c ",p->data);
    }
    printf("\n");
}