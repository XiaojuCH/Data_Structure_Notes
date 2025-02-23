/*
题目:利用栈的数据结构特点，将二进制转换为十进制数

分析:地球人都知道，二进制数是计算机数据的存储形式，它是由一串0和1组成的，每个二进制数转换成相应的十进制数方法如下:
(XnXn-1...X3X2X1)2= X1*2^0+X*2^1+...+Xn*2^(n-1)
一个二进制数要转换为相应的十进制数，就是从最低位起用每一位去乘以对应位的积，也就是说用第n位去乘以2^(n-1)，然后全部加起来
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX_SIZE 100
typedef int ElemType;

typedef struct Stack
{
    ElemType *base;
    ElemType *top;
    ElemType stackSize;
}Stack;

Stack initStack(Stack *s);
void push(Stack *s, ElemType a);
void pop(Stack *s);

int main()
{
    Stack s;
    initStack(&s);
    printf("请输入需要转换的二进制数:\n");

    while(1)
    {
        char ch = getchar();
        if (ch == '\n' && ch == EOF) { // 按下回车键时，清空缓冲区并退出循环
            while ((ch = getchar()) != '\n' && ch != EOF);
            break;
        }
        
        int num = ch - '0'; // 将字符转换为数字
        
        if (num == 0 || num == 1)
        {
            push(&s, num);
            printf("%d入栈\n", num);
        }
        else
        {
            // 输入非0或1的数，退出循环
            break;
        }
    }
    
    ElemType output = 0;
    ElemType n = 0;
    while(s.top != s.base)
    {
        output += *(s.top) * pow(2,n);
        pop(&s);
        n++;
    }

    printf("\n\n转换后的结果是:%d\n",output);


    return 0;
}

Stack initStack(Stack *s)
{
    s->base = (ElemType *)malloc(MAX_SIZE * sizeof(ElemType));
    if(!s->base)
    {
        exit(0);
    }

    s->top = s->base;
    s->stackSize = MAX_SIZE;

    return *s;
}

void push(Stack *s, ElemType a)
{
    s->top++;
    if(s->top - s->base == s->stackSize)
    {
        printf("栈已满!\n");
        return;
    }
    *(s->top) = a;
}

void pop(Stack *s)
{
    if(s->top == s->base)
    {
        printf("栈已空空如也\n");
        return;
    }
    printf("弹出%d\n",*(s->top));
    s->top--;
}
