/*
问题描述:魔术师利用一副牌中的13张黑牌，预先将他们排好后叠放在一起，牌面朝下
对观众说:我不看牌，只数数就可以猜到每张牌是什么，我大声数数，你们听，不信?
现场演示
魔术师将最上面的那张牌数为1，把他翻过来正好是黑桃A，将黑桃A放在桌子上
第二次数1，2，将第一张牌放在这些牌的下面，将第二张牌翻过来，正好是黑桃2，也将它放在桌子上这样依次进行将13张牌全部翻出，准确无误

问题:牌的开始顺序是如何安排的?
*/

#include<stdio.h>
#include<stdlib.h>


typedef struct List
{
    int num;
    struct List *next;
}List;

List *head = NULL;
List *tail = NULL;

int main()
{
    for(int i = 1 ; i <= 13 ; i++)
    {
        List *new = (List *)malloc(sizeof(List));
        if(!new)
        {
            printf("内存分配错误!");
            exit(0);
        }
        new->num = 0;

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

    int count = 2;

    List *p = head;
    p->num = 1;

    while(1)
    {
        for(int i = 0 ; i < count ; i++)
        {
            p = p->next;
            if(p->num != 0)
            {
                i--;
            }
        }
        if(p->num == 0)
        {
            p->num = count;
            count++;

            if(count == 14) break;
        }
    }

    int times = 0;
    for(List *q = head; q != NULL && times < 13; q = q->next)
    {
        times++;
        printf("%d ",q->num);
    }

    return 0;
}