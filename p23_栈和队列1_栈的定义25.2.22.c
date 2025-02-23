/*

创建一个栈

入栈

出栈

*/


#include<stdio.h>
#include<stdlib.h>

#define STACK_INIT_SIZE 100

typedef struct
{
    int *base;
    int *top;
    int stackSize;
}Stack;

//初始化栈
void initStack(Stack *s);

//入栈
void push(Stack *s, int a);

//出栈
void pop(Stack *s);

int main()
{
    Stack s;
    initStack(&s);
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    pop(&s);
    pop(&s);
    pop(&s);
    pop(&s);
    
    return 0;
}

void initStack(Stack *s)
{
    s->base = (int *)malloc(STACK_INIT_SIZE * sizeof(int));
    if(!s->base)
    {
        exit(0);
    }
    s->top = s->base;//最开始栈顶就是栈底
    s->stackSize = STACK_INIT_SIZE;
}

void push(Stack *s, int a)
{
    if(*(s->top) == STACK_INIT_SIZE - 1)
    {
        printf("栈已满!\n");
        return;
    }
    else
    {
        printf("压入%d\n",a);
        *(s->top) = a;
        s->top++;
    }
}

void pop(Stack *s)
{
    if(s->top == s->base)
    {
        printf("栈已空空如也\n");
        return;
    }
    else
    {
        s->top--;
        printf("弹出%d\n",*(s->top));
    }
}
