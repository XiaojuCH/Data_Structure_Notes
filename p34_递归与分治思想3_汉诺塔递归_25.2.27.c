/*
    ��ŵ���ݹ�
*/

#include<stdio.h>

void move(int n, char x, char y, char z);

int main()
{
    int n;
    printf("�����뺺ŵ���Ĳ���:\n");
    scanf("%d",&n);
    move(n,'X','Y','Z');
    printf("�ƶ���������:\n");

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
        move(n-1,x,z,y);        //�� n-1 �����Ӵ� x ���� z �Ƶ� y ��
        printf("%c-->%c\n",x,z);//���� n �����Ӵ� x �Ƶ� z ��
        move(n-1, y, x, z);     //�� n-1 �����Ӵ� y ���� x �Ƶ� z ��
    }
}
