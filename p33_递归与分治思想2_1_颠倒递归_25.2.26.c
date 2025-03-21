/*

题目要求:编写一个递归函数，实现将输入的任意长度的字符串反向输出的功能
例如输入字符串Xiaoju则输出字符串ujoaiX。
应用递归的思想有时可以很轻松地实现一些看似不太容易实现的功能，例如这道题
要将一个字符串反向地输出，童鞋们一般采用的方法是将该字符串存放到一个数组中，然后将数组元素反向的输出即可
这道题要求输入是任意长度，所以不用递归的话，实现起来会比较麻烦(当然你可以用之前我们讲过的动态申请内存那招)

*/

#include<stdio.h>

void fun();

int main()
{
        printf("请输入任意字符串,并以#作为结尾:\n");
        fun();
        printf("\n");

    return 0;
}

void fun()
{
    char ch;
    scanf("%c",&ch);
    if(ch != '#') fun(ch);
    if(ch != '#') printf("%c",ch); //这步可以在输出时去掉 #
}