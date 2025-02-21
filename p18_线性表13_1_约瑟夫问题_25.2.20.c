/*问题:用循环列表模拟约瑟夫问题,把41个人自杀的顺序编号输出*/

#define STEP 2

#include<stdio.h>


typedef struct List
{
    int num;//名字
    int isOut;//0表示没有被淘汰
    struct List *next;
}List;

List *head = NULL;
List *tail = NULL;

static const int count = 0;

int main()
{
    for(int i = 1; i < 42; i++)
    {
        List *new = (List*)malloc(sizeof(List));
        if(new == NULL)
        {
            printf("内存分配失败!");
            return;
        }
        
        new->num = i;
        new->isOut = 0;

        if(head == NULL)
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

    List *current = head;//现在的节点
    List *prev = tail;//上一个节点

    // 模拟约瑟夫环
    int count = 0;
    while(count < 41)
    {
        for(int i = 0 ; i < STEP ; i++)
        {
            prev = current;
            current = current->next;
        }

        printf("%d ",current->num);

        prev->next = current->next;
        free(current);
        current = prev->next;
        count++;
    }

    return 0;
}