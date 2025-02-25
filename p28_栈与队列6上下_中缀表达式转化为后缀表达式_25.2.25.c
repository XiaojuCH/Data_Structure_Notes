/*

将中缀表达式转化为后缀表达式
例如：
(1 - 2) * (4 + 5) 转化为 1 2 - 4 5 + *

*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define STACK_INIT_SIZE 20
#define STACKINCRIMENT  10
#define MAXBUFFER       10

typedef char ElemType;
typedef struct Stack
{
    ElemType *base;
    ElemType *top;
    int stackSize;
}Stack;

void initStack(Stack *s);
void Push(Stack *s, ElemType e);
void Pop(Stack *s, ElemType *e);
int StackLen(Stack s);

int main()
{
    Stack s;
    initStack(&s);

    printf("请输入待计算数据,以#作为结束标志:\n");

    char ch;
    char e;
    scanf("%c",&ch);
    while(ch != '#')
    {
        while(ch >= '0' && ch <= '9')
        {
            printf("%c",ch);
            scanf("%c",&ch);
            if(ch < '0' || ch > '9')
            {
                printf(" ");
            }
        } 
        if(')' == ch)
        {
            Pop(&s,&e);
            while('(' != e)
            {
                printf("%c ",e);
                Pop(&s,&e);
            }
        }
        else if('+' == ch || '-' == ch )
        {
            if( !StackLen(s))
            {
                Push(&s,ch);
            }
            else
            {
                do
                {
                    Pop(&s,&e);
                    if('(' == e)
                    {
                        Push(&s,e);
                    }
                    else
                    {
                        printf("%c ",e);
                    }
                } while (StackLen(s) && '(' != e);
                Push(&s,ch);
            }
        }
        else if('*' == ch || '/' == ch || '(' == ch)
        {
            Push(&s,ch);
        }
        else if('#' == ch)
        {
            break;
        }
        else
        {
            printf("\n出错!输入格式错误\n");
            return -1;
        }

        scanf("%c",&ch);
    }
 
    while (StackLen(s))
    {
        Pop(&s, &e);
        printf("%c", e);
    }
    
    return 0;
}

void initStack(Stack *s)
{
    s->base = (ElemType *)malloc(STACK_INIT_SIZE * (sizeof(ElemType)));
    if(!s->base)
    {
        exit(0);
    }
    s->top = s->base;
    s->stackSize = STACK_INIT_SIZE;
}

void Push(Stack *s, ElemType e)
{
    if(s->top - s->base >= s->stackSize)
    {
        s->base = (ElemType *)realloc(s->base, (s->stackSize + STACKINCRIMENT) * sizeof(ElemType));
        if(!s->base)
        {
            exit(0);
        }

        s->top = s->base + s->stackSize;
        s->stackSize = s->stackSize + STACKINCRIMENT;
    }

    *(s->top) = e;
    s->top ++;
}

void Pop(Stack *s, ElemType *e)
{
    if(s->top == s->base)
    {
        return;
    }

    *e = *--(s->top);
}

int StackLen(Stack s)
{
    return (s.top - s.base);
}
