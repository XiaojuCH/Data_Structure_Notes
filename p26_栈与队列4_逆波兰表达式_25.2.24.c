/*

一般表达式:
a + b * c
5 - (6 + 7) * 8 + 9 / 4

逆波兰表达式:
a b c * -
5 6 7 + 8 * - 9 4 / +

*/


#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

#define STACK_INIT_SIZE 20
#define STACKINCREMENT  10
#define MAXBUFFER       10

typedef double ElemType;
typedef struct Stack
{
    ElemType *base;
    ElemType *top;
    int stackSize;
}Stack;

void InitStack(Stack *s)
{
    s->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
    if( !s->base )
    {
        exit(0);
    }

    s->top = s->base;
    s->stackSize = STACK_INIT_SIZE;
}

void Push(Stack *s, ElemType e)
{
    //栈满，追加空间，鱼油必须懂!
    if( s->top - s->base >= s->stackSize )
    {
        s->base = (ElemType *)realloc(s->base, (s->stackSize + STACKINCREMENT) * sizeof(ElemType));
        if( !s->base )
        {
            exit(0);
        }

        s->top = s->base + s->stackSize;
        s->stackSize = s->stackSize + STACKINCREMENT;
    }

    *(s->top) = e;  //存放数据
    s->top++;
}

void Pop(Stack *s, ElemType *e)
{
    if( s->top == s->base)
    {
        return;
    }

    *e = *--(s->top);   //将栈顶元素弹出并修改栈顶指针
}

int StackLen(Stack s)
{
    return (s.top - s.base);
}

int main()
{
    Stack s;
    InitStack(&s);

    printf("请按逆波兰表达式输入待计算数据,数据与运算符之间用空格隔开,以#作为结束标志:\n");
    
    char ch;
    double d,e;
    char str[MAXBUFFER];//定义缓冲区
    int i = 0;

    scanf("%c",&ch);
    while(ch != '#')
    {
        while(isdigit(ch) || ch == '.') //判断这个字符的ACILL码是否在48-57(即对应0-9)
        {
            str[i++] = ch;
            str[i] = '\0';
            if(i >=  10)
            {
                printf("出错:输入的单个数据过大!\n");
                return -1;
            }

            scanf("%c",&ch); 

            if(ch == ' ')
            {
                d = atof(str);//将字符串转化为浮点数
                Push(&s,d);
                i = 0;
                break;
            }
        }

        switch(ch)
        {
            case '+':   
            {
                Pop(&s,&e);
                Pop(&s,&d);
                Push(&s,d+e);
                break;
            }
            case '-':
            {
                Pop(&s,&e);
                Pop(&s,&d);
                Push(&s,d-e);
                break;
            }
            case '*':
            {
                Pop(&s,&e);
                Pop(&s,&d);
                Push(&s,d*e);
                break;
            }
            case '/':
            {
                Pop(&s,&e);
                Pop(&s,&d);
                if(e != 0)
                {
                    Push(&s,d/e);
                }
                else
                {
                    printf("\n出错:除数为0!\n");
                    return -1;
                }
                break;
            }

        }
        scanf("%c",&ch);
    }
    
    Pop(&s,&d);
    printf("最终的计算结果为:%lf\n",d);

    return 0;
}