/*
    汉诺塔递归
*/

#include<stdio.h>

void move(int n, char x, char y, char z);

int main()
{
    int n;
    printf("请输入汉诺塔的层数:\n");
    scanf("%d",&n);
    move(n,'X','Y','Z');
    printf("移动步骤如下:\n");

    return 0;
}

void move(int n, char x, char y, char z)
{
    if(n == 1)
    {
        printf("%c-->%c\n",x,z);
    }
    else
    {
        move(n-1,x,z,y);        //将 n-1 个盘子从 x 借助 z 移到 y 上
        printf("%c-->%c\n",x,z);//将第 n 个盘子从 x 移到 z 上
        move(n-1, y, x, z);     //将 n-1 个盘子从 y 借助 x 移到 z 上
    }
}
